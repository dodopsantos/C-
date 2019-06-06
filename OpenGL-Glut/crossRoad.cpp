/// Chicken Cross Roads
#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>

#define janela_altura 700 
#define janela_largura 1000 
#define PI 3.1416
#define VK_W 0x57
#define VK_S 0x53

//Functions
void environment();
int stripes(int x);
int lineStripe(int y);
float Car(float tx, float ty);
void fullStripes();
void keyboard();
void player1();
void anima(int valor);
void update(int valor); int interval = 200;
void display(void);
void tela(GLsizei W, GLsizei h);
GLuint LoadTexture(const char * filename);

//Movimento da bola
float tx0 = 500, tx1 = -500, tx2 = 500, tx3 = -500, tx4 = 500, tx5 = -500, tx6 = 500, tx7 = -500, tx8 = 500, tx9 = -500;
float ty0 = -225, ty1 = -175, ty2 = -125, ty3 = -75, ty4 = -25, ty5 = 25, ty6 = 75, ty7 = 125, ty8 = 175, ty9 = 225;
float xTep0 = -4, xTep1 = 8, xTep2 = -12, xTep3 = 16, xTep4 = -5, xTep5 = 9, xTep6 = -13, xTep7 = 17, xTep8 = -6, xTep9 = 20;

//Player
float p1X = -10, p1Y = -285, p1Comp = 20, p1Alt = 20;

//Colision
bool Colision(float Ax, float Ay, float Bx, float By, float Bcompr, float Baltu) {

	if (Ay < By) return false;
	else if (Ay > By + Baltu) return false;
	else if (Ax > Bx + Bcompr) return false;
	else if (Ax < Bx) return false;

	return true;
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("Chicken cross road"); // cria janela 

	//glutFullScreen();
	//glutKeyboardFunc(&keyboard); // chama teclado 
	glutTimerFunc(250, update, 1);
	glutTimerFunc(150, anima, 1);
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 	

	return(0);
}
void update(int value) {

	keyboard();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay();
}
void anima(int valor) {

	if (Colision(tx0, ty0, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx1, ty1, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx2, ty2, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx3, ty3, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx4, ty4, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx5, ty5, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx6, ty6, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx7, ty7, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx8, ty8, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;
	if (Colision(tx9, ty9, p1X, p1Y, p1Comp, p1Alt) == true) p1Y = -285;

	if (tx0 < -490)	tx0 = 500.0f;
	if (tx1 > 490) tx1 = -500.0f;
	if (tx2 < -490)	tx2 = 500.0f;
	if (tx3 > 490) tx3 = -500.0f;
	if (tx4 < -490)	tx4 = 500.0f;
	if (tx5 > 490) tx5 = -500.0f;
	if (tx6 < -490)	tx6 = 500.0f;
	if (tx7 > 490) tx7 = -500.0f;
	if (tx8 < -490)	tx8 = 500.0f;
	if (tx9 > 490) tx9 = -500.0f;

	tx0 += xTep0;
	tx1 += xTep1;
	tx2 += xTep2;
	tx3 += xTep3;
	tx4 += xTep4;
	tx5 += xTep5;
	tx6 += xTep6;
	tx7 += xTep7;
	tx8 += xTep8;
	tx9 += xTep9;

	glutPostRedisplay();
	glutTimerFunc(15, anima, 2);

}
void keyboard() {

	if (GetAsyncKeyState(VK_UP)) if (p1Y < 250) p1Y += 50;
	if (GetAsyncKeyState(VK_DOWN)) if (p1Y > -250) p1Y -= 50;

	if (GetAsyncKeyState(VK_RIGHT)) if (p1X < 450) p1X += 50;
	if (GetAsyncKeyState(VK_LEFT)) if (p1X > -500) p1X -= 50;

}
GLuint LoadTexture(const char * filename)
{

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

#pragma warning(disable:4996)
	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	width = 1024;
	height = 512;
	data = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}
void environment() {

	//Principal road
	glBegin(GL_QUADS);
	glColor3ub(147, 148, 150);
	glVertex2f(-500, -250);
	glVertex2f(-500, 250);
	glVertex2f(500, 250);
	glVertex2f(500, -250);
	glEnd();

	//Top bar
	glBegin(GL_QUADS);
	glColor3ub(173, 175, 178);
	glVertex2f(-500, 253);
	glVertex2f(-500, 297);
	glVertex2f(500, 297);
	glVertex2f(500, 253);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(147, 148, 150);
	glVertex2f(-500, 300);
	glVertex2f(-500, 350);
	glVertex2f(500, 350);
	glVertex2f(500, 300);
	glEnd();

	//Bottom bar
	glBegin(GL_QUADS);
	glColor3ub(173, 175, 178);
	glVertex2f(-500, -253);
	glVertex2f(-500, -297);
	glVertex2f(500, -297);
	glVertex2f(500, -253);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(147, 148, 150);
	glVertex2f(-500, -300);
	glVertex2f(-500, -350);
	glVertex2f(500, -350);
	glVertex2f(500, -300);
	glEnd();
	fullStripes();

}
void fullStripes() {

	lineStripe(0);
	lineStripe(-50);
	lineStripe(-100);
	lineStripe(-150);
	lineStripe(-200);
	lineStripe(-250);
	lineStripe(-300);
	lineStripe(-350);
	lineStripe(-400);

}
int lineStripe(int y) {
	glPushMatrix();
	glTranslated(0, y, 0);

	stripes(0);
	stripes(60);
	stripes(120);
	stripes(180);
	stripes(240);
	stripes(300);
	stripes(360);
	stripes(420);
	stripes(480);
	stripes(540);
	stripes(600);
	stripes(660);
	stripes(720);
	stripes(780);
	stripes(840);
	stripes(900);
	stripes(960);

	glPopMatrix();
	return true;
}
int stripes(int x) {

	glPushMatrix();
	glTranslated(x, 0, 0);

	glBegin(GL_QUADS);
	glColor3ub(173, 175, 178);
	glVertex2f(-470, 200);
	glVertex2f(-470, 205);
	glVertex2f(-440, 205);
	glVertex2f(-440, 200);
	glEnd();

	glPopMatrix();
	return true;
}
void player1() {

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(p1X, p1Y + p1Alt);
	glVertex2f(p1X + p1Comp, p1Y + p1Alt);
	glVertex2f(p1X + p1Comp, p1Y);
	glVertex2f(p1X, p1Y);
	glEnd();

	glPopMatrix();

}
float Car(float tx, float ty) {

	glPushMatrix();

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 10.0f, raioY = 10.0f;

	glTranslatef(tx, ty, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glPopMatrix();
	return true;

}
void display()
{

	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho 
	glLoadIdentity();
	glClearColor(0, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA 
								  // Especificar o local aonde o desenho acontece: bem no centro da janela 
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	// execute o desenho 
	environment();
	player1();

	Car(tx0, ty0);
	Car(tx1, ty1);
	Car(tx2, ty2);
	Car(tx3, ty3);
	Car(tx4, ty4);
	Car(tx5, ty5);
	Car(tx6, ty6);
	Car(tx7, ty7);
	Car(tx8, ty8);
	Car(tx9, ty9);

	/*GLuint texture;
	texture = LoadTexture("blobsheet_0.bmp");
	glBindTexture(GL_TEXTURE_2D, texture);*/

	glFlush();

}
void tela(GLsizei W, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima) 
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}