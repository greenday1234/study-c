//
//  4.cpp
//  Greenday
//
//  Created by 이찬희 on 2023/03/22.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>

void display() {
    glColor3f(1.0, 1.0, 1.0);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f(-0.75, -0.75, 0.0);
    glColor3f(0, 1, 0);
    glVertex3f(0.75, -0.75, 0.0);
    glColor3f(0, 0, 1);
    glVertex3f(0.75, 0.75, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.75, 0.75, 0.0);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h) {
    glViewport(0, 0, new_w, new_h);
    float WidthFactor = (float)new_w / 250.0;
    float HeightFactor = (float)new_h / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);    // ¿©µµøÏ √¢ ≈©±‚∏¶ ∫Ø∞Ê«ÿµµ ≈©±‚∞° ∫Ø«œ¡ˆ æ ∞‘ «ÿ¡‹
}

void keyboardProcess(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        printf("write 1.\n");
    case '2':
        printf("write 2.\n");
    case '3':
        printf("write 3.\n");
    case 'Q':
        printf("write Q.\n");
    }
}

void mouseProcess(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("Press left mouse button.\n");
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        printf("Press middle mouse button.\n");
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        printf("Press right mouse button.\n");
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        printf("Cut left mouse button.\n");
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        printf("Cut middle mouse button.\n");
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        printf("Cut right mouse button.\n");
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("02 Reshape Callback");
    init();

    glutKeyboardFunc(keyboardProcess);
    glutMouseFunc(mouseProcess);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
