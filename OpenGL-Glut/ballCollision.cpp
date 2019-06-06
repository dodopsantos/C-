/// colisao de quadrados 
#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>
#define janela_altura 400 
#define janela_largura 600 
#define PI 3.1416
float trans = 100;
float cateto1, cateto2, distancia;

struct vertices
{
	int x;
	int y;
};

struct vertices mouse;


void display(void);
void tela(GLsizei W, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void movimentoMouse(int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("colisao_circulo"); // cria janela 

	glutPassiveMotionFunc(movimentoMouse);
	//glutFullscreen(); 
	glutKeyboardFunc(&keyboard); // chama teclado 
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 
	return(0);
}

void movimentoMouse(int x, int y)
{
	mouse.x = x - (janela_largura / 2);
	mouse.y = y - (janela_altura / 2);

	cateto1 = mouse.x;
	cateto2 = mouse.y;

	distancia = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));

}

void keyboard(unsigned char tecla, int x, int y) {

	printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 para esquerda: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);
	if (tecla == '1')
	{
		trans = trans - 1;
		printf("\n o valor de translacao e %.2f\n", trans);
	}
	if (tecla == '2')
	{
		trans = trans + 1;
		printf("\n o valor de translação e %.2f\n", trans);
	}

	glutPostRedisplay();
}
void desenhar()
{
	glScaled(1, -1, 1);
	glTranslatef(0, 0, 0);

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 50.0f, raioY = 50.0f;

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glTranslatef(mouse.x, mouse.y, 0);
	// cor 
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();
	glutPostRedisplay();
}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho 
	glLoadIdentity();

	if (distancia >= 100) {

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	}
	else {

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // cor do fundo 
	}

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA 
								  // Especificar o local aonde o desenho acontece: bem no centro da janela 
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush();
	// execute o desenho 
}
void tela(GLsizei W, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima) 
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
