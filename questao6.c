/*
    Questao 6 da lista 1 de Computação gráfica
    Nome: Anélio Gonçalves Caldas
*/

#include <GL/glut.h>

int inicialSizeWindow = 500;
int posicaoXMouse;
int posicaoYMouse;

void desenhaMinhaCena()
{
    glClearColor(1, 1, 1, 1);  //branco

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    
    // Desenha um polígono por seus vértices
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(20.0, 20.0, 0.0);
        glVertex3f(80.0, 20.0, 0.0);
        glVertex3f(80.0, 80.0, 0.0);
        glVertex3f(20.0, 80.0, 0.0);
    glEnd();

    glFlush();
}

void redimensiona(int width, int height)
{
    // Verifica se a tela foi redmensionada:
    if((width != inicialSizeWindow) || (height != inicialSizeWindow)){
        printf("Redimensionamento de tela:\n");
        printf("Nova largura: %d\n", width); 
        printf("Nova altura : %d\n", height);   
    }
        
   // left, bottom, right, top
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y)
{
    printf("Tecla %c pressionada, Posição do mouse: x: %d e y: %d\n", key, x, y);

    // vê qual tecla foi pressionada
    switch(key)
    {
    case 27:      // Tecla "ESC"
        exit(0);  // Sai da aplicação
        break;
    default:
        break;
    }
}
void gerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            printf("Botão esquerdo do mouse pressionado, Posição do mouse: x: %d e y: %d\n", x, y);
        }
        if (state == GLUT_UP){
            printf("Botão esquerdo do mouse foi solto, Posição do mouse: x: %d e y: %d\n", x, y);
        }
    }
    if (button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN){
            printf("Botão direito do mouse pressionado, Posição do mouse: x: %d e y: %d\n", x, y);
        }
        if (state == GLUT_UP){
            printf("Botão direito do mouse foi solto, Posição do mouse: x: %d e y: %d\n", x, y);
        }
    }
}

void imprimirPosicaoMouse(){
    printf("Posicao do mouse: x: %d e y: %d\n", posicaoXMouse, posicaoYMouse);
}

void movimentoMouse(int x, int y){
    // Atualiza a posicao do mouse se ela tiver mudado:
    if(posicaoXMouse != x || posicaoYMouse != y){
        posicaoXMouse = x;
        posicaoYMouse = y;
        imprimirPosicaoMouse();
    }

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(inicialSizeWindow, inicialSizeWindow);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Questao6_Anelio");
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);
    glutMouseFunc(gerenciaMouse);
    glutPassiveMotionFunc(movimentoMouse);
    glutMainLoop();
    return 0;
}
