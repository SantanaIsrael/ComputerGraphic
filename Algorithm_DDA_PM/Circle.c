#include <GL/glut.h>
#include <stdio.h>

int raioDoCirculo = 0; // Variável global para armazenar o raio do círculo

// Função para plotar pontos nos quatro quadrantes do círculo
void plotarPontos(int coordX, int coordY);
// Algoritmo do Ponto Médio para desenhar um círculo
void algoritmoPontoMedio();
// Função para desenhar os eixos x e y
void desenharEixos();
// Função de callback para renderizar a cena
void callbackExibicao();
// Função de inicialização do OpenGL
void iniciarOpenGL();

// Função principal
int main(int argc, char **argv)
{
    while (1) // Loop infinito até a entrada válida
    {
        printf("Digite o raio do círculo: "); // Solicita ao usuário o raio do círculo
        scanf("%d", &raioDoCirculo); // Lê o valor do raio

        // Verifica se o raio é válido
        if (raioDoCirculo >= 1 && raioDoCirculo <= 10)
        {
            break; // Sai do loop se o raio for válido
        }
        else
        {
            printf("Raio inválido. Deve estar entre 1 e 10.\n"); // Mensagem de erro para raio inválido
        }
    }

    glutInit(&argc, argv); // Inicializa a GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de exibição
    glutInitWindowSize(800, 800); // Define o tamanho da janela
    glutInitWindowPosition(0, 0); // Define a posição inicial da janela
    glutCreateWindow("PONTO MEDIO"); // Cria a janela com o título especificado
    iniciarOpenGL(); // Chama a função de inicialização
    glutDisplayFunc(callbackExibicao); // Registra a função de callback de exibição
    glutMainLoop(); // Entra no loop principal da GLUT
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

void plotarPontos(int coordX, int coordY)
{   glColor3f(0.0, 0.0, 0.0); // Define a cor dos pontos como preto
    glBegin(GL_POINTS); // Inicia a definição de pontos
    glVertex2i(coordX, coordY);   // Plota ponto no primeiro quadrante
    glVertex2i(-coordX, coordY);  // Plota ponto no segundo quadrante
    glVertex2i(coordX, -coordY);  // Plota ponto no terceiro quadrante
    glVertex2i(-coordX, -coordY); // Plota ponto no quarto quadrante
    // Plota pontos rotacionados em 45 graus
    glVertex2i(coordY, coordX);   // Plota ponto rotacionado no primeiro quadrante
    glVertex2i(-coordY, coordX);  // Plota ponto rotacionado no segundo quadrante
    glVertex2i(coordY, -coordX);  // Plota ponto rotacionado no terceiro quadrante
    glVertex2i(-coordY, -coordX); // Plota ponto rotacionado no quarto quadrante
    glEnd(); // Finaliza a definição de pontos
}


void algoritmoPontoMedio()
{
    int coordX = 0;        // Coordenada x inicial
    int coordY = raioDoCirculo;     // Coordenada y inicial (igual ao raio)
    int parametroDecisao = 1 - raioDoCirculo; // Parâmetro de decisão inicial

    plotarPontos(coordX, coordY); // Plota os pontos iniciais

    while (coordX < coordY) // Enquanto x for menor que y
    {
        if (parametroDecisao < 0) // Se o ponto médio está dentro do círculo
        {
            parametroDecisao += 2 * coordX + 3; // Atualiza o parâmetro de decisão
        }
        else // Se o ponto médio está fora ou no círculo
        {
            parametroDecisao += 2 * (coordX - coordY) + 5; // Atualiza o parâmetro de decisão
            coordY--; // Decrementa y
        }
        coordX++; // Incrementa x
        plotarPontos(coordX, coordY); // Plota os novos pontos
    }
}


void desenharEixos()
{   glColor3f(255.0, 0.0, 0.0); // Define a cor dos eixos como vermelho
    glBegin(GL_LINES); // Inicia a definição de linhas
    // Eixo x
    glVertex2i(-10, 0); // Ponto inicial do eixo x
    glVertex2i(10, 0);  // Ponto final do eixo x
    // Eixo y
    glVertex2i(0, -10); // Ponto inicial do eixo y
    glVertex2i(0, 10);  // Ponto final do eixo y
    glEnd(); // Finaliza a definição de linhas
}


void callbackExibicao()
{
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor
    desenharEixos(); // Desenha os eixos
    algoritmoPontoMedio(); // Chama a função para desenhar o círculo
    glFlush(); // Garante que todos os comandos de renderização sejam executados
}


void iniciarOpenGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo como branco
    glColor3f(0.0, 0.0, 0.0); // Define a cor dos pontos como preto
    glPointSize(4.0); // Define o tamanho dos pontos
    gluOrtho2D(-10, 10, -10, 10); // Define a projeção ortográfica
}
