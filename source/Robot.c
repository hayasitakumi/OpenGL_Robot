/* List: p3-robot.c
* Robot arm with two links and two joints.
* Examination of world-local coordinates, modeling transfomation and
* operation of matrix stack.
*/
#include <stdlib.h>
#include <GL/glut.h>

static int shoulder_right = 0, elbow_right = 0, hand_right = 0;
static int shoulder_left = 0, elbow_left = 0, hand_left = 0;
static int body = 0;
static int neck = 0, head = 0, shoulder_ball = 0;
static int camera_x = 0;

void myInit(char* progname)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 1.0, 0.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//body
	glPushMatrix();
	/* 1st link */
	glRotated((double)body, 0.0, 0.0, 1.0);
	glPushMatrix();
	glScaled(2.0, 5.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/*2nd link*/
	glTranslated(0.0, 2.5, 0.0);
	glRotated((double)neck, 0.0, 0.0, 1.0);
	glTranslated(0.0, 0.5, 0.0);
	glPushMatrix();
	glScaled(0.5, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//Toward the right arm
	glPushMatrix();
	glTranslated(1.0, 1.0, 0.0);
	glPushMatrix();
	glRotated((double)shoulder_ball, 0.0, 1.0, 0.0);

	glutSolidSphere(0.3, 10, 5);
	glPopMatrix();

	/* 1st link */
	glRotated((double)shoulder_right, 0.0, 0.0, 1.0);
	glTranslated(1.3, 0.0, 0.0);
	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/* 2nd link */
	glTranslated(1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated((double)elbow_right, 0.0, 0.0, 1.0);
	glTranslated(1.0, 0.0, 0.0);
	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/* 3rd link */
	glTranslated(1.0, 0.0, 0.0);				//move to the end of 2nd link
	glRotated((double)hand_right, 0.0, 0.0, 1.0);
	glTranslated(0.5, 0.0, 0.0);
	glPushMatrix();
	glScaled(1.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//Toward the left arm
	glPushMatrix();
	/* 1st link */
	glRotated(-(double)shoulder_left, 0.0, 0.0, 1.0);
	glTranslated(-2.0, 1.0, 0.0);
	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/* 2nd link */
	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated(-(double)elbow_left, 0.0, 0.0, 1.0);
	glTranslated(-1.0, 0.0, 0.0);
	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/* 3rd link */
	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 2nd link
	glRotated(-(double)hand_left, 0.0, 0.0, 1.0);
	glTranslated(-0.5, 0.0, 0.0);
	glPushMatrix();
	glScaled(1.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width / (double)height, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera_x, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'u':
		camera_x = (camera_x + 5) % 360;

		break;

		//Toward the right
	case 'j':
		if (shoulder_right <= 25) {
			shoulder_right = (shoulder_right + 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'J':
		if (shoulder_right >= -25) {
			shoulder_right = (shoulder_right - 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'k':
		if (elbow_right <= 25) {
			elbow_right = (elbow_right + 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'K':
		if (elbow_right >= -25) {
			elbow_right = (elbow_right - 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'l':
		hand_right = (hand_right + 5) % 360;
		glutPostRedisplay();
		break;
	case 'L':
		hand_right = (hand_right - 5) % 360;
		glutPostRedisplay();
		break;

		//Toward the left
	case 'f':
		shoulder_left = (shoulder_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'F':
		shoulder_left = (shoulder_left - 5) % 360;
		glutPostRedisplay();
		break;
	case 'd':
		elbow_left = (elbow_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		elbow_left = (elbow_left - 5) % 360;
		glutPostRedisplay();
		break;
	case 's':
		hand_left = (hand_left + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		hand_left = (hand_left - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
