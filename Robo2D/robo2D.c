#include <windows.h>
//#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

// Declaração das variáveis para controle dos ângulos de cada parte do robô
static GLint ombroEsq = 0, cotoveloEsq = 0, maoEsq = 0;
static GLint ombroDir = 0, cotoveloDir = 0, maoDir = 0;
static GLint pernaEsq = 0, joelhoEsq = 0, peEsq = 0;
static GLint pernaDir = 0, joelhoDir = 0, peDir = 0;
static GLint cabeca = 0, tronco = 0;
static GLint dedo1Esq = 0, dedo1Esq2 = 0, dedo1Esq3 = 0, dedo2Esq = 0, dedo2Esq2 = 0, dedo2Esq3 = 0;
static GLint dedo1Dir = 0, dedo1Dir2 = 0, dedo1Dir3 = 0, dedo2Dir = 0, dedo2Dir2 = 0, dedo2Dir3 = 0;

void Desenho(void);
void Redimensionamento(GLint largura, GLint altura);
void Teclado(unsigned char tecla, GLint x, GLint y);
void DesenhaQuadrado(void);

void DesenhaQuadrado(void) {
    glBegin(GL_POLYGON);
        glVertex2f(-1, 1);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 1);
    glEnd();
}

void DesenhaTexto(char *string)
{
    glColor3ub(255, 255, 255);
    glPushMatrix();
    // Posição no universo onde o texto será colocado
    glRasterPos2f(-4.0,4.0);
    // Exibe caracter a caracter
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    glPopMatrix();
    glColor3ub(255, 255, 255);
}

void Desenho(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    DesenhaTexto("|ombro| A e G |cotovelo| S e F  |mao| Z e V |dedos| Q ao L");
    // Desenhar o tronco
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef((GLfloat)tronco, 0.0, 0.0, 1.0);
        glPushMatrix();
            glScalef(0.5, 1.0, 1.0); // Escala do tronco
            DesenhaQuadrado();
        glPopMatrix();

        // Desenhar a cabeça
        glPushMatrix();
            glTranslatef(0.0, 1.5, 0.0); // Aumenta a translação vertical da cabeça
            glRotatef((GLfloat)cabeca, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef(0.3, 0.3, 1.0); // Escala da cabeça
                DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix();

        // Desenhar o braço esquerdo
        glPushMatrix();
            glTranslatef(-0.3, 0.8, 0.0);
            glRotatef((GLfloat)ombroEsq, 0.0, 0.0, 1.0);
            glTranslatef(-0.7, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.4, 0.12, 1.0); // Escala do braço esquerdo
                DesenhaQuadrado();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.1, 0.0, 0.0);
                glRotatef((GLfloat)cotoveloEsq, 0.0, 0.0, 1.0);
                glTranslatef(-0.7, 0.0, 0.0);
                glPushMatrix();
                    glScalef(0.3, 0.12, 1.0); // Escala do antebraço (cotovelo esquerdo)
                    DesenhaQuadrado();
                glPopMatrix();

                // Desenhar a mão esquerda e dedos

                glPushMatrix();

                    glTranslatef(-0.4, 0.0, 0.0);
                    glRotatef((GLfloat)maoEsq, 0.0, 0.0, 1.0);
                    glTranslatef(-0.2, 0.0, 0.0);

                    glPushMatrix();
                        glScalef(0.24, 0.08, 1.0); // Escala da mão esquerda
                        DesenhaQuadrado();
                    glPopMatrix();

                    // Dedo 1 esquerdo
                    glPushMatrix();

                        glTranslatef(-0.4, 0.1, 0.0);
                        glRotatef((GLfloat)dedo1Esq, 0.0, 0.0, 1.0);

                        glPushMatrix();
                            glScalef(0.10, 0.04, 1.0); // Escala do dedo 1 esquerdo
                            DesenhaQuadrado();
                        glPopMatrix();

                        glPushMatrix();

                            glTranslatef(-0.21, 0.0, 0.0);
                            glRotatef((GLfloat)dedo1Esq2, 0.0, 0.0, 1.0);

                            glPushMatrix();
                                glScalef(0.08, 0.04, 1.0); // Escala do dedo 1 esquerdo 2
                                DesenhaQuadrado();
                            glPopMatrix();

                            
                            glPushMatrix();

                                glTranslatef(-0.19, 0.0, 0.0);//
                                glRotatef((GLfloat)dedo1Esq3, 0.0, 0.0, 1.0);

                                glPushMatrix();
                                    glScalef(0.06, 0.04, 1.0); // Escala do dedo 1 esquerdo 3
                                    DesenhaQuadrado();
                                glPopMatrix();

                            glPopMatrix();


                        glPopMatrix();

                    glPopMatrix();

                    // Dedo 2 esquerdo

                    glPushMatrix();

                        glTranslatef(-0.4, -0.1, 0.0);
                        glRotatef((GLfloat)dedo2Esq, 0.0, 0.0, 1.0);
                        glPushMatrix();
                            glScalef(0.10, 0.04, 1.0); // Escala do dedo 2 esquerdo
                            DesenhaQuadrado();
                        glPopMatrix();

                        
                        glPushMatrix();

                        glTranslatef(-0.21, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Esq2, 0.0, 0.0, 1.0);
                            
                            glPushMatrix();
                                glScalef(0.08, 0.04, 1.0); // Escala do dedo 2 esquerdo 2
                                DesenhaQuadrado();
                            glPopMatrix();

                            
                            glPushMatrix();

                            glTranslatef(-0.19, 0.0, 0.0);
                            glRotatef((GLfloat)dedo2Esq3, 0.0, 0.0, 1.0);
                            
                                glPushMatrix();
                                    glScalef(0.06, 0.04, 1.0); // Escala do dedo 2 esquerdo 3
                                    DesenhaQuadrado();
                                glPopMatrix();

                            glPopMatrix();

                        glPopMatrix();

                    glPopMatrix();

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();

        // Desenhar o braço direito
        glPushMatrix();
            glTranslatef(0.3, 0.8, 0.0);
            glRotatef((GLfloat)ombroDir, 0.0, 0.0, 1.0);
            glTranslatef(0.7, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.4, 0.12, 1.0); // Escala do braço direito
                DesenhaQuadrado();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.1, 0.0, 0.0);
                glRotatef((GLfloat)cotoveloDir, 0.0, 0.0, 1.0);
                glTranslatef(0.7, 0.0, 0.0);
                glPushMatrix();
                    glScalef(0.3, 0.12, 1.0); // Escala do antebraço (cotovelo direito)
                    DesenhaQuadrado();
                glPopMatrix();
                // Desenhar a mão direita e dedos
                glPushMatrix();
                    glTranslatef(0.4, 0.0, 0.0);
                    glRotatef((GLfloat)maoDir, 0.0, 0.0, 1.0);
                    glTranslatef(0.2, 0.0, 0.0);
                    glPushMatrix();
                        glScalef(0.24, 0.08, 1.0); // Escala da mão direita
                        DesenhaQuadrado();
                    glPopMatrix();

                    // Dedo 1 direito
                    glPushMatrix();

                        glTranslatef(0.4, 0.1, 0.0);
                        glRotatef((GLfloat)dedo1Dir, 0.0, 0.0, 1.0);

                        glPushMatrix();
                            glScalef(0.10, 0.04, 1.0); // Escala do dedo 1 direito
                            DesenhaQuadrado();
                        glPopMatrix();

                        glPushMatrix();
                            glTranslatef(0.2, 0.0, 0.0);
                            glRotatef((GLfloat)dedo1Dir2, 0.0, 0.0, 1.0);

                            glPushMatrix();
                                glScalef(0.08, 0.04, 1.0); // Escala do dedo 1 direito 2
                                DesenhaQuadrado();
                            glPopMatrix();

                            glPushMatrix();
                                glTranslatef(0.19, 0.0, 0.0);
                                glRotatef((GLfloat)dedo1Dir3, 0.0, 0.0, 1.0);

                                glPushMatrix();
                                    glScalef(0.06, 0.04, 1.0); // Escala do dedo 1 direito 3
                                    DesenhaQuadrado();
                                glPopMatrix();
                            
                            glPopMatrix();
                            
                        glPopMatrix();
                    
                    glPopMatrix();

                    // Dedo 2 direito
                    glPushMatrix();

                        glTranslatef(0.4, -0.1, 0.0);
                        glRotatef((GLfloat)dedo2Dir, 0.0, 0.0, 1.0);

                        glPushMatrix();
                            glScalef(0.10, 0.04, 1.0); // Escala do dedo 2 direito
                            DesenhaQuadrado();
                        glPopMatrix();


                        glPushMatrix();

                        glTranslatef(0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Dir2, 0.0, 0.0, 1.0);

                        glPushMatrix();
                            glScalef(0.08, 0.04, 1.0); // Escala do dedo 2 direito 2
                            DesenhaQuadrado();
                        glPopMatrix();

                        
                            glPushMatrix();

                            glTranslatef(0.19, 0.0, 0.0);
                            glRotatef((GLfloat)dedo2Dir3, 0.0, 0.0, 1.0);

                            glPushMatrix();
                                glScalef(0.06, 0.04, 1.0); // Escala do dedo 2 direito 3
                                DesenhaQuadrado();
                            glPopMatrix();
                    
                            glPopMatrix();
                    
                        glPopMatrix();
                    
                    glPopMatrix();

                glPopMatrix();

            glPopMatrix();
        glPopMatrix();

        // Desenhar a perna esquerda
        glPushMatrix();
            glTranslatef(-0.4, -0.8, 0.0);
            glRotatef((GLfloat)pernaEsq, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.7, 0.0);
            glPushMatrix();
                glScalef(0.12, 0.4, 1.0); // Escala da perna esquerda
                DesenhaQuadrado();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, -0.2, 0.0);
                glRotatef((GLfloat)joelhoEsq, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.7, 0.0);
                glPushMatrix();
                    glScalef(0.12, 0.4, 1.0); // Escala do joelho esquerdo
                    DesenhaQuadrado();
                glPopMatrix();
                // Desenhar o pé esquerdo
                glPushMatrix();
                    glTranslatef(0.0, -0.4, 0.0);
                    glRotatef((GLfloat)peEsq, 0.0, 0.0, 1.0);
                    glTranslatef(0.18, -0.18, 0.0);
                    glPushMatrix();
                        glScalef(0.36, 0.12, 1.0); // Escala do pé esquerdo
                        DesenhaQuadrado();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        // Desenhar a perna direita
        glPushMatrix();
            glTranslatef(0.4, -0.8, 0.0);
            glRotatef((GLfloat)pernaDir, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.7, 0.0);
            glPushMatrix();
                glScalef(0.12, 0.4, 1.0); // Escala da perna direita
                DesenhaQuadrado();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, -0.2, 0.0);
                glRotatef((GLfloat)joelhoDir, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.7, 0.0);
                glPushMatrix();
                    glScalef(0.12, 0.4, 1.0); // Escala do joelho direito
                    DesenhaQuadrado();
                glPopMatrix();
                // Desenhar o pé direito
                glPushMatrix();
                    glTranslatef(0.0, -0.4, 0.0);
                    glRotatef((GLfloat)peDir, 0.0, 0.0, 1.0);
                    glTranslatef(0.18, -0.18, 0.0);
                    glPushMatrix();
                        glScalef(0.36, 0.12, 1.0); // Escala do pé direito
                        DesenhaQuadrado();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void Redimensionamento(GLint largura, GLint altura) {
    glViewport(0, 0, (GLsizei)largura, (GLsizei)altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // Exibição Bidimensional
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Teclado(unsigned char tecla, GLint x, GLint y) {
    switch (tecla) {

        // Controle do braço esquerdo
        case 'a':
            ombroEsq = (ombroEsq + 5) % 360;
            break;
        case 's':
            cotoveloEsq = (cotoveloEsq + 5) % 360;
            break;
        case 'z':
            maoEsq = (maoEsq + 5) % 360;
            break;

        // Controle do braço direito
        case 'g':
            ombroDir = (ombroDir + 5) % 360;
            break;
        case 'f':
            cotoveloDir = (cotoveloDir + 5) % 360;
            break;
        case 'v':
            maoDir = (maoDir + 5) % 360;
            break;

        // Controle dos dedos

        case 'q'://dedos esquerdo (superior\inferior)
            dedo1Esq = (dedo1Esq + 5) % 360;
            break;
        case 'w':
            dedo1Esq2 = (dedo2Esq + 5) % 360;
            break;
        case 'e':
            dedo1Esq3 = (dedo1Esq + 5) % 360;
            break;
        case 'r':
            dedo2Esq = (dedo2Esq - 5) % 360;
            break;
        case 't':
            dedo2Esq2 = (dedo1Esq - 5) % 360;
            break;
        case 'y':
            dedo2Esq3 = (dedo2Esq - 5) % 360;
            break;
        case 'u': //dedos direito (superior\inferior)
            dedo1Dir = (dedo1Dir - 5) % 360; 
            break;
        case 'i':
            dedo1Dir2 = (dedo1Dir2 - 5) % 360;
            break;
        case 'o':
            dedo1Dir3 = (dedo1Dir3 - 5) % 360;
            break;
        case 'p':
            dedo2Dir = (dedo2Dir + 5) % 360;
            break;
        case 'l':
            dedo2Dir2 = (dedo2Dir2 + 5) % 360;
            break;
        case 'k':
            dedo2Dir3 = (dedo2Dir3 + 5) % 360;
            break;
        // Sair do programa
        case 27:
            exit(0);
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(Desenho);
    glutReshapeFunc(Redimensionamento);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}