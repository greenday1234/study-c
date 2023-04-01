//
//  Mouse Star.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/03/26.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat angle = 0.0f;

void idleProcess() {
    angle += 0.2f;
    if (angle > 360.0)
        angle = 0.0f;
    
    glutPostRedisplay();
}

double to_radian(double d)
{
    return d * M_PI / 180.0;
}

void draw_star(int x, int y, int r)
{
    double radian = to_radian(60);
    
    glColor3f(1.0, 1.0, 1.0);
    
    // 삼각형 1
    glBegin(GL_TRIANGLES);
        glVertex3f(x, y+r, 0);
        glVertex3f(x - r*sin(radian), y - r*cos(radian), 0);
        glVertex3f(x + r*sin(radian), y - r*cos(radian), 0);
    glEnd();
    
    // 삼각형 2
    glBegin(GL_TRIANGLES);
        glVertex3f(x, y-r, 0);
        glVertex3f(x - r*sin(radian), y + r*cos(radian), 0);
        glVertex3f(x + r*sin(radian), y + r*cos(radian), 0);
    glEnd();
}

void display() {
   
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);    // 윈도우 배경을 검은색으로 지정
    glClear(GL_COLOR_BUFFER_BIT);    // 색상 버퍼를 지움
    // 직교 투영: left, right, bottom, top
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
}

void mouseProcess(int button, int state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //상하반전
        y = 400-y;
       
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);    // GLUT 상태를 초기화
    // 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 창의 크기와 위치 설정
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Mouse Star");    // 윈도우 생성
    init();
    
    // 필요한 콜백함수 등록
    glutDisplayFunc(display);
    glutMouseFunc(mouseProcess);
    glutIdleFunc(idleProcess);

    glutMainLoop();    // 이벤트 처리엔진 시작
    return 0;
}
