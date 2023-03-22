//
//  0322_hw.cpp
//  Graphics
//
//  Created by 김건아 on 2023/03/22.
//

#define GL_SILENCE_DEPRECATION  // deprecation경고 제거
#include <GLUT/GLUT.h>          // 윈도우와 user interface API

GLfloat angle = 0.0f;

void idleProcess()
{
    angle += 0.0001f;
    if (angle > 360.0) angle = 0.0f;
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glRotatef(angle, 0, 0, 1);
    
    glColor3f(1.0f, 1.0f, 0.0f);
    
    // 삼각형의 좌표 입력
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.25, -0.15, 0.0);
        glVertex3f(0.25, -0.15, 0.0);
        glVertex3f(0, 0.3, 0.0);
    glEnd();
    // 삼각형의 좌표 입력
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.25, 0.15, 0.0);
        glVertex3f(0.25, 0.15, 0.0);
        glVertex3f(0, -0.3, 0.0);
    glEnd();
    
    glutSwapBuffers();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h)
{
    glViewport(0, 0, new_w, new_h);
    float WidthFactor = (float)new_w/255.0;
    float HeightFactor = (float)new_h/255.0;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-0.5 * WidthFactor, 0.5 * WidthFactor, -0.5 * HeightFactor, 0.5 * HeightFactor);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("02_5 Idle Callback");
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idleProcess);
    glutMainLoop();
    
    return 0;
}
