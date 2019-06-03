#include <stdlib.h>
#include <GL/glut.h>

static int shoulder_right = 0, elbow_right = 0, hand_right = 0;
static int shoulder_left = 0, elbow_left = 0, hand_left = 0;
static int body = 0;
static int neck = 0, head = 0, shoulder_ball = 0;
static int camera_x = 0;

//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//body
//	glPushMatrix();
//	/* 1st link */
//	glRotated((double)body, 0.0, 0.0, 1.0);
//	glPushMatrix();
//	glScaled(2.0, 5.0, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	/*2nd link*/
//	glTranslated(0.0, 2.5, 0.0);
//	glRotated((double)neck, 0.0, 0.0, 1.0);
//	glTranslated(0.0, 0.5, 0.0);
//	glPushMatrix();
//	glScaled(0.5, 1.0, 0.5);
//	glutSolidCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	//Toward the right arm
//	glPushMatrix();
//	glTranslated(1.0, 1.0, 0.0);
//	glPushMatrix();
//	glRotated((double)shoulder_ball, 0.0, 1.0, 0.0);
//
//	glutSolidSphere(0.3, 10, 5);
//	glPopMatrix();
//
//	/* 1st link */
//	glRotated((double)shoulder_right, 0.0, 0.0, 1.0);
//	glTranslated(1.3, 0.0, 0.0);
//	glPushMatrix();
//	glScaled(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	/* 2nd link */
//	glTranslated(1.0, 0.0, 0.0);				//move to the end of 1st link
//	glRotated((double)elbow_right, 0.0, 0.0, 1.0);
//	glTranslated(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScaled(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	/* 3rd link */
//	glTranslated(1.0, 0.0, 0.0);				//move to the end of 2nd link
//	glRotated((double)hand_right, 0.0, 0.0, 1.0);
//	glTranslated(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScaled(1.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	//Toward the left arm
//	glPushMatrix();
//	/* 1st link */
//	glRotated(-(double)shoulder_left, 0.0, 0.0, 1.0);
//	glTranslated(-2.0, 1.0, 0.0);
//	glPushMatrix();
//	glScaled(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	/* 2nd link */
//	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 1st link
//	glRotated(-(double)elbow_left, 0.0, 0.0, 1.0);
//	glTranslated(-1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScaled(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	/* 3rd link */
//	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 2nd link
//	glRotated(-(double)hand_left, 0.0, 0.0, 1.0);
//	glTranslated(-0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScaled(1.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}