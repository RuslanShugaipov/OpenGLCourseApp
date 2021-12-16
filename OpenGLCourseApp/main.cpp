#include <cstdio>
#include <cstdarg>
#include <cmath>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;
double translate_x = 0;
double translate_y = 0;
double translate_z = -0.3;

void display();
void keyboard(unsigned char key, int x, int y);
void init();
void reset();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(320, 320);
	glutInitWindowPosition(600, 300);
	glutCreateWindow("Cube");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	
	init();
	glutMainLoop();

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, translate_z);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y,0.0, 1.0, 0.0);

	//передн€€ сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	//задн€€ сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	//права€ сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();


	//лева€ сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();


	//верхн€€ сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	//нижн€€ сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		rotate_y += 5;
		break;
	case 'd':
		rotate_y -= 5;
		break;
	case 'w':
		rotate_x += 5;
		break;
	case 's':
		rotate_x -= 5;
		break;
	case 'q':
		translate_z += 0.05;
		break;
	case 'e':
		translate_z -= 0.05;
		break;
	case 'r':
		reset();
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'a':
//		rotate_y += 5;
//		break;
//	case 'd':
//		rotate_y -= 5;
//		break;
//	case 'w':
//		rotate_x += 5;
//		break;
//	case 's':
//		rotate_x -= 5;
//		break;
//	default:
//		break;
//	}
//
//	glutPostRedisplay();
//}

void init()
{
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void reset()
{
	rotate_x = 0;
	rotate_y = 0;
	rotate_z = 0;
	translate_x = 0;
	translate_y = 0;
	translate_z = 0;
}