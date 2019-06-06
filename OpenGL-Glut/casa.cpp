#include <stdlib.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(400, 400);  // tamanho da janela

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
	switch (key)
	{
	case '\x1B':
		exit(EXIT_SUCCESS);
		break;
	}
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
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	//casa
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(50.0, 200);
	glVertex2f(200, 200);
	glVertex2f(200, 70.0);
	glVertex2f(50, 70);
	glEnd();

	//telhado
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(50,200);
	glVertex2f(200,200);
	glVertex2f(125,240);	
	glEnd();

	//porta
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex2f(50.0, 105);
	glVertex2f(85, 105);
	glVertex2f(85, 0);
	glVertex2f(50, 0);
	glEnd();

	//circulo
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(6.0);
	glPointSize(8.0f);
	glBegin(GL_POINTS);	
	glColor3f(0, 0, 0);
	glVertex2i(70, 90);
	
	glEnd();

	//grama
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(0, 70);
	glVertex2f(250, 70);
	glVertex2f(250, 0);
	glVertex2f(0, 0);
	glEnd();

	//janela
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);	
	glVertex2f(100.0, 160);
	glColor3f(0, 0, 1);
	glVertex2f(125, 160);
	glVertex2f(125, 135);
	glColor3f(1, 1, 1);
	glVertex2f(100, 135);
	glEnd();


	glFlush(); // executa o desenho
}