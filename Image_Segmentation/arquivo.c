#include <stdio.h>
#include <stdlib.h>

FILE *fpin1, *fpin2, *fpout_movimento, *fpout_seg;
int **foto1_Red, **foto1_Green, **foto1_Blue, **foto2_Red, **foto_2Green, **foto2_Blue,
    **subtracao_movRed, **subtracao_movGreen, **subtracao_movBlue, **foto_segmentadaRed, **foto_segmentadaGreen, **foto_segmentadaBlue;
int nLinhas, nColunas, quant_nivel_cinza;
float percentual_erro;

void abrir_arquivos(int argc, char *argv[]);
void ler_cabecalho(FILE *, int *, int *, int *);
void ler_imagem(FILE *, int **, int **, int **, int, int);
void gravar_cabecalho(FILE *, int, int, int);
void gravar_imagem(FILE *, int **, int **, int **, int, int);
void fechar_arquivos(void);

void subtrair_imagens(int **imagem1R, int **imagem1G, int **imagem1B, int **imagem2R, int **imagem2G, int **imagem2B, int **resultadoR, int **resultadoG, int **resultadoB, int ncol, int nlin);
void segmentar_imagem(int **imagem1R, int **imagem1G, int **imagem1B, int **imagem2R, int **imagem2G, int **imagem2B, int **segmentadaR, int **segmentadaG, int **segmentadaB, int ncol, int nlin);
int **aloca_matriz(int, int);

void subtrair_imagens(int **, int **, int **, int **, int **, int **, int **, int **, int **, int, int);
void segmentar_imagem(int **, int **, int **, int **, int **, int **, int **, int **, int **, int, int);
void segmentar_imagemColor(int **, int **, int **, int **, int **, int **, int **, int **, int **, int, int);
void liberar_memoria();

int main(int argc, char *argv[])
{

    abrir_arquivos(argc, argv);

    printf("Digite o percentual de erro: ");
    scanf("%f", &percentual_erro);

    ler_cabecalho(fpin1, &nLinhas, &nColunas, &quant_nivel_cinza);

    foto1_Red = aloca_matriz(nLinhas, nColunas);
    foto1_Green = aloca_matriz(nLinhas, nColunas);
    foto1_Blue = aloca_matriz(nLinhas, nColunas);

    ler_imagem(fpin1, foto1_Red, foto1_Green, foto1_Blue, nLinhas, nColunas);

    ler_cabecalho(fpin2, &nLinhas, &nColunas, &quant_nivel_cinza);

    foto2_Red = aloca_matriz(nLinhas, nColunas);
    foto_2Green = aloca_matriz(nLinhas, nColunas);
    foto2_Blue = aloca_matriz(nLinhas, nColunas);

    ler_imagem(fpin2, foto2_Red, foto_2Green, foto2_Blue, nLinhas, nColunas);

    subtracao_movBlue = aloca_matriz(nLinhas, nColunas);
    subtracao_movGreen = aloca_matriz(nLinhas, nColunas);
    subtracao_movRed = aloca_matriz(nLinhas, nColunas);

    subtrair_imagens(foto1_Red, foto1_Green, foto1_Blue, foto2_Red, foto_2Green, foto2_Blue, subtracao_movRed, subtracao_movGreen, subtracao_movBlue, nLinhas, nColunas);

    gravar_cabecalho(fpout_movimento, nLinhas, nColunas, quant_nivel_cinza);
    gravar_imagem(fpout_movimento, subtracao_movRed, subtracao_movGreen, subtracao_movBlue, nLinhas, nColunas);

    foto_segmentadaRed = aloca_matriz(nLinhas, nColunas);
    foto_segmentadaGreen = aloca_matriz(nLinhas, nColunas);
    foto_segmentadaBlue = aloca_matriz(nLinhas, nColunas);

    // SEGMENTAR CINZA(MONOCROMATICO) A QUARTA IMAGEM SAI COM TONS DE CINZAS
    //segmentar_imagem(foto1_Red, foto1_Green, foto1_Blue, foto2_Red, foto_2Green, foto2_Blue, foto_segmentadaRed, foto_segmentadaGreen, foto_segmentadaBlue, nLinhas, nColunas);

    // //SEGMENTAR COLORIDO
    segmentar_imagemColor(foto1_Red, foto1_Green, foto1_Blue, foto2_Red, foto_2Green, foto2_Blue, foto_segmentadaRed, foto_segmentadaGreen, foto_segmentadaBlue, nLinhas, nColunas);

    gravar_cabecalho(fpout_seg, nLinhas, nColunas, quant_nivel_cinza);
    gravar_imagem(fpout_seg, foto_segmentadaRed, foto_segmentadaGreen, foto_segmentadaBlue, nLinhas, nColunas);

    fechar_arquivos();
    liberar_memoria();

    return 0;
}

int **aloca_matriz(int nLinha, int nColuna)
{

    int **aloc_auxiliar;

    aloc_auxiliar = (int **)malloc(nColunas * sizeof(int *));
    for (int i = 0; i < nColunas; i++)
        aloc_auxiliar[i] = (int *)malloc(nLinhas * sizeof(int));

    return aloc_auxiliar;
}

// abre os arquivos de entrada e saída
void abrir_arquivos(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Modo correto de uso: <prog> <foto1> <foto2> <foto3.ppm> <foto4.ppm>\n");
        exit(1);
    }
    if ((fpin1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Não foi possível abrir o arquivo de imagem %s\n", argv[1]);
        exit(1);
    }
    if ((fpin2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Não foi possível abrir o arquivo de imagem %s\n", argv[2]);
        exit(1);
    }
    if ((fpout_movimento = fopen(argv[3], "w")) == NULL)
    {
        printf("Não foi possível abrir o arquivo de saída para a imagem de movimento\n");
        exit(1);
    }
    if ((fpout_seg = fopen(argv[4], "w")) == NULL)
    {
        printf("Não foi possível abrir o arquivo de saída para a imagem segmentada\n");
        exit(1);
    }
}

// ler o cabeçalho com as informações de numero de linhas e colunas e nivel máximo das cores
void ler_cabecalho(FILE *fpin, int *ncol, int *nlin, int *quant_nivel)
{

    char controle[4];

    fscanf(fpin, "%s\n", controle);
    fscanf(fpin, "%d %d\n", ncol, nlin);
    fscanf(fpin, "%d\n", quant_nivel);
}

// ler a imagem e adiciona em três matrizez
void ler_imagem(FILE *fpin, int **imagemR, int **imagemG, int **imagemB, int ncol, int nlin)
{

    int lin, col;
    for (lin = 0; lin < nlin; lin++)
    {
        for (col = 0; col < ncol; col++)
        {
            fscanf(fpin, "%d ", &imagemR[lin][col]);
            fscanf(fpin, "%d ", &imagemG[lin][col]);
            fscanf(fpin, "%d ", &imagemB[lin][col]);
        }
    }
}

// grava o cabeçalho com as informações passada por parametro no arquivo
void gravar_cabecalho(FILE *fpout, int ncol, int nlin, int quant_nivel)
{

    fprintf(fpout, "P3\n");
    fprintf(fpout, "%d %d\n", ncol, nlin);
    fprintf(fpout, "%d\n", quant_nivel);
}

// junta as três matrizes RGB passa por parametro em um arquivo
void gravar_imagem(FILE *fpout, int **imagemR, int **imagemG, int **imagemB, int ncol, int nlin)
{

    int lin, col;

    for (lin = 0; lin < nlin; lin++)
    {
        for (col = 0; col < ncol; col++)
        {
            fprintf(fpout, "%d ", imagemR[lin][col]);
            fprintf(fpout, "%d ", imagemG[lin][col]);
            fprintf(fpout, "%d ", imagemB[lin][col]);
        }
        fprintf(fpout, "\n");
    }
}

// fecha todos os arquivos abertos
void fechar_arquivos(void)
{
    fclose(fpin1);
    fclose(fpin2);
    fclose(fpout_movimento);
    fclose(fpout_seg);
}

// subtrai as matrizes RGBs das duas imagens
void subtrair_imagens(int **imagem1R, int **imagem1G, int **imagem1B, int **imagem2R, int **imagem2G, int **imagem2B, int **resultadoR, int **resultadoG, int **resultadoB, int ncol, int nlin)
{

    for (int lin = 0; lin < nlin; lin++)
    {
        for (int col = 0; col < ncol; col++)
        {

            // Subtrai os canis RGBs soma o resultante de cada um
            int diferencaTotal = abs(imagem1R[lin][col] - imagem2R[lin][col]) +
                                 abs(imagem1G[lin][col] - imagem2G[lin][col]) +
                                 abs(imagem1B[lin][col] - imagem2B[lin][col]);

            // se teve movimento, adiciona o máximo daquela cor, se não, o minimo
            if (diferencaTotal > percentual_erro)
            {
                resultadoR[lin][col] = 225;
                resultadoG[lin][col] = 225;
                resultadoB[lin][col] = 225;
            }
            else
            {
                resultadoR[lin][col] = 0;
                resultadoG[lin][col] = 0;
                resultadoB[lin][col] = 0;
            }
        }
    }
}

// Compara as duas imagens //monocormatico
void segmentar_imagem(int **imagem1R, int **imagem1G, int **imagem1B, int **imagem2R, int **imagem2G, int **imagem2B, int **segmentadaR, int **segmentadaG, int **segmentadaB, int ncol, int nlin)
{

    int lin, col, media_luminosidade1, media_luminosidade2;

    for (lin = 0; lin < nlin; lin++)
    {
        for (col = 0; col < ncol; col++)
        {

            // Calcula a diferença total dos canais RGB
            int diferencaTotal = abs(imagem1R[lin][col] - imagem2R[lin][col]) +
                                 abs(imagem1G[lin][col] - imagem2G[lin][col]) +
                                 abs(imagem1B[lin][col] - imagem2B[lin][col]);

           if(diferencaTotal > percentual_erro){

                //calcula a media entre as três matrizes
                media_luminosidade1 = (imagem1R[lin][col] + imagem1G[lin][col] + imagem1B[lin][col])/3;

                //adiciona a subtração das medias naquele pixel
                segmentadaR[lin][col] = media_luminosidade1;
                segmentadaG[lin][col] = media_luminosidade1;
                segmentadaB[lin][col] = media_luminosidade1;

            }else {
                //se não houve mudança adiciona o preto (o minimo daquela cor)
                segmentadaR[lin][col] = 0;
                segmentadaG[lin][col] = 0;
                segmentadaB[lin][col] = 0;
            }
        }
    }
}
// Compara as duas imagens
void segmentar_imagemColor(int **imagem1R, int **imagem1G, int **imagem1B, int **imagem2R, int **imagem2G, int **imagem2B, int **segmentadaR, int **segmentadaG, int **segmentadaB, int ncol, int nlin)
{

    int lin, col, media_luminosidade1, media_luminosidade2;

    for (lin = 0; lin < nlin; lin++)
    {
        for (col = 0; col < ncol; col++)
        {

            // Calcula a diferença total dos canais RGB
            int diferencaTotal = abs(imagem1R[lin][col] - imagem2R[lin][col]) +
                                 abs(imagem1G[lin][col] - imagem2G[lin][col]) +
                                 abs(imagem1B[lin][col] - imagem2B[lin][col]);

            // Verifica se há movimento
            if (diferencaTotal > percentual_erro)
            {
                // Substitui por cor original da imagem 1
                segmentadaR[lin][col] = imagem1R[lin][col];
                segmentadaG[lin][col] = imagem1G[lin][col];
                segmentadaB[lin][col] = imagem1B[lin][col];
            }
            else
            {
                // Se não há movimento, mantém o valor 0
                segmentadaR[lin][col] = 0;
                segmentadaG[lin][col] = 0;
                segmentadaB[lin][col] = 0;
            }
        }
    }
}

void liberar_memoria()
{

    // Liberar a memória alocada para as matrizes
    for (int i = 0; i < nColunas; i++)
    {
        free(foto1_Red[i]);
        free(foto1_Green[i]);
        free(foto1_Blue[i]);
        free(foto2_Red[i]);
        free(foto_2Green[i]);
        free(foto2_Blue[i]);
        free(subtracao_movRed[i]);
        free(subtracao_movGreen[i]);
        free(subtracao_movBlue[i]);
        free(foto_segmentadaRed[i]);
        free(foto_segmentadaGreen[i]);
        free(foto_segmentadaBlue[i]);
    }
    free(foto1_Red);
    free(foto1_Green);
    free(foto1_Blue);
    free(foto2_Red);
    free(foto_2Green);
    free(foto2_Blue);
    free(subtracao_movRed);
    free(subtracao_movGreen);
    free(subtracao_movBlue);
    free(foto_segmentadaRed);
    free(foto_segmentadaGreen);
    free(foto_segmentadaBlue);
}