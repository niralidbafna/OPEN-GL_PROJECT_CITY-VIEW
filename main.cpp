#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
float light_r = 1, light_g = 1, light_b = 1;
float bg_r = 0, bg_g = 0.8, bg_b = 1.5; //bg down
float bg_r2 = 1, bg_g2 = 1, bg_b2 = 0; //bg up
float star_r = 1, star_g = 1, star_b = 0;
float school_dr = 184, school_dg = 88, school_db = 64;
float grass_g = 0.5, ps = 1;
GLint xr = 0, yr = 0;
float carspeed = 0.25;
int SCENE_ID = 1;
#define PI 3.141592653589

GLint cx1 = 115, cy1 = 110, cx4 = 115, cy4 = 130;//carlight co-ordinates
struct Point {
	GLint x;
	GLint y;
};
float  counter = 900, counterman = 650;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}
void wheel(int x, int y)
{
	float th;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 18 * cos(th), y + 18 * sin(th));
	}

	glEnd();

	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 18 * cos(th), y + 18 * sin(th));
	}

	glEnd();

	glPolygonMode(GL_FRONT, GL_FILL);

}
void moon(int x, int y)
{
	float th;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + xr * cos(th), y + yr * sin(th));
	}

	glEnd();
}
void carlight()
{
	glColor3f(light_r, light_g, light_b);
	glBegin(GL_POLYGON);
	glVertex2i(cx1, cy1);
	glVertex2i(120, 115);
	glVertex2i(120, 125);
	glVertex2i(cx4, cy4);
	glEnd();
}
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = start_angle; i < end_angle; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
	glPushMatrix();

	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = 0; i < 360; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}
void man()
{
	glPushMatrix();
	glLoadIdentity();
	counterman = counterman - 0.15;
	glColor3ub(37, 64, 154);
	glTranslated(counterman, 0, 0.0);

	//shoe extension
	glBegin(GL_POLYGON);
	glColor3ub(234, 10, 10);
	glVertex2f(120, 120);
	glVertex2f(127, 120);
	glVertex2f(127, 132);
	glVertex2f(120, 132);
	glEnd();

	//shoe extension
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2f(120, 120);
	glVertex2f(128, 120);
	glVertex2f(128, 129);
	glVertex2f(120, 129);
	glEnd();

	//shoes
	drawSemiCircle(120, 120,
		1, 1,
		0, 0, 0,
		8,
		-90, 91);



	// Pants
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 200);
	glVertex2f(118, 132);
	glVertex2f(129, 132);
	glVertex2f(129, 160);
	glVertex2f(118, 160);
	glEnd();

	// Shirt
	glBegin(GL_POLYGON);
	glColor3ub(234, 10, 10);
	glVertex2f(116, 160);
	glVertex2f(131, 160);
	glVertex2f(129, 190);
	glVertex2f(118, 190);
	glEnd();

	// Bag
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex2f(130, 164);
	glVertex2f(137, 164);
	glVertex2f(135, 186);
	glVertex2f(129, 186);
	glEnd();

	// Hair

	drawSemiCircle(126, 199,
		1, 1,
		234, 10, 10,
		11,
		-80, 180);

	// Head
	drawCircle(123, 199,
		232, 190, 123,
		1, 1.2,
		8);


	// Eye
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3ub(0, 0, 0);
	glVertex2f(121, 201);
	glEnd();
	glPointSize(1);

	// Lips
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3ub(0, 0, 0);
	glVertex2f(115, 196);
	glVertex2f(119, 194);
	glVertex2f(123, 195);
	glEnd();
	glPointSize(1);
	//out of house initially =650
	if (counterman > 350 && counterman < 400) //get inside school
		counterman = 1300;
	else if (counterman > 1100 && counterman < 1200) //get out of school
		counterman = 350;
	else if (counterman < 50 && counterman>45) //get inside theatre
		counterman = 1500;
	else if (counterman < 1400 && counterman>1300) //get outside theatre
		counterman = 45;
	else if (counterman < -150) //walk on road
		counterman = 1000;
	else if (counterman > 651 && counterman < 655) //get inside house
		counterman = 1700;
	else if (counterman > 1500 && counterman < 1600) //get outside house
		counterman = 650;

	glPopMatrix();

}
void car()
{
	//Bottom Part
	glLoadIdentity();
	counter = counter - carspeed;
	glColor3ub(37, 64, 154);
	glTranslated(counter, -60, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(120, 100);
	glVertex2f(370, 100);
	glVertex2f(370, 140);
	glVertex2f(120, 140);
	glEnd();

	//Top Part
	glBegin(GL_POLYGON);
	glVertex2f(150, 140);
	glVertex2f(350, 140);
	glVertex2f(300, 180);
	glVertex2f(200, 180);
	glEnd();

	//window1
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(175, 145);
	glVertex2i(240, 145);
	glVertex2i(240, 172);
	glVertex2i(202, 172);
	glEnd();


	carlight();

	//window2
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(255, 145);
	glVertex2i(333, 145);
	glVertex2i(300, 172);
	glVertex2i(255, 172);
	glEnd();

	//door
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(247, 105);
	glVertex2i(247, 175);
	glEnd();

	//door handle
	glBegin(GL_LINES);
	glVertex2i(233, 130);
	glVertex2i(244, 130);
	glEnd();

	wheel(190, 100);
	wheel(305, 100);

	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2i(190, 100);
	glVertex2i(305, 100);
	glEnd();

	if (counter < -400)
		counter = 1100;



}
void print(int x, int y, float r, float g, float b, const char* str, void* font)
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(str);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, str[i]);
	}
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
void school()
{
	//building
	glColor3ub(school_dr, school_dg, school_db);
	glBegin(GL_POLYGON);
	glVertex2i(320, 140);
	glVertex2i(680, 140);
	glColor3ub(241, 130, 94);
	glVertex2i(680, 350);
	glVertex2i(320, 350);
	glEnd();

	//building border
	glLineWidth(0.1);
	glBegin(GL_LINE_LOOP);
	glColor3ub(194, 88, 64);
	glVertex2f(320, 140);
	glVertex2f(680, 140);
	glVertex2f(680, 350);
	glVertex2f(320, 350);
	glEnd();


	//board
	glBegin(GL_POLYGON);
	glColor3ub(40, 34, 34);
	glVertex2f(420, 330);
	glVertex2f(590, 330);
	glVertex2f(590, 380);
	glVertex2f(420, 380);
	glEnd();
	print(430, 345, 255, 255, 255, "RNS SCHOOL", GLUT_BITMAP_TIMES_ROMAN_24);

	//board border
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(420, 330);
	glVertex2f(590, 330);
	glVertex2f(590, 380);
	glVertex2f(420, 380);
	glEnd();

	//bulb
	glColor3f(light_r, light_g, light_b);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(419, 330);
	glVertex2f(591, 330);
	glVertex2f(591, 380);
	glVertex2f(419, 380);

	glEnd();
	//school door
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(420, 140);
	glVertex2f(580, 140);
	glVertex2f(580, 240);
	glVertex2f(420, 240);
	glEnd();

	//school door border
	glColor3ub(100, 99, 97);
	glBegin(GL_LINE_LOOP);
	glVertex2f(420, 140);
	glVertex2f(580, 140);
	glVertex2f(580, 240);
	glVertex2f(420, 240);
	glEnd();

	// School Door Divider
	glBegin(GL_LINES);
	glColor3ub(100, 99, 97);
	glVertex2f(500, 140);
	glVertex2f(500, 240);
	glEnd();

	//windows
	int p = 340, q = 260;
	for (int j = 0; j < 4; j++) {
		glBegin(GL_POLYGON);
		glColor3ub(59, 91, 132);
		glVertex2f(p, q);
		glVertex2f(p + 50, q);
		glVertex2f(p + 50, q + 50);
		glColor3ub(97, 131, 159);
		glVertex2f(p, q + 50);
		glEnd();
		p += 90;
	}

	p = 340;
	q -= 80;
	for (int j = 0; j < 2; j++) {
		glBegin(GL_POLYGON);
		glColor3ub(59, 91, 132);
		glVertex2f(p, q);
		glVertex2f(p + 50, q);
		glVertex2f(p + 50, q + 50);
		glColor3ub(97, 131, 159);
		glVertex2f(p, q + 50);
		glEnd();
		p += 270;
	}

	//windows border
	glColor3ub(70, 100, 145);
	p = 340; q = 260;
	for (int j = 0; j < 4; j++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(p, q);
		glVertex2f(p + 50, q);
		glVertex2f(p + 50, q + 50);
		glVertex2f(p, q + 50);
		glEnd();
		p += 90;
	}

	p = 340;
	q -= 80;
	for (int j = 0; j < 2; j++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(p, q);
		glVertex2f(p + 50, q);
		glVertex2f(p + 50, q + 50);
		glVertex2f(p, q + 50);
		glEnd();
		p += 270;
	}
	glFlush();

}
void theatre()
{
	//bottom
	glColor3ub(160, 27, 39);
	glBegin(GL_POLYGON);
	glVertex2f(20, 140);
	glVertex2f(300, 140);
	glVertex2f(300, 260);
	glColor3ub(197, 57, 69);
	glVertex2f(20, 260);
	glEnd();

	//inner bottom
	glBegin(GL_POLYGON);
	glVertex2f(40, 140);
	glVertex2f(280, 140);
	glVertex2f(280, 230);
	glVertex2f(40, 230);
	glEnd();

	// door
	glColor3ub(183, 184, 188);
	glBegin(GL_POLYGON);
	glVertex2f(100, 140);
	glVertex2f(220, 140);
	glVertex2f(220, 200);
	glVertex2f(100, 200);
	glEnd();

	//door divider
	glBegin(GL_LINES);
	glColor3ub(100, 99, 97);
	glVertex2f(160, 140);
	glVertex2f(160, 200);
	glEnd();

	//door border
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, 140);
	glVertex2f(220, 140);
	glVertex2f(220, 200);
	glVertex2f(100, 200);
	glEnd();

	//bottom border
	glColor3ub(155, 22, 34);
	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 140);
	glVertex2f(300, 140);
	glVertex2f(300, 260);
	glVertex2f(20, 260);
	glEnd();

	//rods
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(45, 260);
	glVertex2i(45, 280);
	glVertex2i(275, 260);
	glVertex2i(275, 280);
	glEnd();
	glLineWidth(1);

	//top
	glBegin(GL_POLYGON);
	glVertex2f(10, 280);
	glVertex2f(310, 280);
	glVertex2f(310, 330);
	glVertex2f(10, 330);
	glEnd();

	//THEATRE
	print(80, 295, 255, 255, 255, "CINEMA HALL", GLUT_BITMAP_TIMES_ROMAN_24);

	//bulbs
	glColor3f(light_r, light_g, light_b);
	glPointSize(4);
	glBegin(GL_POINTS);
	//left
	int p = 10, q = 280;
	for (int i = 0; i < 5; i++) {
		glVertex2i(p, q);
		q += 12;
	}

	//right
	p = 310; q = 280;
	for (int i = 0; i < 5; i++) {
		glVertex2i(p, q);
		q += 12;
	}

	//top
	p = 10; q = 330;
	for (int i = 0; i < 26; i++) {
		glVertex2i(p, q);
		p += 12;
	}

	//bottom
	p = 10; q = 280;
	for (int i = 0; i < 26; i++) {
		glVertex2i(p, q);
		p += 12;
	}
	glEnd();
	glFlush();

}
void draw_circle(Point pC, GLfloat radius) {
	GLfloat step = 1 / radius;
	GLfloat x, y;
	glColor3f(light_r, light_g, light_b);
	glPointSize(1);
	glBegin(GL_POINTS);

	for (GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}
void house()
{
	//house
	glColor3ub(184, 100, 49);
	glBegin(GL_POLYGON);
	glVertex2i(720, 140);
	glVertex2i(980, 140);
	glVertex2i(980, 220);
	glVertex2i(820, 220);
	glVertex2i(820, 300);
	glColor3ub(240, 152, 94);
	glVertex2i(720, 300);
	glVertex2i(720, 220);
	glEnd();

	//border
	glColor3ub(38, 36, 35);
	glBegin(GL_LINE_LOOP);
	glVertex2i(720, 140);
	glVertex2i(980, 140);
	glVertex2i(980, 220);
	glVertex2i(820, 220);
	glVertex2i(820, 300);
	glVertex2i(720, 300);
	glVertex2i(720, 220);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(720, 220);
	glVertex2i(820, 220);
	glVertex2i(820, 140);
	glEnd();


	//roof 1
	glColor3ub(94, 52, 26);
	glBegin(GL_POLYGON);
	glVertex2i(710, 300);
	glVertex2i(830, 300);
	glColor3ub(38, 36, 35);
	glVertex2i(770, 380);
	glEnd();

	Point p = { 770,330 };
	draw_circle(p, 10);
	//roof 2
	glColor3ub(94, 52, 26);
	glBegin(GL_POLYGON);
	glVertex2i(820, 221);
	glVertex2i(990, 221);
	glColor3ub(38, 36, 35);
	glVertex2i(920, 285);
	glVertex2i(820, 285);
	glEnd();

	print(830, 265, 1, 1, 1, "Press ' S ' for stop", GLUT_BITMAP_HELVETICA_10);
	print(830, 252, 1, 1, 1, "Press ' R ' for resume", GLUT_BITMAP_HELVETICA_10);
	print(830, 239, 1, 1, 1, "Press ' N ' for night mode", GLUT_BITMAP_HELVETICA_10);
	print(830, 226, 1, 1, 1, "Press ' D ' for day mode", GLUT_BITMAP_HELVETICA_10);

	//roof 1 border
	glColor3ub(38, 36, 35);
	glBegin(GL_LINE_LOOP);
	glVertex2i(710, 300);
	glVertex2i(830, 300);
	glVertex2i(770, 380);
	glEnd();

	//roof 2 border
	glColor3ub(38, 36, 35);
	glBegin(GL_LINE_LOOP);
	glVertex2i(820, 220);
	glVertex2i(990, 220);
	glVertex2i(920, 285);
	glVertex2i(820, 285);
	glEnd();
	//window 1
	glBegin(GL_POLYGON);
	glColor3ub(75, 128, 243);
	glVertex2f(750, 240);
	glVertex2f(790, 240);
	glVertex2f(790, 280);
	glColor3ub(97, 131, 159);
	glVertex2f(750, 280);
	glEnd();

	//window 1 border
	glBegin(GL_LINE_LOOP);
	glColor3ub(70, 100, 145);
	glVertex2f(750, 240);
	glVertex2f(790, 240);
	glVertex2f(790, 280);
	glVertex2f(750, 280);
	glEnd();

	//door
	glBegin(GL_POLYGON);
	glColor3ub(191, 185, 181);
	glVertex2f(750, 141);
	glVertex2f(790, 141);
	glVertex2f(790, 200);
	glVertex2f(750, 200);
	glEnd();

	//door divider
	glBegin(GL_LINES);
	glColor3ub(100, 99, 97);
	glVertex2f(770, 141);
	glVertex2f(770, 200);
	glEnd();

	//door border
	glBegin(GL_LINE_LOOP);
	glColor3ub(100, 99, 97);
	glVertex2f(750, 141);
	glVertex2f(790, 141);
	glVertex2f(790, 200);
	glVertex2f(750, 200);
	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3ub(75, 128, 243);
	glVertex2f(850, 160);
	glVertex2f(950, 160);
	glVertex2f(950, 200);
	glColor3ub(97, 131, 159);
	glVertex2f(850, 200);
	glEnd();

	//window 2 border
	glBegin(GL_LINE_LOOP);
	glColor3ub(70, 100, 145);
	glVertex2f(850, 160);
	glVertex2f(950, 160);
	glVertex2f(950, 200);
	glVertex2f(850, 200);
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
		glPointSize(ps);
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
		q = p + 70;
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
void cardisplay()
{
	//Push and pop matrix for separating circle object from Background
	glPushMatrix();
	car();
	glutSwapBuffers();
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
}
void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	background();
	stars();
	moon(850, 540);
	road();
	grass();
	school();
	house();
	theatre();
	man();
	streetlight();
	cardisplay();

	glutPostRedisplay();
}
void introduction()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	print(320, 500, 1, 1, 1, "RNS INSTITUTE OF TECHNOLOGY", GLUT_BITMAP_TIMES_ROMAN_24);
	print(370, 470, 1, 1, 1, "CHANNASANDRA, BANGALORE", GLUT_BITMAP_HELVETICA_18);
	print(370, 410, 1, 0, 0, "CITY VIEW OPENGL PROJECT", GLUT_BITMAP_HELVETICA_18);
	print(415, 373, 1, 1, 1, "GUIDE: MRS. MAMATHA JAJUR", GLUT_BITMAP_HELVETICA_12);
	print(375, 320, 0, 0, 1, "NIRALI D BAFNA 1RN19CS088", GLUT_BITMAP_HELVETICA_18);
	print(385, 290, 0, 0, 1, "MEGHANA GN 1RN19CS078", GLUT_BITMAP_HELVETICA_18);

	print(50, 215, 1, 1, 1, "INSTRUCTIONS: ", GLUT_BITMAP_HELVETICA_12);
	print(50, 190, 1, 1, 1, "-> Press ' r ' to enter into the scene", GLUT_BITMAP_HELVETICA_12);
	print(50, 175, 1, 1, 1, "-> Press ' UP ARROW ' to increase car speed", GLUT_BITMAP_HELVETICA_12);
	print(50, 160, 1, 1, 1, "-> Press ' DOWN ARROW ' to decrease car speed", GLUT_BITMAP_HELVETICA_12);
	print(50, 145, 1, 1, 1, "-> Press ' LEFT ARROW ' for normal car speed", GLUT_BITMAP_HELVETICA_12);
	print(50, 130, 1, 1, 1, "-> Press ' RIGHT ARROW ' to reverse car", GLUT_BITMAP_HELVETICA_12);

	glFlush();
	glutSwapBuffers();s
	glLoadIdentity();
}
void stop()
{
	glClearColor(0, 0, 0, 0);
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	switch (SCENE_ID)
	{
	case 1: introduction();
		break;

	case 2: scene();
		break;

	case 3: stop();
		break;
	}

}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'n') {
		bg_r = 0.1, bg_g = 0.1, bg_b = 0.4;
		light_r = 1; light_g = 1; light_b = 0;
		star_r = 1; star_g = 1; star_b = 1;
		grass_g = 0.2;
		bg_r2 = 0; bg_g2 = 0; bg_b2 = 0;
		school_dr = 200; school_dg = 88; school_db = 64;
		cx1 = 90; cy1 = 100; cx4 = 90; cy4 = 140;
		ps = 2; //point size
		xr = 27; yr = 27; //moon x_radius, y_radius
	}
	else if (key == 'd') {
		bg_r = 0; bg_g = 0.8; bg_b = 1.5; //bg down
		light_r = 1; light_g = 1; light_b = 1;
		star_r = 1; star_g = 1; star_b = 0;
		grass_g = 0.5;
		bg_r2 = 1; bg_g2 = 1; bg_b2 = 0; //bg up
		school_dr = 184; school_dg = 88; school_db = 64;
		cx1 = 115; cy1 = 110; cx4 = 115; cy4 = 130;
		ps = 1;
		xr = 0.1; yr = 0.1;

	}
	else if (key == 'r')
	{
		SCENE_ID = 2;
	}
	else if (key == 's')
	{
		SCENE_ID = 3;
	}

	glutPostRedisplay();
	glFlush();

}
void special(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		carspeed = 0.5;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		carspeed = 0.1;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		carspeed = 0.25;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		carspeed = -0.25;
	}
	glutPostRedisplay();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 0);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("CITY VIEW");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMainLoop();
	return 0;
}
