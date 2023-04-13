//
//  Push Pop Matrix.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/13.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <iostream>

void draw_box() {
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, -0.25, 0.0);
    glVertex3f(0.25, -0.25, 0.0);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(-0.25, 0.25, 0.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);    //red
    draw_box();

    glPushMatrix();    //green
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-1.2, 0.6, 0.0);
    draw_box();
    glPopMatrix();

    glPushMatrix();    //blue
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.6, 0.0);
    draw_box();
    glPopMatrix();

    glPushMatrix();    //pink
    glColor3f(1.0, 0.0, 1.0);
    glScalef(1.2, 1.2, 1.0);
    glRotatef(15, 0.0, 0.0, 1.0);
    glTranslatef(1.2, -1.2, 0.0);
    draw_box();
    glPopMatrix();

    glPushMatrix();    //yellow
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-0.6, -0.6, 0.0);
    glScalef(1.2, 1.2, 1.0);
    draw_box();
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h) {
    float WidthFactor = (float)new_w / 250.0;
    float HeightFactor = (float)new_h / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-3.0 * WidthFactor, 3.0 * WidthFactor, -3.0 * HeightFactor, 3.0 * HeightFactor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Push Pop Matrix");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
