#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

int tipoOlho = 1, tipoCabelo = 1, tipoNariz = 1, tipoBoca = 1, tipoBrinco = 1, tipoSapato = 1;

int R, G, B;
void DesenhaTexto(char *);
void olho();
void nariz();
void boca();
void sapato();
void cabelo();
void brincodaorelha();
void desenha_orelha();
void corpo();
void keyboard(unsigned char key, int x, int y);


void render()
{
    // limpar a tela
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
     DesenhaTexto("Cabelo = b ao m\nSapato = z ao x\nOlho = 1 ao 7\nNariz = Q ao e\nBoca = a ao f\n");
    sapato();
    cabelo();
    desenha_orelha();
    corpo();
    nariz();
    brincodaorelha();
    boca(); 
    olho();

    glutSwapBuffers();
    // // liberação de memoria
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Estabelece contato com sistema de janelas
    // Configuração exibição do modo grafico (janela)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // pode ser GLUT_RGBA caso precise
    glutInitWindowSize(900, 900);                // Posição inicial do canto superior esquerdo da janela a ser criada
    glutInitWindowPosition(0, 0);
    glutCreateWindow("MiniMy"); // nome que vai ser exibida na janela
    glutDisplayFunc(render);    // aqui adiciona a função de renderizar

    // inicializa o ambiente com as configurações do init que foi definida
    init();
    glutKeyboardFunc(keyboard);
    // loop de tratamento de eventos
    glutMainLoop();
    return 0;
}

// tranforma minha variavel angulo em radianos
float grausParaRadianos(float angulo)
{
    return (angulo * 2 * 3.14159265358979323846) / 360.0;
}

void semi_CirculoPalpebra(float raio, float x0, float y0, int def, float graus, int origem)
{
    /* raio: define o tamanho do circulo.
        x0, y0: define a posição onde o circulo vai está.
        def: a quantidade de pontos, quanto maior mais perfeito o circulo
    */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glBegin(GL_POLYGON);
    glColor3ub(99, 48, 18); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(179, 118, 64); // define a cor

        angulo += passo;
    }
    glEnd();
}

void Circulo(float raio, float x0, float y0, int def, float graus)
{
    /* raio: define o tamanho do circulo.
        x0, y0: define a posição onde o circulo vai está.
        def: a quantidade de pontos, quanto maior mais perfeito o circulo
    */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(0);

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        angulo += passo;
    }
    glEnd();
}

void CirculoCor(float raio, float x0, float y0, int def, float graus, int R, int G, int B, int origem)
{
    /* raio: define o tamanho do circulo.
        x0, y0: define a posição onde o circulo vai está.
        def: a quantidade de pontos, quanto maior mais perfeito o circulo
    */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glBegin(GL_POLYGON);
    glColor3ub(R, G, B); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(255,100,197); // define a cor
        angulo += passo;
    }
    glEnd();
}

void semi_Circulo(float raio, float x0, float y0, int def, float graus, int origem)
{
    /* raio: define o tamanho do circulo.
    x0, y0: define a posição onde o circulo vai está.
    def: a quantidade de pontos, quanto maior mais perfeito o circulo
*/
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glBegin(GL_POLYGON);
    glColor3ub(191, 100, 34); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(160, 100, 34); // define a cor

        angulo += passo;
    }
    glEnd();
}

void semi_CirculoCimaNariz(float raio, float x0, float y0, int def, float graus, int origem)
{
    /* raio: define o tamanho do circulo.
    x0, y0: define a posição onde o circulo vai está.
    def: a quantidade de pontos, quanto maior mais perfeito o circulo
*/
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glColor3ub(143, 69, 26); // define a cor
    glBegin(GL_POLYGON);
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(191, 100, 34); // define a cor

        angulo += passo;
    }
    glEnd();
}

void nariz_vertical(){

    float passo = grausParaRadianos(180 / 30);
    float x, y;
    float angulo = grausParaRadianos(0);

    glColor3ub(143, 69, 26); // define a cor
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++)
    {
        x = 0.080 * cos(angulo) + 0;
        y = 0.080 * sin(angulo) + -0.07;
        glVertex2f(x, y);
        glColor3ub(191, 100, 34); // define a cor

        angulo += passo;
    }
    glEnd();
    
    glColor3ub(143, 69, 26); // define a cor
    glBegin(GL_POLYGON);

        glVertex2f(0.079,-0.23);
        glVertex2f(0.079,-0.06);
        glColor3ub(191, 100, 34); // define a cor
        glVertex2f(-0.079,-0.06);
        glVertex2f(-0.079,-0.23);

    glEnd();

    passo = grausParaRadianos(-200 / 30);
    angulo = grausParaRadianos(0);

    glColor3ub(143, 69, 26); // define a cor
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++)
    {
        x = 0.080 * cos(angulo) + 0;
        y = 0.080 * sin(angulo) + -0.22;
        glVertex2f(x, y);
        glColor3ub(191, 100, 34); // define a cor

        angulo += passo;
    }
    glEnd();
}

void nariz_porco(){
    CirculoCor(0.15, 0, -0.07, 30, 360, 255, 150, 197,0);
    CirculoCor(0.05, -0.055, -0.07, 30, 360, 255, 5, 197,0);
    CirculoCor(0.05, 0.055, -0.07, 30, 360, 255, 5, 197,0);
}

void desenha_nariz()
{

    semi_Circulo(0.080, -0.06, -0.2, 30, 187, 180);     // semi - circulo esquerdo
    semi_Circulo(0.080, 0.06, -0.2, 30, -187, 5);       // semi - circulo direito
    semi_CirculoCimaNariz(0.080, 0, -0.07, 30, 180, 0); // semi - circulo de cima
    glBegin(GL_POLYGON);

    glVertex2f(-0.14, -0.2);  // M
    glColor3ub(191, 100, 34); // define a cor
    glVertex2f(0.14, -0.2);   // N

    glColor3ub(143, 69, 26);

    glVertex2f(0.077, -0.05);  // P
    glColor3ub(191, 100, 34);  // define a cor
    glVertex2f(-0.077, -0.05); // O
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.079, -0.195);
    glColor3ub(160, 100, 34); // define a cor
    glVertex2f(0.079, -0.195);

    glColor3ub(143, 69, 26);

    glVertex2f(0.079, -0.064);
    glColor3ub(191, 100, 34); // define a cor
    glVertex2f(-0.079, -0.064);

    glEnd();
    semi_Circulo(0.080, 0, -0.180, 60, 180, 180); // circulo do meio
}

void nariz_de_palhaco(float raio, float x0, float y0, int def, float graus, int origem){

    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(30,30,30); // define a cor
        angulo += passo;
    }
    glEnd();
}
void semi_Circulo_Olho(float raio, float x0, float y0, int def, float graus, int origem)
{
    /* raio: define o tamanho do circulo.
        x0, y0: define a posição onde o circulo vai está.
        def: a quantidade de pontos, quanto maior mais perfeito o circulo
    */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(133, 133, 133); // define a cor

        angulo += passo;
    }
    glEnd();
}

void desenha_olhoEsquerdo()
{
    semi_Circulo_Olho(0.105, -0.14, 0.28, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    // desenha a pupila
    Circulo(0.05, -0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, -0.14, 0.31, 30, 160, 5);
}

void desenha_olhoDireito()
{
    semi_Circulo_Olho(0.105, 0.14, 0.28, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);

    // desenha a pupila
    Circulo(0.05, 0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, 0.14, 0.31, 30, -160, 180);
}

void olho_serrado()
{
    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    // desenha a pupila
    Circulo(0.05, -0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, -0.14, 0.26, 30, 200, 0);
    semi_CirculoPalpebra(0.107, -0.14, 0.21, 30, -197, 0);

    // segundo olho
    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);

    // desenha a pupila
    Circulo(0.05, 0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, 0.14, 0.26, 30, -197, 180);
    semi_CirculoPalpebra(0.107, 0.14, 0.21, 30, 197, 180);
}

void olho_arregalado()
{

    semi_Circulo_Olho(0.105, -0.14, 0.28, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    // desenha a pupila
    Circulo(0.05, -0.13, 0.22, 20, 340);

    semi_Circulo_Olho(0.105, 0.14, 0.28, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);

    // desenha a pupila
    Circulo(0.05, 0.13, 0.22, 20, 340);
}

void olho_doca()
{

    semi_Circulo_Olho(0.105, -0.14, 0.28, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    semi_Circulo_Olho(0.105, 0.14, 0.28, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);
}

void trocar_corPupila(int R, int G, int B)
{
    semi_Circulo_Olho(0.105, -0.14, 0.28, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    // desenha a pupila
    float passo = grausParaRadianos(340 / 20);
    float x, y;
    float angulo = grausParaRadianos(0);

    glBegin(GL_POLYGON);
    glColor3ub(R, G, B); // define a cor
    for (int i = 0; i < 20; i++)
    {
        x = 0.05 * cos(angulo) + -0.13;
        y = 0.05 * sin(angulo) + 0.22;
        glVertex2f(x, y);
        angulo += passo;
    }
    glEnd();

    semi_CirculoPalpebra(0.107, -0.14, 0.31, 30, 160, 5);

    semi_Circulo_Olho(0.105, 0.14, 0.28, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);

    // desenha a pupila
    glBegin(GL_POLYGON);
    glColor3ub(R, G, B); // define a cor
    for (int i = 0; i < 20; i++)
    {
        x = 0.05 * cos(angulo) + 0.13;
        y = 0.05 * sin(angulo) + 0.22;
        glVertex2f(x, y);
        angulo += passo;
    }
    glEnd();
    semi_CirculoPalpebra(0.107, 0.14, 0.31, 30, -160, 180);
}

// fechado
void olho_fechado()
{
    semi_Circulo_Olho(0.105, -0.14, 0.18, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.25, 30, -180, 0);

    // desenha a pupila
    Circulo(0.05, -0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, -0.14, 0.24, 30, 210, -10);
    semi_CirculoPalpebra(0.107, -0.14, 0.20, 30, -197, 4);

    // segundo olho
    semi_Circulo_Olho(0.105, 0.14, 0.18, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.25, 30, 200, 180);

    // desenha a pupila
    Circulo(0.05, 0.13, 0.22, 20, 340);
    semi_CirculoPalpebra(0.107, 0.14, 0.24, 30, -197, 190);
    semi_CirculoPalpebra(0.107, 0.14, 0.21, 30, 197, 180);
}
// cor palbebra
void cor_daPalpebra(int R, int G, int B)
{
    semi_Circulo_Olho(0.105, -0.14, 0.28, 30, 200, 0);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(-0.244, 0.26);  // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(-0.24, 0.17);   // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.04, 0.17);   // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(-0.035, 0.28);  // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, -0.14, 0.21, 30, -180, 0);

    // desenha a pupila
    Circulo(0.05, -0.13, 0.22, 20, 340);

    float passo = grausParaRadianos(160 / 30);
    float x, y;
    float angulo = grausParaRadianos(5);

    glBegin(GL_POLYGON);
    glColor3ub(99, 48, 18); // define a cor
    for (int i = 0; i < 30; i++)
    {
        x = 0.107 * cos(angulo) + -0.14;
        y = 0.107 * sin(angulo) + 0.31;
        glVertex2f(x, y);
        glColor3ub(R, G, B); // define a cor

        angulo += passo;
    }
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.28, 30, -200, 180);

    glBegin(GL_POLYGON);
    glColor3ub(133, 133, 133); // define a cor

    glVertex2f(0.244, 0.26);   // ponto A
    glColor3ub(133, 133, 133); // define a cor
    glVertex2f(0.24, 0.17);    // ponto B
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.04, 0.17);    // ponto C
    glColor3ub(255, 255, 255); // define a cor
    glVertex2f(0.035, 0.28);   // ponto D
    glEnd();

    semi_Circulo_Olho(0.105, 0.14, 0.21, 30, 200, 180);

    // desenha a pupila
    Circulo(0.05, 0.13, 0.22, 20, 340);

    semi_CirculoPalpebra(0.107, 0.14, 0.31, 30, -160, 180);
    passo = grausParaRadianos(-160 / 30);
    angulo = grausParaRadianos(180);

    glBegin(GL_POLYGON);
    glColor3ub(99, 48, 18); // define a cor
    for (int i = 0; i < 30; i++)
    {
        x = 0.107 * cos(angulo) + 0.14;
        y = 0.107 * sin(angulo) + 0.31;
        glVertex2f(x, y);
        glColor3ub(R, G, B); // define a cor

        angulo += passo;
    }
    glEnd();
}

void desenha_parDeOlhos()
{
    desenha_olhoDireito();
    desenha_olhoEsquerdo();
}

void linha_Arco(float raio, float x0, float y0, float graus, float def, int origem)
{
    /* raio: define o tamanho do circulo.
     x0, y0: define a posição onde o circulo vai está.
     def: a quantidade de pontos, quanto maior mais perfeito o circulo
 */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(origem);

    glLineWidth(300.9f);
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);

        angulo += passo;
    }
    glEnd();
}

void sobracelhas()
{

    linha_Arco(0.105, -0.14, 0.38, 150, 10, 30);
    linha_Arco(0.105, -0.14, 0.39, 150, 10, 30);
    linha_Arco(0.105, -0.14, 0.40, 150, 10, 30);

    linha_Arco(0.105, 0.14, 0.38, -145, 10, 150);
    linha_Arco(0.105, 0.14, 0.39, -145, 10, 150);
    linha_Arco(0.105, 0.14, 0.40, -145, 10, 150);
}

void semi_Circulo_Corpo(float raio, float x0, float y0, int def, float graus)
{
    /* raio: define o tamanho do circulo.
        x0, y0: define a posição onde o circulo vai está.
        def: a quantidade de pontos, quanto maior mais perfeito o circulo
    */
    float passo = grausParaRadianos(graus / def);
    float x, y;
    float angulo = grausParaRadianos(0);

    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // define a cor
    for (int i = 0; i < def; i++)
    {
        x = raio * cos(angulo) + x0;
        y = raio * sin(angulo) + y0;
        glVertex2f(x, y);
        glColor3ub(99, 48, 18); // define a cor

        angulo += passo;
    }
    glEnd();
}

void torax()
{
    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // define a cor

    glVertex2f(0.3, 0.3);    // ponto A
    glVertex2f(0.403, -0.4); // ponto B

    glColor3ub(99, 48, 18); // define a cor

    glVertex2f(-0.403, -0.4); // ponto C
    glVertex2f(-0.302, 0.3);  // ponto D

    glColor3ub(99, 48, 18); // define a cor
    glEnd();
}

void corpo()
{
    // desenhando um circulo
    semi_Circulo_Corpo(0.3, 0.0, 0.3, 20, 200);
    torax();
    semi_Circulo_Corpo(0.400, 0.0, -0.4, 20, -189.6);
}

void desenha_bocatriste()
{
    // Define a cor da boca
    glColor3ub(255, 0, 0); // Vermelho

    // Define o raio e a posição central do semicírculo
    float raio = 0.15;
    float x_centro = 0.0;
    float y_centro = -0.5;

    // Define o número de pontos para o semicírculo
    int num_pontos = 30;

    // Calcula o ângulo de cada ponto no semicírculo
    float angulo;
    float passo_angulo = M_PI / num_pontos;

    // Desenha o semicírculo da boca
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = i * passo_angulo;
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenha_bocafeliz()
{
    // Define a cor da boca
    glColor3ub(255, 0, 0); // Vermelho

    // Define o raio e a posição central do semicírculo
    float raio = 0.15;
    float x_centro = 0.0;
    float y_centro = -0.3;

    // Define o número de pontos para o semicírculo
    int num_pontos = 30;

    // Calcula o ângulo de cada ponto no semicírculo
    float angulo;
    float passo_angulo = M_PI / num_pontos;

    // Desenha o semicírculo da boca
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = (i * passo_angulo) + M_PI; // Ajusta o ângulo para começar de baixo
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenha_boca_fechada()
{
    // Define a cor da boca
    glColor3ub(255, 0, 0); // Vermelho

    // Define a posição inicial e final da linha
    float x_inicio = -0.15;
    float y_inicio = -0.3;
    float x_fim = 0.15;
    float y_fim = -0.3;

    // Desenha a linha da boca
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(x_inicio, y_inicio);
    glVertex2f(x_fim, y_fim);
    glEnd();
}

void desenha_piercing()
{
    // Define a cor do piercing
    glColor3ub(255, 255, 255); // Branco

    // Define o raio e a posição central do piercing
    float raio_piercing = 0.02;
    float x_centro_piercing = 0.1;
    float y_centro_piercing = -0.33;

    // Define o número de pontos para o piercing
    int num_pontos_piercing = 30;

    // Calcula o ângulo de cada ponto no piercing
    float angulo_piercing;
    float passo_angulo_piercing = M_PI / num_pontos_piercing;

    // Desenha o piercing como um arco vertical usando GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < num_pontos_piercing; i++)
    {
        angulo_piercing = (i * passo_angulo_piercing) + (3 * M_PI / 2); // Ajusta o ângulo para começar do lado esquerdo
        float x = x_centro_piercing + raio_piercing * cos(angulo_piercing);
        float y = y_centro_piercing + raio_piercing * sin(angulo_piercing);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenha_bocafelizComPiercing()
{
    // Define a cor da boca
    glColor3ub(255, 0, 0); // Vermelho

    // Define o raio e a posição central do semicírculo
    float raio = 0.15;
    float x_centro = 0.0;
    float y_centro = -0.3;

    // Define o número de pontos para o semicírculo
    int num_pontos = 30;

    // Calcula o ângulo de cada ponto no semicírculo
    float angulo;
    float passo_angulo = M_PI / num_pontos;

    // Desenha o semicírculo da boca
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = (i * passo_angulo) + M_PI; // Ajusta o ângulo para começar de baixo
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();

    // Adiciona um piercing na boca
    desenha_piercing();
}

void desenha_orelhadireita()
{
    // Define a cor da orelha
    glColor3ub(0, 0, 0);

    // Define o raio e a posição central do semicírculo (orelha)
    float raio = 0.15;
    float x_centro = 0.29; // Ajuste a coordenada x para posicionar à direita do corpo
    float y_centro = 0.105;  // Ajuste a coordenada y para posicionar a orelha mais acima

    // Define o número de pontos para o semicírculo
    int num_pontos = 30;

    // Calcula o ângulo de cada ponto no semicírculo para virar para a esquerda
    float angulo;
    float inicio_angulo = M_PI / 2; // Começa a partir de 90 graus (apontando para cima)
    float passo_angulo = M_PI / num_pontos;

    // Desenha o semicírculo da orelha virada para a esquerda
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = inicio_angulo - (i * passo_angulo); // Ajusta o ângulo para virar para a esquerda
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
        glColor3ub(255, 65, 197);
    }
    glEnd();

    raio = 0.095;
    x_centro = 0.29; // Ajuste a coordenada x para posicionar à direita do corpo
    y_centro = 0.105;
    glColor3ub(0, 0, 0);
     // Desenha o semicírculo da orelha virada para a esquerda
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = inicio_angulo - (i * passo_angulo); // Ajusta o ângulo para virar para a esquerda
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
        glColor3ub(140, 35, 109);
    }
    glEnd();
}

void desenha_orelhaesquerda()
{
    // Define a cor da orelha
    glColor3ub(0,0,0);

    // Define o raio e a posição central do semicírculo (orelha)
    float raio = 0.15;
    float x_centro = -0.29; // Ajuste a coordenada x para posicionar à direita do corpo
    float y_centro = 0.105;   // Ajuste a coordenada y para posicionar a orelha mais acima

    // Define o número de pontos para o semicírculo
    int num_pontos = 30;

    // Calcula o ângulo de cada ponto no semicírculo para virar para a direita
    float angulo;
    float inicio_angulo = M_PI / 2; // Começa a partir de 90 graus (apontando para cima)
    float passo_angulo = M_PI / num_pontos;

    // Desenha o semicírculo da orelha virada para a direita
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = inicio_angulo + (i * passo_angulo); // Ajusta o ângulo para virar para a direita
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
        glColor3ub(255, 65, 197);

    }
    glEnd();

    // Define a cor da orelha
    glColor3ub(0,0,0);

    // Define o raio e a posição central do semicírculo (orelha)
    raio = 0.095;
    x_centro = -0.29; // Ajuste a coordenada x para posicionar à direita do corpo
    y_centro = 0.105;   // Ajuste a coordenada y para posicionar a orelha mais acima
    // Desenha o semicírculo da orelha virada para a direita
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_pontos; i++)
    {
        angulo = inicio_angulo + (i * passo_angulo); // Ajusta o ângulo para virar para a direita
        float x = x_centro + raio * cos(angulo);
        float y = y_centro + raio * sin(angulo);
        glVertex2f(x, y);
        glColor3ub(140, 35, 109);

    }
    glEnd();
}

void desenha_orelha()
{
    desenha_orelhaesquerda();
    desenha_orelhadireita();
}

void brinco(){
    CirculoCor(0.06,0.35,-0.04,30,360,255,255,0,0);
    CirculoCor(0.06,-0.35,-0.04,30,360,255,255,0,180);
}
//sapatos
void desenha_sapatodireita() {
    // Fatores de escala e posição para ajustar o sapato
    float escala = 0.7; // Fator de escala para diminuir um pouco o tamanho do sapato
    float deslocamento_x = -0.25; // Desloca o sapato para a esquerda
    float deslocamento_y = -0.65; // Desloca o sapato para baixo

    // Desenha a sola do sapato como um retângulo diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Cor preta
    glVertex2f((deslocamento_x - 0.1) * escala, deslocamento_y - 0.3 * escala); // Canto inferior esquerdo (abaixo do corpo)
    glVertex2f((deslocamento_x + 0.1) * escala, deslocamento_y - 0.3 * escala); // Canto inferior direito (abaixo do corpo)
    glVertex2f((deslocamento_x + 0.08) * escala, deslocamento_y); // Canto superior direito (abaixo do corpo)
    glVertex2f((deslocamento_x - 0.08) * escala, deslocamento_y); // Canto superior esquerdo (abaixo do corpo)
    glEnd();

    // Desenha o corpo do sapato como um polígono diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // Cor do sapato

    // Coordenadas dos vértices do corpo do sapato (diminuído e deslocado)
    float x1 = (deslocamento_x + 0.1) * escala; // Canto inferior direito
    float y1 = deslocamento_y - 0.3 * escala;
    float x2 = (deslocamento_x - 0.1) * escala; // Canto inferior esquerdo
    float y2 = deslocamento_y - 0.3 * escala;
    float x3 = deslocamento_x * escala; // Ponta do sapato (abaixo)
    float y3 = (deslocamento_y - 0.15) * escala; // Ajuste a altura da ponta do sapato

    glVertex2f(x1, y1); // Canto inferior direito do corpo do sapato
    glVertex2f(x2, y2); // Canto inferior esquerdo do corpo do sapato
    glVertex2f(x3, y3); // Ponta do sapato
    glEnd();
}

void desenha_sapatoesquerda() {
    // Fatores de escala e posição para ajustar o sapato
    float escala = 0.7; // Fator de escala para diminuir um pouco o tamanho do sapato
    float deslocamento_x = 0.25; // Desloca o sapato para a direita
    float deslocamento_y = -0.65; // Desloca o sapato para baixo

    // Desenha a sola do sapato como um retângulo diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Cor preta
    glVertex2f((deslocamento_x - 0.1) * escala, deslocamento_y - 0.3 * escala); // Canto inferior esquerdo (abaixo do corpo)
    glVertex2f((deslocamento_x + 0.1) * escala, deslocamento_y - 0.3 * escala); // Canto inferior direito (abaixo do corpo)
    glVertex2f((deslocamento_x + 0.08) * escala, deslocamento_y); // Canto superior direito (abaixo do corpo)
    glVertex2f((deslocamento_x - 0.08) * escala, deslocamento_y); // Canto superior esquerdo (abaixo do corpo)
    glEnd();

    // Desenha o corpo do sapato como um polígono diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // Cor do sapato

    // Coordenadas dos vértices do corpo do sapato (diminuído e deslocado)
    float x1 = (deslocamento_x + 0.1) * escala; // Canto inferior direito
    float y1 = deslocamento_y - 0.3 * escala;
    float x2 = (deslocamento_x - 0.1) * escala; // Canto inferior esquerdo
    float y2 = deslocamento_y - 0.3 * escala;
    float x3 = deslocamento_x * escala; // Ponta do sapato (abaixo)
    float y3 = (deslocamento_y - 0.15) * escala; // Ajuste a altura da ponta do sapato

    glVertex2f(x1, y1); // Canto inferior direito do corpo do sapato
    glVertex2f(x2, y2); // Canto inferior esquerdo do corpo do sapato
    glVertex2f(x3, y3); // Ponta do sapato
    glEnd();
}


void desenha_sapato_esquerdo_com_listra_na_base() {
    // Fatores de escala e posição para ajustar o sapato
    float escala = 0.7; // Fator de escala para diminuir um pouco o tamanho do sapato
    float deslocamento_x = 0.25; // Desloca o sapato para a direita
    float deslocamento_y = -0.65; // Desloca o sapato para baixo

    // Desenha a sola do sapato como uma curva
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); // Cor preta

    // Desenho da sola curva do sapato
    for (float angle = 0.0; angle <= M_PI; angle += 0.1) {
        float x = deslocamento_x + cos(angle) * 0.1 * escala;
        float y = deslocamento_y - sin(angle) * 0.3 * escala;
        glVertex2f(x * escala, y * escala);
    }

    glEnd();

    // Desenha o corpo do sapato como um polígono diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // Cor do sapato

    // Coordenadas dos vértices do corpo do sapato (diminuído e deslocado)
    float x1 = (deslocamento_x + 0.1) * escala; // Canto inferior direito
    float y1 = deslocamento_y - 0.3 * escala;
    float x2 = (deslocamento_x - 0.1) * escala; // Canto inferior esquerdo
    float y2 = deslocamento_y - 0.3 * escala;
    float x3 = deslocamento_x * escala; // Ponta do sapato (abaixo)
    float y3 = (deslocamento_y - 0.15) * escala; // Ajuste a altura da ponta do sapato

    //Vértices do corpo do sapato
    glVertex2f(x1, y1); // Canto inferior direito do corpo do sapato
    glVertex2f(x2, y2); // Canto inferior esquerdo do corpo do sapato
    glVertex2f(x3, y3); // Ponta do sapato

    glEnd();

    glLineWidth(6.0); // Define a largura da linha para 6 pixels

    // Desenha a listra na base do sapato
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Cor  para a listra

    // Coordenadas da listra na base do sapato
    float base_y = deslocamento_y - 0.3 * escala; // Altura da base do sapato
    float base_width = (x1 - x2) * 0.8; // Largura da listra (80% da largura do corpo do sapato)

    glVertex2f(x2, base_y); // Extremidade esquerda da listra
    glVertex2f(x1, base_y); // Extremidade direita da listra


    glEnd();
}

void desenha_sapato_direito_com_listra_na_base() {
    // Fatores de escala e posição para ajustar o sapato
    float escala = 0.7; // Fator de escala para diminuir um pouco o tamanho do sapato
    float deslocamento_x = -0.25; // Desloca o sapato para a esquerda
    float deslocamento_y = -0.65; // Desloca o sapato para baixo

    // Desenha a sola do sapato como uma curva
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); // Cor preta

    // Desenho da sola curva do sapato
    for (float angle = 0.0; angle <= M_PI; angle += 0.1) {
        float x = deslocamento_x + cos(angle) * 0.1 * escala;
        float y = deslocamento_y - sin(angle) * 0.3 * escala;
        glVertex2f(x * escala, y * escala);
    }

    glEnd();

    // Desenha o corpo do sapato como um polígono diminuído e deslocado
    glBegin(GL_POLYGON);
    glColor3ub(179, 118, 64); // Cor do sapato

    // Coordenadas dos vértices do corpo do sapato (diminuído e deslocado)
    float x1 = (deslocamento_x + 0.1) * escala; // Canto inferior direito
    float y1 = deslocamento_y - 0.3 * escala;
    float x2 = (deslocamento_x - 0.1) * escala; // Canto inferior esquerdo
    float y2 = deslocamento_y - 0.3 * escala;
    float x3 = deslocamento_x * escala; // Ponta do sapato (abaixo)
    float y3 = (deslocamento_y - 0.15) * escala; // Ajuste a altura da ponta do sapato

    // Vértices do corpo do sapato
    glVertex2f(x1, y1); // Canto inferior direito do corpo do sapato
    glVertex2f(x2, y2); // Canto inferior esquerdo do corpo do sapato
    glVertex2f(x3, y3); // Ponta do sapato

    glEnd();

    glLineWidth(6.0); // Define a largura da linha para 6 pixels

    // Desenha a listra na base do sapato
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Cor preta para a listra

    // Coordenadas da listra na base do sapato
    float base_y = deslocamento_y - 0.3 * escala; // Altura da base do sapato
    float base_width = (x1 - x2) * 0.8; // Largura da listra (80% da largura do corpo do sapato)

    glVertex2f(x2, base_y); // Extremidade esquerda da listra
    glVertex2f(x1, base_y); // Extremidade direita da listra

    glEnd();
}

//bonés


void desenha_bone() {
    // Cor e tamanho do boné
    glColor3ub(R, G, B); // Azul
    float raio = 0.3; // Raio da base do boné

    // Desenha a parte de baixo do boné (círculo)
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0;
        float x = raio * cos(angle);
        float y = raio * sin(angle);
        glVertex2f(x, y + 0.4); // Ajuste a altura para ficar acima da cabeça
    }
    glEnd();

    // Desenha a parte superior do boné (parte retangular)
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.7); // Canto superior esquerdo
    glVertex2f(0.3, 0.7);  // Canto superior direito
    glVertex2f(0.2, 0.4);  // Canto inferior direito
    glVertex2f(-0.2, 0.4); // Canto inferior esquerdo
    glEnd();
}

//Função para desenhar um gorro na cabeça do personagem
void desenha_gorro() {
    float raio_base = 0.3; // Raio da base do gorro
    float altura_gorro = 0.4; // Altura do gorro
    int num_segmentos = 30; // Número de segmentos para desenhar o gorro

    // Desenha a base do gorro (um círculo)
    glBegin(GL_POLYGON);
    glColor3ub(R, G, B); // Cor preto para o gorro

    for (int i = 0; i < num_segmentos; i++) {
        float angulo = 2.0 * M_PI * i / num_segmentos;
        float x = raio_base * cos(angulo);
        float y = raio_base * sin(angulo);
        glVertex2f(x, y);
    }

    glEnd();

    // Desenha o topo arredondado do gorro
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, altura_gorro); // Vértice do topo do gorro

    for (int i = 0; i <= num_segmentos; i++) {
        float angulo = 2.0 * M_PI * i / num_segmentos;
        float x = raio_base * cos(angulo);
        float y = raio_base * sin(angulo);
        glVertex2f(x, y + altura_gorro); // Adiciona a altura para formar o topo arredondado
    }

    glEnd();
}
void DesenhaTexto(char *string)
{
    glColor3ub(0, 0, 0);
    glPushMatrix();
    // Posição no universo onde o texto será colocado
    glRasterPos2f(-1, 0.8);
    // Exibe caracter a caracter
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    glPopMatrix();
    glColor3ub(255, 255, 255);
}
// Função para desenhar um chapéu
void desenha_chapeu() {
    float raio_base = 0.5;
    float altura_chapeu = 0.8;

    // Cor do chapéu (azul)
    glColor3ub(R, G, B);

    // Desenha a parte cônica do chapéu (usando triângulos para aproximar um cone)
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 360; i += 10) {
        glVertex2f(0.0, altura_chapeu);  // Ponto no topo do chapéu
        glVertex2f(raio_base * sin(i * M_PI / 180), raio_base * cos(i * M_PI / 180));  // Ponto na circunferência
        glVertex2f(raio_base * sin((i + 10) * M_PI / 180), raio_base * cos((i + 10) * M_PI / 180));  // Próximo ponto na circunferência
    }
    glEnd();

    // Desenha a base circular do chapéu
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        glVertex2f(raio_base * sin(i * M_PI / 180), raio_base * cos(i * M_PI / 180));  // Pontos na circunferência
        glColor3ub(0, 0,0 );
    }
    glEnd();
}

void boca(){
    switch (tipoBoca)
    {
    case 1:  
        desenha_bocafeliz();
        break;
    case 2:
        desenha_bocatriste();
        break;
    case 3:
        desenha_boca_fechada();
        break;
    case 4:
        desenha_bocafelizComPiercing();
        break;
    default:
        break;
    }
}
void cabelo(){
     switch (tipoCabelo)
    {
    case 1:  
        desenha_bone();
        break;
    case 2:
        desenha_gorro() ;
        break;
    case 3:
        desenha_chapeu() ;
        break;
    default:
        break;
    }
}
void sapato (){
     switch (tipoSapato)
    {
    case 1:  
        desenha_sapatoesquerda();
        desenha_sapatodireita();
        break;
    case 2:
        desenha_sapato_esquerdo_com_listra_na_base();
        desenha_sapato_direito_com_listra_na_base();
        break;
   
    default:
        break;
    }
}
void brincodaorelha(){
       switch (tipoBrinco)
    {
    case 1:  
        CirculoCor(0.06,0.35,-0.04,30,360,255,255,0,0);
        CirculoCor(0.06,-0.35,-0.04,30,360,255,255,0,180);
        break;
    default:
        break;
    }
}

void nariz(){
    switch (tipoNariz)
    {
    case 1:  
        desenha_nariz();
        break;
    case 2:
        nariz_porco();
        break;
    case 3 :
        nariz_de_palhaco(0.15, 0, -0.1, 60, 360,90);
        break;
    default:
        break;
    }
}

void olho()
{
    switch (tipoOlho)
    {
    case 1:  
        desenha_parDeOlhos();
        break;
    case 2:
        olho_doca();
        break;
    case 3:
        cor_daPalpebra(255,0,0);
        break;
    case 4:
        trocar_corPupila(0,0,255);
        break;
    case 5:
        olho_arregalado();
        break;
    case 6:
        olho_serrado();
        break;
    case 7:
        olho_fechado();;
        break;
    default:
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        tipoOlho = 1;
        break;
    case '2':
        tipoOlho = 2;
        break;
    case '3':
        tipoOlho = 3;
        break;
    case '4':
        tipoOlho = 4;
        break;
    case '5':
        tipoOlho = 5;
        break;
    case '6':
        tipoOlho = 6;
        break;
    case '7':
        tipoOlho = 7;
        break;
    case 'q':
        tipoNariz = 1;
        break;
    case 'w':
        tipoNariz = 2;
        break;
    case 'e':
        tipoNariz = 3;
        break;
    case 'a':
        tipoBoca = 1;
        break;
    case 's':
        tipoBoca = 2;
        break;
    case 'd':
        tipoBoca = 3;
        break;
    case 'f':
        tipoBoca = 4;
        break;
    case 'z':
        tipoSapato = 1;
        break;
    case 'x':
        tipoSapato = 2;
        break;
    case 'c':
        tipoBrinco = 1;
        break;
    case 'b':
        tipoCabelo = 1;
        break;
    case 'n':
        tipoCabelo = 2;
        break;
    case 'm':
        tipoCabelo = 3;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}