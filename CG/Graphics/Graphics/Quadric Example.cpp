//
//  Quadric Example.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/06/08.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include <stdio.h>

GLUquadricObj* obj;

int renderingmode = 0;
int objectmode = 0;    

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0.0, 0.5, 0.2, 0.0, 0.0, 0, 0.0, 1.0, 0.0);
    
    glPushMatrix();

    switch (renderingmode) {
    case 0:
        gluQuadricDrawStyle(obj, GLU_LINE);
        break;
    case 1:
        gluQuadricDrawStyle(obj, GLU_FILL);
        break;
    case 2:
        gluQuadricDrawStyle(obj, GLU_POINT);
        break;
    case 3:
        gluQuadricDrawStyle(obj, GLU_SILHOUETTE);
        break;
    }

    switch (objectmode) {
    case 0:
        gluSphere(obj, 0.23, 20, 15);
        break;
    case 1:
        gluCylinder(obj, 0.5, 0.5, 0.8, 20, 15);
        break;
    case 2:
        gluDisk(obj, 0.2, 0.6, 20, 15);
        break;
    }

    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);

    obj = gluNewQuadric();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':
        printf("Sphere\n");
        objectmode = 0;
        break;
    case 'w':
        printf("Cylinder\n");
        objectmode = 1;
        break;
    case 'e':
        printf("Disk\n");
        objectmode = 2;
        break;
    case 'a':
        printf("Wireframe\n");
        renderingmode = 0;
        break;
    case 's':
        printf("Fill\n");
        renderingmode = 1;
        break;
    case 'd':
        printf("Point\n");
        renderingmode = 2;
        break;
    case 'f':
        printf("Silhoutte\n");
        renderingmode = 3;
        break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("11_1 Quardic Example");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
