//
//  Korea.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/02.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>

void DrawLine(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.05,0,0);
        glVertex3f(0.05,0,0);
        glVertex3f(0.05,0.023,0);
        glVertex3f(-0.05,0.023,0);
    glEnd();
}

void DrawTwoLine(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.05,0,0);
    glVertex3f(-0.005,0,0);
    glVertex3f(-0.005,0.023,0);
    glVertex3f(-0.05,0.023,0);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.005,0,0);
    glVertex3f(0.05,0,0);
    glVertex3f(0.05,0.023,0);
    glVertex3f(0.005,0.023,0);
    glEnd();
}

void display() {
    glColor3f(1.0, 1.0, 1.0);    // 흰색으로 설정

        // 사각형의 좌표 입력
        glBegin(GL_POLYGON);
        glVertex2f(0.2, 0.3);
        glVertex2f(0.8, 0.3);
        glVertex2f(0.8, 0.7);
        glVertex2f(0.2, 0.7);
        glEnd();

        glViewport(0.0, 0.0, 600.0, 400.0);
        glFlush();    // 사각형을 화면에 그림
    
    glColor3f(1.0, 0.0, 0.0);    // 빨강으로 설정
   
    //빨간 반원
    double radius = 0.1;    //원의 반지름
    
    glBegin(GL_POLYGON);
    for(int i=-20;i<=160;i++)  //원 생성
    {
        double angle = i*3.141592 / 180;
        double x = radius*cos(angle);
        double y = radius*sin(angle);
        glVertex2f(x+0.5,y+0.5);    //생성된 원의 좌표를 설정
    }
    glEnd();
    
    //파란 반원
    glColor3f(0.0, 0.0, 1.0);
    radius = 0.1;
    
    glBegin(GL_POLYGON);
    for(int i=160;i<=340;i++)  //원 생성
    {
        double angle = i*3.141592 / 180;
        double x = radius*cos(angle);
        double y = radius*sin(angle);
        glVertex2f(x+0.5,y+0.5);    //생성된 원의 좌표를 설정
    }
    glEnd();
    
    //빨간 작은 원
    glColor3f(1.0, 0.0, 0.0);
    radius = 0.05;
    
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)  //원 생성
    {
        double angle = i*3.141592 / 180;
        double x = radius*cos(angle);
        double y = radius*sin(angle);
        glVertex2f(x+0.459,y+0.53);    //생성된 원의 좌표를 설정
    }
    glEnd();
    
    //파란 작은 원
    glColor3f(0.0, 0.0, 1.0);
    radius = 0.05;
    
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)  //원 생성
    {
        double angle = i*3.141592 / 180;
        double x = radius*cos(angle);
        double y = radius*sin(angle);
        glVertex2f(x+0.541,y+0.47);    //생성된 원의 좌표를 설정
    }
    glEnd();
    
    //건
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(-33.690068, 0.0, 0.0, 1.0);
    glTranslatef(-0.17, -0.02, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    DrawLine();
    glTranslatef(0.0, 0.03, 0.0);
    DrawLine();
    glTranslatef(0.0, 0.03, 0.0);
    DrawLine();
    glPopMatrix();
    
    //감
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(33.690068, 0.0, 0.0, 1.0);
    glTranslatef(0.19, -0.0, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    DrawTwoLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawTwoLine();
    glPopMatrix();
    
    //곤
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(-33.690068, 0.0, 0.0, 1.0);
    glTranslatef(0.23, 0.01, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    DrawTwoLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawTwoLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawTwoLine();
    glPopMatrix();
    
    //리
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(-50, 0.0, 0.0, 1.0);
    glTranslatef(-0.03, -0.23, 0.0);
    glRotatef(180, 0.0, 0.0, 1.0);
    DrawLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawTwoLine();
    glTranslatef(0.0, -0.03, 0.0);
    DrawLine();
    glPopMatrix();
    
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);    // 윈도우 배경을 검은색으로 지정
    glClear(GL_COLOR_BUFFER_BIT);    // 색상 버퍼를 지움

    gluOrtho2D(-0.025, 1.025, 0.15, 0.85);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);    // GLUT 상태를 초기화
    // 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 창의 크기와 위치 설정
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Korea");    // 윈도우 생성
    init();
    
    // 필요한 콜백함수 등록
    glutDisplayFunc(display);
    glutMainLoop();    // 이벤트 처리엔진 시작
    return 0;
}
