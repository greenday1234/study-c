//
//  3.cpp
//  Greenday
//
//  Created by 이찬희 on 2023/03/22.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

GLfloat angle = 0.0f;

void Display() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.0, -0.8);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Make Star");

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
