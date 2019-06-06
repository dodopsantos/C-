/// Pong
#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>
#define janela_altura 600 
#define janela_largura 800 
#define PI 3.1416
#define VK_W 0x57
#define VK_S 0x53

//Funções
void keyboard();
void anima(int valor);
void update(int valor); int interval = 1000 / 60;

//Movimento da bola
float tx, ty = 0.0;
float cateto1, cateto2, distancia;
float xTep = 4;
float yTep = 1;

//Posições dos jogadores
float p1X = -380, p1Y = 50, p1Comp = 20, p1Alt = -100;
float p2X = 380, p2Y = 50, p2Comp = -20, p2Alt = -100;

//Posições das paredes
float Tx = -400, Ty = 280, Tcomp = 800, Talt = -20;
float Cx = -400, Cy = -280, Ccomp = 800, Calt = 20;

//Placar
int scoreP1 = 0, scoreP2 = 0;


//Colisões
bool colisaoP1(float Ax, float Ay, float Bx, float By, float Bcompr, float Baltu) {

	if (Ay > By) return false;
	else if (Ay < By + Baltu) return false;
	else if (Ax > Bx + Bcompr) return false;

	return true;
}
bool colisaoP2(float Ax, float Ay, float Bx, float By, float Bcompr, float Baltu) {

	if (Ay > By) return false;
	else if (Ay < By + Baltu) return false;
	else if (Ax < Bx + Bcompr) return false;

	return true;
}
bool colisaoTeto(float Ax, float Ay, float Bx, float By, float Bcompr, float Baltu) {

	if (Ay < By + Baltu) return false;

	return true;
}
bool colisaoChao(float Ax, float Ay, float Bx, float By, float Bcompr, float Baltu) {

	if (Ay > By + Baltu) return false;

	return true;
}

int teste = 0;

void display(void);
void tela(GLsizei W, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("Pong"); // cria janela 

							  //glutFullscreen(); 
	glutTimerFunc(150, anima, 1);
	glutTimerFunc(250, update, 1);
	//glutKeyboardFunc(&keyboard); // chama teclado 
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
	cateto1 = tx;
	cateto2 = ty;

	distancia = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));

	if (colisaoP1(cateto1, cateto2, p1X, p1Y, p1Comp, p1Alt) == true)
	{
		xTep = -xTep;
		yTep = yTep;
	}
	if (colisaoP2(cateto1, cateto2, p2X, p2Y, p2Comp, p2Alt) == true)
	{
		xTep = -xTep;
		yTep = yTep;
	}
	if (colisaoTeto(cateto1, cateto2, Tx, Ty, Tcomp, Talt) == true)
	{
		xTep = xTep;
		yTep = -yTep;
	}
	if (colisaoChao(cateto1, cateto2, Cx, Cy, Ccomp, Calt) == true)
	{
		xTep = xTep;
		yTep = -yTep;
	}
	if (cateto1 > 390)
	{
		tx = 0;
		ty = 0;
		scoreP2++;
	}
	else if (cateto1 < -390)
	{
		tx = 0;
		ty = 0;
		scoreP1++;
	}
	else if (scoreP1 == 3 || scoreP2 == 3)
	{
		Sleep(1000);
		exit(0);
	}

	ty += yTep;
	tx += xTep;

	printf("Distancia: %f  -   Cateto X: %f   -   Cateto Y: %f", distancia, cateto1, cateto2);
	glutPostRedisplay();
	glutTimerFunc(15, anima, 2);

}

void keyboard() {
	// Movimento do jogador 1
	if (GetAsyncKeyState(VK_W)) if (p1Y < 260) p1Y += 10;
	if (GetAsyncKeyState(VK_S)) if (p1Y > -160) p1Y -= 10;

	// Movimento do jogador 2
	if (GetAsyncKeyState(VK_UP)) if (p2Y < 260) p2Y += 10;
	if (GetAsyncKeyState(VK_DOWN)) if (p2Y > -160) p2Y -= 10;
}

void cenario() {

	//Barra superior
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(Tx, Ty);
	glVertex2f(Tx + Tcomp, Ty);
	glVertex2f(Tx + Tcomp, Ty + Talt);
	glVertex2f(Tx, Ty + Talt);
	glEnd();

	//Barra inferior
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(Cx, Cy);
	glVertex2f(Cx + Ccomp, Cy);
	glVertex2f(Cx + Ccomp, Cy + Calt);
	glVertex2f(Cx, Cy + Calt);
	glEnd();

	//Tracejado horizontal
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, 280);
	glVertex2f(5, 280);
	glVertex2f(5, 220);
	glVertex2f(-5, 220);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, 200);
	glVertex2f(5, 200);
	glVertex2f(5, 140);
	glVertex2f(-5, 140);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, 120);
	glVertex2f(5, 120);
	glVertex2f(5, 60);
	glVertex2f(-5, 60);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, 40);
	glVertex2f(5, 40);
	glVertex2f(5, -20);
	glVertex2f(-5, -20);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, -40);
	glVertex2f(5, -40);
	glVertex2f(5, -100);
	glVertex2f(-5, -100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, -120);
	glVertex2f(5, -120);
	glVertex2f(5, -180);
	glVertex2f(-5, -180);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-5, -200);
	glVertex2f(5, -200);
	glVertex2f(5, -260);
	glVertex2f(-5, -260);
	glEnd();
}
void player1() {

	//Jogador Esquerda
	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(p1X, p1Y);
	glVertex2f(p1X + p1Comp, p1Y);
	glVertex2f(p1X + p1Comp, p1Y + p1Alt);
	glVertex2f(p1X, p1Y + p1Alt);
	glEnd();

	glPopMatrix();
}
void player2() {

	//Jogador Direita
	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(p2X, p2Y);
	glVertex2f(p2X + p2Comp, p2Y);
	glVertex2f(p2X + p2Comp, p2Y + p2Alt);
	glVertex2f(p2X, p2Y + p2Alt);
	glEnd();

	glPopMatrix();
}
void bola() {

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

}
void placarP1() {

	if (scoreP1 == 0)
	{
		glBegin(GL_LINE_LOOP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 170);
		glVertex2f(50, 170);
		glEnd();
	}
	else if (scoreP1 == 1)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(60, 200);
		glVertex2f(80, 230);
		glVertex2f(80, 170);
		glEnd();
	}
	else if (scoreP1 == 2)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 200);
		glVertex2f(50, 200);
		glVertex2f(50, 170);
		glVertex2f(80, 170);
		glEnd();
	}
	else if (scoreP1 == 3)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 200);
		glVertex2f(50, 200);
		glVertex2f(80, 200);
		glVertex2f(80, 170);
		glVertex2f(50, 170);
		glEnd();
	}
}
void placarP2() {

	if (scoreP2 == 0)
	{
		glBegin(GL_LINE_LOOP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 170);
		glVertex2f(-80, 170);
		glEnd();
	}
	else if (scoreP2 == 1)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(-80, 200);
		glVertex2f(-60, 230);
		glVertex2f(-60, 170);
		glEnd();
	}
	else if (scoreP2 == 2)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 200);
		glVertex2f(-80, 200);
		glVertex2f(-80, 170);
		glVertex2f(-50, 170);
		glEnd();
	}
	else if (scoreP2 == 3)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 200);
		glVertex2f(-80, 200);
		glVertex2f(-50, 200);
		glVertex2f(-50, 170);
		glVertex2f(-80, 170);
		glEnd();
	}
}
void desenhar()
{
	cenario();
	player1();
	player2();
	bola();
	placarP1();
	placarP2();

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


