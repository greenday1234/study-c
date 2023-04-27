//
//  Planet + Pop up.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/27.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>

int year = 0;
int day = 0;

float sR = 1.0;
float sG = 0.0;
float sB = 0.0;

float mR = 1.0;
float mG = 1.0;
float mB = 1.0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    glColor3f(sR, sG, sB);
    glutSolidSphere(1.0, 20, 16);

    glColor3f(mR, mG, mB);
    glRotatef(year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef(day, 0.0, 1.0, 0.0);
    glutSolidSphere(0.2, 10, 8);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int new_w, int new_h) {
    glViewport(0, 0, new_w, new_h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        day = (day + 10) % 360;
        break;
    case 'D':
        day = (day - 10) % 360;
        break;
    case 'y':
        year = (year + 5) % 360;
        break;
    case 'Y':
        year = (year - 5) % 360;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void popupMenu(int value) {
    switch (value) {
    case 1:
        sR = 1.0; sG = 0.0; sB = 0.0;
        glutPostRedisplay();
        break;
    case 2:
        sR = 1.0; sG = 1.0; sB = 0.0;
        glutPostRedisplay();
        break;
    case 3:
        mR = 1.0; mG = 1.0; mB = 1.0;
        glutPostRedisplay();
        break;
    case 4:
        mR = 0.0; mG = 0.0; mB = 1.0;
        glutPostRedisplay();
        break;
    case 99:
        printf("OpenGl Program exit.\n");
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("06_1 Planet");

    init();

    int submenu1 = glutCreateMenu(popupMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Yellow", 2);

    int submenu2 = glutCreateMenu(popupMenu);
    glutAddMenuEntry("White", 3);
    glutAddMenuEntry("Blue", 4);

    glutCreateMenu(popupMenu);
    glutAddSubMenu("SUN", submenu1);
    glutAddSubMenu("MOON", submenu2);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
