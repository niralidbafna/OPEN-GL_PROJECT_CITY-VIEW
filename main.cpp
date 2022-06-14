#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
float light_r = 1, light_g = 1, light_b = 1;
float bg_r = 0, bg_g = 0.8, bg_b = 1.5; //bg down
float bg_r2 = 1, bg_g2 = 1, bg_b2 = 0; //bg up
float star_r = 1, star_g = 1, star_b = 0;
float mall_dr = 1, mall_dg = 0.8, mall_db = 0.5;
float grass_g = 0.5;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 600);
}
void streetlight()
{
	//streetlight
	int x = 100; int y = 55;
	int q = 155;
	for (int i = 0; i < 5; i++) {
		//pole
		glColor3f(0.15, 0.05, 0);
		glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + 10, y);
		glVertex2i(x + 10, y + 100);
		glVertex2i(x, y + 100);
		glEnd();

		//bulb
		glColor3f(light_r, light_g, light_b);
		glBegin(GL_POLYGON);
		glVertex2i(x, q);
		glVertex2i(x + 10, q);
		glVertex2i(x + 20, q + 10);
		glVertex2i(x + 5, q + 25);
		glVertex2i(x - 10, q + 10);
		glEnd();

		glColor3f(0, 0, 0);
		glLineWidth(1);
		glBegin(GL_LINE_LOOP);
		glVertex2i(x, q);
		glVertex2i(x + 10, q);
		glVertex2i(x + 20, q + 10);
		glVertex2i(x + 5, q + 25);
		glVertex2i(x - 10, q + 10);
		glEnd();
		x += 200;
	}
	glFlush();
}
void background()
{
	glShadeModel(GL_SMOOTH);
	glColor3f(bg_r, bg_g, bg_b);
	glBegin(GL_POLYGON);
	glVertex2i(0, 140);
	glVertex2i(1000, 140);
	glColor3f(bg_r2, bg_g2, bg_b2);
	glVertex2i(1000, 600);
	glVertex2i(0, 600);
	glEnd();
	glFlush();
}
void mall()
{
	glColor3f(mall_dr, mall_dg, mall_db);
	glBegin(GL_POLYGON);
	glVertex2i(320, 140);
	glVertex2i(680, 140);
	glVertex2i(680, 350);
	glVertex2i(320, 350);
	glEnd();
	glFlush();

}
void stars()
{
	int x, y;
	glColor3f(star_r, star_g, star_b);
	for (int i = 0; i < 300; i++) {
		srand(i + 100);
		x = rand() % 1000;
		y = rand() % 600 + 460;
		glPointSize(2);
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();

	}
	glFlush();

}
void road()
{
	//black road
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(1000, 0);
	glVertex2i(1000, 50);
	glVertex2i(0, 50);
	glEnd();

	//white strips
	int p = 0, q = 70;
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 8; i++) {
		glBegin(GL_POLYGON);
		glVertex2i(p, 23);
		glVertex2i(q, 23);
		glVertex2i(q + 2, 28);
		glVertex2i(p + 2, 28);
		glEnd();
		p = q + 100;
		q = p + 70;;
	}

	//footpath
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 55);
	glVertex2i(0, 55);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2i(0, 55);
	glVertex2i(1000, 55);
	glVertex2i(1000, 80);
	glVertex2i(0, 80);
	glEnd();

	int x = 30, y = 40;
	glColor3f(0.3, 0.3, 0.3);
	glLineWidth(2);
	for (int i = 0; i < 15; i++) {
		glBegin(GL_LINES);
		glVertex2i(x, 55);
		glVertex2i(x + 10, 80);
		glEnd();
		x += 70;
	}
	glFlush();
}
void grass()
{
	glColor3f(0, grass_g, 0);
	
	glBegin(GL_POLYGON);
	glVertex2i(0, 80);
	glVertex2i(1000, 80);
	glVertex2i(1000, 140);
	glVertex2i(0, 140);
	glEnd();
	glFlush();
}
void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	background();
	stars();
	road();
	grass();
	mall();
	streetlight();
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'n') {
		bg_r = 0.1, bg_g = 0.1, bg_b = 0.4;
		light_r = 1; light_g = 1; light_b = 0;
		star_r = 1; star_g = 1; star_b = 1;
		grass_g = 0.2;
		bg_r2 = 0; bg_g2 = 0; bg_b2 = 0;
	}
	else if (key == 'd') {
		bg_r = 0; bg_g = 0.8; bg_b = 1.5; //bg down
		light_r = 1; light_g = 1; light_b = 1;
		star_r = 1; star_g = 1; star_b = 0;
		grass_g = 0.5;
		bg_r2 = 1; bg_g2 = 1; bg_b2 = 0; //bg up
	}
	glutPostRedisplay();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 0);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("CITY VIEW");
	glutDisplayFunc(scene);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}