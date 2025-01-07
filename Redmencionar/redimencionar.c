#include <stdio.h>
#include <stdlib.h>

struct Pixel typedef PixelDaImagem;
struct Foto typedef DadosDaFoto;

// Função para liberar a memória alocada para uma imagem
void liberarImagem(DadosDaFoto* imagem);

// Função para carregar uma imagem a partir de um arquivo
DadosDaFoto* carregarImagem(const char* nomeDaFoto);

// Função para salvar uma imagem em um arquivo
void salvarImagem(const char* nomeArquivo, DadosDaFoto* img);

// Função para interpolar o valor de um pixel com base em seus vizinhos
PixelDaImagem interpolarPixel1Vizinhanca(DadosDaFoto* entrada, float x, float y, int escolhaVizinho);

PixelDaImagem interpolarPixel4Vizinhanca(DadosDaFoto* entrada, float x, float y);

DadosDaFoto* interpolarImagem4Vizinhanca(DadosDaFoto* entrada, float width, float height);

DadosDaFoto* interpolarImagem1Vizinhanca(DadosDaFoto* entrada, float width, float height, int escolhaVizinho);


int main(int argc, char *argv[]) {
    
    float largura, altura;
    int vizinhanca, escolhaVizinho1;

    printf("Digite o valor da largura (M): ");
    scanf("%f", &largura);

    printf("Digite o valor da altura (N) ");
    scanf("%f", &altura);

   //Carrega a imagem com o nome que foi passado como argumento
    DadosDaFoto* imagemOriginal = carregarImagem(argv[1]);
    if (!imagemOriginal) {
        return -1;
    }

    //Cria as variavéis nescessárias para fazer a interpolação
    DadosDaFoto* imagemInterpolada;
    DadosDaFoto* imagemInterpolada2;
    

    printf("Escolha o vizinho para interpolacao de 1-vizinhanca:\n");
    printf("1 - Vizinho direito (padrao)\n");
    printf("2 - Vizinho inferior\n");
    printf("3 - Vizinho diagonal inferior direito\n");
    scanf("%d", &escolhaVizinho1);

    if (escolhaVizinho1 < 1 || escolhaVizinho1 > 3) {
        fprintf(stderr, "Opção de vizinho inválida.\nSaindo...\n");
        liberarImagem(imagemOriginal);
        return -1;
    }

    //Faz as duas interpolações
    imagemInterpolada = interpolarImagem1Vizinhanca(imagemOriginal, largura, altura, escolhaVizinho1);
    imagemInterpolada2 = interpolarImagem4Vizinhanca(imagemOriginal, largura, altura);


    if (!imagemInterpolada||!imagemInterpolada2) {
        liberarImagem(imagemOriginal);
        return -1;
    }

    //Salvando as duas imagens já interpoladas
    salvarImagem("output_1vizinhanca.ppm", imagemInterpolada);
    salvarImagem("output_4vizinhanca.ppm", imagemInterpolada2);

    //Liberando as duas imagens 
    liberarImagem(imagemOriginal);
    liberarImagem(imagemInterpolada);
    liberarImagem(imagemInterpolada2);

    return 0;
}
// Define uma estrutura para representar um pixel com componentes vermelho, verde e azul
struct Pixel{
    unsigned char vermelho, verde, azul;
};

// Define uma estrutura para representar uma foto com largura, altura e dados de pixels
struct Foto{
    int largura, altura; // Dimensões da imagem
    PixelDaImagem* dados; // Ponteiro para um array de pixels representando os dados da imagem
};

// Função para liberar a memória alocada para uma imagem
void liberarImagem(DadosDaFoto* imagem) {
    free(imagem->dados); // Libera a memória alocada para os dados dos pixels
    free(imagem);// Libera a memória alocada para a própria estrutura da imagem
}

// Função para carregar uma imagem a partir de um arquivo
DadosDaFoto* carregarImagem(const char* nomeDaFoto) {
    FILE* arquivo = fopen(nomeDaFoto, "r"); // Abre o arquivo da imagem para leitura
    if (!arquivo) {
        fprintf(stderr, "Nao consegui abrir a imagem com esse nome\n"); // Se não conseguir abrir o arquivo, imprime um erro
        return NULL; // Retorna NULL para indicar falha
    }
    // Aloca memória para os dados da imagem
    DadosDaFoto* img = (DadosDaFoto*)malloc(sizeof(DadosDaFoto));
    if (!img) {
        fprintf(stderr, "Erro de alocação\n");
        fclose(arquivo);
        return NULL;
    }

    //Se o formato da imagem não for P3, não abre a imagem
    char formato[3];
    fscanf(arquivo, "%s %d %d %*d", formato, &(img->largura), &(img->altura)); // Lê o formato e as dimensões da imagem do arquivo

    if (formato[0] != 'P' || formato[1] != '3') {
        fprintf(stderr, "Formato de imagem não suportado, aceito apenas o formato P3\n");
        free(img);// Libera a memória alocada para os dados da imagem
        fclose(arquivo);// Fecha o arquivo
        return NULL;// Retorna NULL para indicar falha
    }
    // Aloca memória para os pixels da imagem
    img->dados = (PixelDaImagem*)malloc(img->largura * img->altura * sizeof(PixelDaImagem));
    if (!img->dados) {
        fprintf(stderr, "Erro de alocação de memória do pixel\n"); // Se a alocação falhar, imprime um erro
        free(img);// Libera a memória alocada para os dados da imagem
        fclose(arquivo);// Fecha o arquivo
        return NULL;// Retorna NULL para indicar falha
    }
    
    for (int i = 0; i < img->largura * img->altura; i++) {
        fscanf(arquivo, "%hhu %hhu %hhu", &(img->dados[i].vermelho), &(img->dados[i].verde), &(img->dados[i].azul));// Lê os dados dos pixels do arquivo
    }

    fclose(arquivo);// Fecha o arquivo após terminar de ler os dados
    return img;// Retorna um ponteiro para os dados da imagem carregada
}

// Função para salvar uma imagem em um arquivo
void salvarImagem(const char* nomeArquivo, DadosDaFoto* img) {
    FILE* arquivo = fopen(nomeArquivo, "w");// Abre ou cria um arquivo para escrita
    if (!arquivo) { // Se não conseguir abrir o arquivo, imprime um erro
        fprintf(stderr, "Erro ao criar arquivo\n");
        return;
    }

    fprintf(arquivo, "P3\n"); // Escreve o cabeçalho do formato P3 no arquivo
    fprintf(arquivo, "%d %d\n255\n", img->largura, img->altura); // Escreve as dimensões da imagem e o valor máximo para cada cor

    for (int i = 0; i < img->largura * img->altura; i++) {
        fprintf(arquivo, "%d %d %d\n", img->dados[i].vermelho, img->dados[i].verde, img->dados[i].azul);// Escreve os dados dos pixels no arquivo
    }

    fclose(arquivo); // Fecha o arquivo após terminar de escrever os dados
}

// Função para interpolar o valor de um pixel com base em seus vizinhos
PixelDaImagem interpolarPixel1Vizinhanca(DadosDaFoto* entrada, float x, float y, int escolhaVizinho) {
    // Converte as coordenadas de ponto flutuante para valores inteiros
    int x0 = (int)x;
    int y0 = (int)y;

    int x1, y1;

    // Determina qual pixel vizinho usar com base na escolha fornecida
    if (escolhaVizinho == 1) {  // Vizinho à direita
        x1 = (x0 + 1) % entrada->largura;
        y1 = y0;
    } else if (escolhaVizinho == 2) {  // Vizinho de baixo
        x1 = x0;
        y1 = (y0 + 1) % entrada->altura;
    } else if (escolhaVizinho == 3) {  // Vizinho diagonal inferior direito
        x1 = (x0 + 1) % entrada->largura;
        y1 = (y0 + 1) % entrada->altura;
    }

    // Calcula a fração decimal das coordenadas para interpolação
    float fracX = x - x0;
    float fracY = y - y0;

    // Interpolação bilinear
    PixelDaImagem pixelInterpolado;
    pixelInterpolado.vermelho = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].vermelho +
                                fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].vermelho +
                                (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].vermelho +
                                fracX * fracY * entrada->dados[y1 * entrada->largura + x1].vermelho;

    pixelInterpolado.verde = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].verde +
                             fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].verde +
                             (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].verde +
                             fracX * fracY * entrada->dados[y1 * entrada->largura + x1].verde;

    pixelInterpolado.azul = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].azul +
                            fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].azul +
                            (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].azul +
                            fracX * fracY * entrada->dados[y1 * entrada->largura + x1].azul;

    return pixelInterpolado; // Retorna o pixel interpolado
}

PixelDaImagem interpolarPixel4Vizinhanca(DadosDaFoto* entrada, float x, float y) {
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = (x0 + 1) % entrada->largura;
    int y1 = (y0 + 1) % entrada->altura;

    float fracX = x - x0;
    float fracY = y - y0;
    
    /*
      SL----SR
      |      |
      |  P   |  <- P é o novo pixel que queremos interpolar.
      |      |
      IL----IR

    Valor de vermelho de P = (1 - fracX) * (1 - fracY) * R1  // Peso do Superior esquerdo
                       + fracX * (1 - fracY) * R2            // Peso do Superior direito
                       + (1 - fracX) * fracY * R3            // Peso do Inferior esquerdo
                       + fracX * fracY * R4                  // Peso do Inferior direito
            */

    // Interpolação bilinear
    PixelDaImagem pixelInterpolado;
    pixelInterpolado.vermelho = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].vermelho +
                                fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].vermelho +
                                (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].vermelho +
                                fracX * fracY * entrada->dados[y1 * entrada->largura + x1].vermelho;

    pixelInterpolado.verde = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].verde +
                             fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].verde +
                             (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].verde +
                             fracX * fracY * entrada->dados[y1 * entrada->largura + x1].verde;

    pixelInterpolado.azul = (1 - fracX) * (1 - fracY) * entrada->dados[y0 * entrada->largura + x0].azul +
                            fracX * (1 - fracY) * entrada->dados[y0 * entrada->largura + x1].azul +
                            (1 - fracX) * fracY * entrada->dados[y1 * entrada->largura + x0].azul +
                            fracX * fracY * entrada->dados[y1 * entrada->largura + x1].azul;

    return pixelInterpolado;
}

DadosDaFoto* interpolarImagem4Vizinhanca(DadosDaFoto* entrada, float width, float height) {
    int novaLargura = (int)(entrada->largura * width);
    int novaAltura = (int)(entrada->altura * height);

    DadosDaFoto* saida = (DadosDaFoto*)malloc(sizeof(DadosDaFoto));
    if (!saida) {
        fprintf(stderr, "Erro de alocação de memória para a imagem interpolada\n");
        return NULL;
    }

    saida->largura = novaLargura;
    saida->altura = novaAltura;
    saida->dados = (PixelDaImagem*)malloc(novaLargura * novaAltura * sizeof(PixelDaImagem));

    if (!saida->dados) {
        fprintf(stderr, "Erro de alocação de memória para os pixels da imagem interpolada\n");
        free(saida);
        return NULL;
    }

    for (int y = 0; y < novaAltura; y++) {
        for (int x = 0; x < novaLargura; x++) {
            float origemX = (float)x / novaLargura * entrada->largura;
            float origemY = (float)y / novaAltura * entrada->altura;

            // 4-vizinhança (média aritmética simples)
            saida->dados[y * novaLargura + x] = interpolarPixel4Vizinhanca(entrada, origemX, origemY);
        }
    }

    return saida;
}

DadosDaFoto* interpolarImagem1Vizinhanca(DadosDaFoto* entrada, float width, float height, int escolhaVizinho) {
    
    DadosDaFoto* saida;
    
    int novaLargura = (int)(entrada->largura * width);
    int novaAltura = (int)(entrada->altura * height);

    if (!(saida = (DadosDaFoto*)malloc(sizeof(DadosDaFoto)))) {
        fprintf(stderr, "Erro de alocação de memória para a imagem a ser interpolada\n");
        return NULL;
    }

    saida->largura = novaLargura;
    saida->altura = novaAltura;
    
    saida->dados = (PixelDaImagem*)malloc(novaLargura * novaAltura * sizeof(PixelDaImagem));

    if (!saida->dados) {
        fprintf(stderr, "Erro de alocação de memória para os pixels da imagem interpolada\n");
        free(saida);
        return NULL;
    }

    for (int y = 0; y < novaAltura; y++) {
        for (int x = 0; x < novaLargura; x++) {
            float origemX = (float)x / novaLargura * entrada->largura;
            float origemY = (float)y / novaAltura * entrada->altura;

            // 1-vizinhança com escolha de vizinho
            saida->dados[y * novaLargura + x] = interpolarPixel1Vizinhanca(entrada, origemX, origemY, escolhaVizinho);
        }
    }

    return saida;
}