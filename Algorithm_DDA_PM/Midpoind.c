#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <windows.h>
#include <stddef.h>

void displayDDA(void);
void displayPM(void);
void iniciarDDA(void);
void iniciarPM(void);
void keyboard(unsigned char key, int x, int y);

int DDA, PM, PMC; // Variáveis das janelas gráficas

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  iniciarDDA();
  iniciarPM();
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  return 0;
}

void iniciarDDA(void){
  glutInitWindowSize (640, 640); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (10, 10); //Estabelece o tamanho (em pixels) da janela a ser criada
  DDA = glutCreateWindow ("DDA");
  glClearColor(1.0, 1.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-2, 12, -2, 12, -1 ,1);
  glutDisplayFunc(displayDDA); //Função callback chamada para fazer o desenho
}

void iniciarPM(void){
  glutInitWindowSize (640, 640); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (1000, 10); //Estabelece o tamanho (em pixels) da janela a ser criada
  PM = glutCreateWindow ("Ponto Médio");
  glClearColor(1.0, 1.0, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-2, 12, -2, 12, -1 ,1);
  glutDisplayFunc(displayPM); //Função callback chamada para fazer o desenho
}

void displayDDA(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  // Desenhando os eixos
  // Definindo a espessura da linha
  glLineWidth(2.0);
  glBegin (GL_LINES);
    // Definindo a reta do eixo Y
    glVertex3i(0,0,0.0);
    glVertex3i(0.0,10,0.0);
    // Definindo a reta do eixo X
    glVertex3i(0.0,0,0.0);
    glVertex3i(10,0,0.0);
  glEnd();
  // Desenhando as pontas dos eixos
  glBegin(GL_TRIANGLES);
    // Triangulo do eixo Y
    glVertex3f(-0.2,10,0.0);
    glVertex3f(0.0,10.2,0.0);
    glVertex3f(0.2,10,0.0);
    //Triangulo do eixo X
    glVertex3f(10,0.2,0.0);
    glVertex3f(10,-0.2,0.0);
    glVertex3f(10.2,0.0,0.0);
  glEnd();
  // Desenhando os pontos (cor: vermelha)
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glBegin(GL_POINTS);
    glVertex3i(2,2,0.0);
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void displayPM(void){
  glClear(GL_COLOR_BUFFER_BIT); ////Limpa a janela de visualização com a cor de fundo especificada
  glColor3f (0.0, 0.0, 0.0);
  // Desenhando os eixos
  // Definindo a espessura da linha
  glLineWidth(2.0);
  glBegin (GL_LINES);
    // Definindo a reta do eixo Y
    glVertex3i(0,0,0.0);
    glVertex3i(0.0,10,0.0);
    // Definindo a reta do eixo X
    glVertex3i(0.0,0,0.0);
    glVertex3i(10,0,0.0);
  glEnd();
   // Desenhando as pontas dos eixos
  glBegin(GL_TRIANGLES);
    // Triangulo do eixo Y
    glVertex3f(-0.2,10,0.0);
    glVertex3f(0.0,10.2,0.0);
    glVertex3f(0.2,10,0.0);
    //Triangulo do eixo X
    glVertex3f(10,0.2,0.0);
    glVertex3f(10,-0.2,0.0);
    glVertex3f(10.2,0.0,0.0);
  glEnd();
   // Desenhando os pontos (cor: vermelha)
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glBegin(GL_POINTS);
    glVertex3i(2,2,0.0);
  glEnd();
  glFlush(); ////Executa os comandos OpenGL para renderização
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: exit(0);
  }
}
