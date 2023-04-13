//
//  Frustum Ortho.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/13.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glutWireCube(1.0);

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-1.5, 0.0, 1.5);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(1.5, 0.0, 1.5);
    glutWireCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void reshape(int new_w, int new_h) {
    glViewport(0, 0, new_w, new_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
    //glOrtho(-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Push Pop + Projection");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
