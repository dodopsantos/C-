#include <stdlib.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


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
	glClearColor(0.56, 1.76, 2.22, 1);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	//pier
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(200.0, 80);
	glVertex2f(400, 80);
	glVertex2f(400, 70.0);
	glVertex2f(200, 70);
	glEnd();

	//Rampa
	glBegin(GL_TRIANGLES);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(400, 70);
	glVertex2f(430, 70);
	glVertex2f(400, 80);
	glEnd();

	//pilar1
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(200.0, 80);
	glVertex2f(210, 80);
	glVertex2f(210, 0);
	glVertex2f(200, 0);
	glEnd();

	//pilar2
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(250.0, 80);
	glVertex2f(260, 80);
	glVertex2f(260, 0);
	glVertex2f(250, 0);
	glEnd();

	//pilar3
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(300.0, 80);
	glVertex2f(310, 80);
	glVertex2f(310, 0);
	glVertex2f(300, 0);
	glEnd();

	//pilar4
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(350.0, 80);
	glVertex2f(360, 80);
	glVertex2f(360, 0);
	glVertex2f(350, 0);
	glEnd();

	//sup-corrimão1
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(203.0, 80);
	glVertex2f(206, 80);
	glVertex2f(206, 100);
	glVertex2f(203, 100);
	glEnd();

	//sup-corrimão2
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(253.0, 80);
	glVertex2f(256, 80);
	glVertex2f(256, 100);
	glVertex2f(253, 100);
	glEnd();

	//sup-corrimão3
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(303.0, 80);
	glVertex2f(306, 80);
	glVertex2f(306, 100);
	glVertex2f(303, 100);
	glEnd();

	//terra
	glBegin(GL_QUADS);
	glColor3f(0.62, 0.32, 0.17);
	glVertex2f(400.0, 70);
	glVertex2f(500, 70);
	glVertex2f(500, 0);
	glVertex2f(400, 0);
	glEnd();

	//sup-corrimão4
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(353.0, 80);
	glVertex2f(356, 80);
	glVertex2f(356, 100);
	glVertex2f(353, 100);
	glEnd();

	//sup-corrimão5
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(396, 80);
	glVertex2f(399, 80);
	glVertex2f(399, 100);
	glVertex2f(396, 100);
	glEnd();

	//corrimão
	glBegin(GL_QUADS);
	glColor3f(0.72, 0.52, 0.04);
	glVertex2f(200.0, 95);
	glVertex2f(400, 95);
	glVertex2f(400, 100.0);
	glVertex2f(200, 100);
	glEnd();

	//grama
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(400.0, 70);
	glVertex2f(500, 70);
	glVertex2f(500, 55);
	glVertex2f(400, 55);
	glEnd();

	//Arvore-tronco
	glBegin(GL_QUADS);
	glColor3f(0.24, 0.04, 0.01);
	glVertex2f(460.0, 150);
	glVertex2f(485, 150);
	glVertex2f(485, 70);
	glVertex2f(460, 70);
	glEnd();

	//Arvore-folha
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(425.0, 200);
	glVertex2f(500, 200);
	glVertex2f(500, 135);
	glVertex2f(425, 135);
	glEnd();

	//Canoa
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.38, 0.28);
	glVertex2f(50, 80);
	glVertex2f(150, 80);
	glVertex2f(140, 60);
	glVertex2f(60, 60);
	glEnd();

	//Canoa-pilar
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.38, 0.28);
	glVertex2f(99, 120);
	glVertex2f(105, 120);
	glVertex2f(105, 60);
	glVertex2f(99, 60);
	glEnd();

	//Canoa-bandeira
	glBegin(GL_TRIANGLES);
	glColor3f(0.62, 0.10, 0.10);
	glVertex2f(107, 120);
	glVertex2f(107, 90);
	glVertex2f(142, 105);
	glEnd();

	//mar
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex2f(0, 65);
	glVertex2f(400, 65);
	glVertex2f(400, 0);
	glVertex2f(0, 0);
	glEnd();

	//passaro1
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(230.0, 205);
	glVertex2f(240, 195);
	glVertex2f(255, 205);
	glVertex2f(239, 190);
	glEnd();

	//passaro2
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(200.0, 225);
	glVertex2f(210, 215);
	glVertex2f(225, 225);
	glVertex2f(209, 210);
	glEnd();



	glFlush(); // executa o desenho
}