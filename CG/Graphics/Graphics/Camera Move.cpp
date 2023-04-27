//
//  Camera Move.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/05.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    //행렬 초기화

    //Viewing Transformation
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

    //glRotatef(90, 1.0, 0.0, 0.0);        // 카메라의 위치를 x축을 기준으로 90도 회전
    //glTranslatef(0.0, 0.0, -2.0);        // z축으로 -2.0만큼 이동.(물체가 작아짐)
    glutWireTeapot(1.0);

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    //행렬 초기화
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformation Teapot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
