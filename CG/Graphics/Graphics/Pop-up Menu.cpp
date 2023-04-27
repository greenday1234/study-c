//
//  Pop-up Menu.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/27.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0, 0.0, 0.0);
    glFlush();
}

void popupMenu(int value) {
    switch (value) {
    case 1:
        glutSetWindowTitle("first Menu");
        printf("select first menu.\n");
        break;
    case 2:
        glutSetWindowTitle("second Menu");
        printf("select second menu.\n");
        break;
    case 3:
        glutSetWindowTitle("third Menu");
        printf("select third menu.\n");
        break;
    case 99:
        printf("OpenGl Program exit.\n");
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("07_1 Pop-up Menu");

    glutCreateMenu(popupMenu);
    glutAddMenuEntry("First", 1);
    glutAddMenuEntry("Second", 2);
    glutAddMenuEntry("third", 3);
    glutAddMenuEntry("Exit", 99);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
