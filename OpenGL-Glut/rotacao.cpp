#include <stdlib.h>
#include<stdio.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);
float rotacao = 1;
float trans = 1;
float zoom = 1;


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(1000, 500);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(10, 300); // posicao inicial da janela

	glutCreateWindow("GLUT Test wagner---- exercicio de glut");   /// cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(&resize); // 

	glutDisplayFunc(display);

	glutMainLoop();

	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
	printf("\ntecla %c\n", key);
	printf("\n\nDigite 1 para esquerda, 2 para direita: ");
	printf("\ntecla %c\n", key);
	printf("\nNo Mouse estava em %d x %d\n",x,y);
	
	switch (key)
	{
	case 'a':
		rotacao = rotacao + 1;
		printf("\n O valor de rotacao e %.2\n", rotacao);
	
	case 'b':
		rotacao = rotacao - 1;
		printf("\n O valor de rotacao e %.2\n", rotacao);

	case '1':
		zoom = zoom + 0.05;
		printf("\n O valor de zoom e %.2\n", zoom);

	case '2':
		zoom = zoom - 0.05;
		printf("\n O valor de zoom e %.2\n", zoom);

	case 'e':
		trans = trans + 1;
		printf("\n O valor de translacao e %.2\n", trans);

	case 'd':
		trans = trans - 1;
		printf("\n O valor de translacao e %.2\n", trans);
	}

	glutPostRedisplay();
}

void resize(GLsizei w, GLsizei h)
{

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

							 // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
	{
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else
	{
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);


}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.56, 1.76, 2.22, 1);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glRotated(rotacao, 0, 0, 1);

	//Quadrado	
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(125, 125);
	glVertex2f(175, 125);
	glVertex2f(175, 75);
	glVertex2f(125, 75);
	glEnd();
	
	glRotated(-rotacao, 0, 0, 1);

	glTranslatef(trans, trans, 0);	

	//Triangulo
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(100, 150);
	glVertex2f(150, 150);
	glVertex2f(125, 190);
	glEnd();

	glTranslatef(1,1, 0);
	
	glScalef(zoom, zoom, 0);	

	//Retangulo
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex2f(250, 190);
	glVertex2f(300, 190);
	glVertex2f(300, 75);
	glVertex2f(250, 75);
	glEnd();	
	
	glScalef(1, 1, 0);
	
	glFlush(); // executa o desenho
}