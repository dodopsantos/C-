/// colisao de quadrados 
#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>
#define janela_altura 600 
#define janela_largura 800 
#define PI 3.1416
float trans = 100;
void keyboard(unsigned char key, int x, int y);
float cateto1, cateto2, distancia;
void anima(int valor);
float tx, ty = 0.0;
float xTep = 4;
float rot = 0;
float mov = 4;
float mov1 = 0;
float angulo = 45.0f;
int r = 237, g = 119, b = 40;

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
	glutCreateWindow("Aquario"); // cria janela 

	//glutFullscreen(); 
	glutTimerFunc(150, anima, 1);
	glutKeyboardFunc(&keyboard); // chama teclado 
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 
	return(0);
}

void anima(int valor) {
	cateto1 = tx;
	cateto2 = ty;

	distancia = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));

	if (distancia >= 170) {
		xTep = -xTep;

		if (angulo == 45.0f)
		{
			angulo = -135.0f;
		}
		else
		{
			angulo = 45.0f;
		}

		mov = -mov;
	}

	rot = angulo;
	tx += xTep;
	ty += mov;

	printf("aa: %f", distancia);
	glutPostRedisplay();
	glutTimerFunc(50, anima, 2);

}


void keyboard(unsigned char tecla, int x, int y) {

	switch (tecla)
	{

	case '0':
		r = 0;
		g = 0;
		b = 0;
		break;
	case '1':
		r = 62;
		g = 127;
		b = 232;
		break;

	case '2':
		r = 155;
		g = 23;
		b = 62;
		break;
	case '3':
		r = 237;
		g = 119;
		b = 40;
		break;
	}

	glutPostRedisplay();
}

void peixe() {
	//glScaled(1, -1, 1);
	glTranslatef(-tx, -ty, 0);
	glRotated(rot, 0, 0, 1);

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 75.0f, raioY = 40.0f;

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glColor3ub(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY / 3);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(r, g, b);
	glVertex2f(60, 0);
	glVertex2f(130, 45);
	glVertex2f(130, -45);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(r, g, b);
	glVertex2f(-13, 40);
	glVertex2f(35, 80);
	glVertex2f(15, 39);
	glEnd();

	glRotated(180, 180, 0, 1);
	glBegin(GL_TRIANGLES);
	glColor3ub(r, g, b);
	glVertex2f(-13, 40);
	glVertex2f(35, 80);
	glVertex2f(15, 39);
	glEnd();

}
void aquario() {

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 300.0f, raioY = 300.0f;

	glColor3ub(119, 115, 110);
	glLineWidth(35);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	GLfloat ang2, raioX2 = 297.5f, raioY2 = 297.5f;

	glColor3f(0.62f, 0.92f, 0.93f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang2 = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang2)*raioX2, sin(ang2)*raioY2);
	}
	glEnd();


}
void desenhar()
{
	aquario();
	peixe();

}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho 
	glLoadIdentity();
	glClearColor(0.40f, 0.26f, 0.06f, 1);


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