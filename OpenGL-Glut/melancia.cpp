#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>

void display(void);
void draw(void);
void seed(void);
#define PI 3.1416


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(1000, 800);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao inicial da janela
	glutCreateWindow("Melancia");   /// cria a janela	
	
	glutDisplayFunc(display);
	glutMainLoop();

	return EXIT_SUCCESS;
}
void draw() {
	//parte verde
	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 0.6f, raioY = 0.6f;

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt / -2;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	//parte branca
	GLfloat circ_pnt3 = 500;
	GLfloat ang3, raioX3 = 0.53f, raioY3 = 0.53f;

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int l = 0; l < circ_pnt; l++) {
		ang3 = (2 * PI * l) / circ_pnt3 / -2;
		glVertex2f(cos(ang3)*raioX3, sin(ang3)*raioY3);
	}
	glEnd();

	//parte vermelha
	GLfloat circ_pnt2 = 500;
	GLfloat ang2, raioX2 = 0.5f, raioY2 = 0.5f;

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int j = 0; j < circ_pnt2; j++) {
		ang2 = (2 * PI * j) / circ_pnt / -2;
		glVertex2f(cos(ang2)*raioX2, sin(ang2)*raioY2);
	}
	glEnd();


}
void seed() {

}



void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.56, 1.76, 2.22, 1);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	draw();	
	seed();
	
	glFlush(); // executa o desenho
}
 