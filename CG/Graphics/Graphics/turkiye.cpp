//
//  turkiye.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/03/26.
//

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>

void display() {
glColor3f(0.75, 0.0, 0.0);    // 빨강으로 설정

    // 사각형의 좌표 입력
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.8, 0.7);
    glVertex2f(0.2, 0.7);
    glEnd();

    glFlush();    // 사각형을 화면에 그림
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);    // 윈도우 배경을 검은색으로 지정
    glClear(GL_COLOR_BUFFER_BIT);    // 색상 버퍼를 지움

    // 직교 투영: left, right, bottom, top, near, far
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboardProcess(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
        {
            glColor3f(1.0f, 1.0f, 1.0f);    //흰색 설정
            
            double radius = 0.1;    //원의 반지름
            
            glBegin(GL_POLYGON);
            for(int i=0;i<360;i++)  //원 생성
            {
                double angle = i*3.141592 / 180;
                double x = radius*cos(angle);
                double y = radius*sin(angle);
                glVertex2f(x+0.4,y+0.5);    //생성된 원의 좌표를 설정
            }
            glEnd();
            glFlush();
            break;
        }
    case '2':
        {
            glColor3f(0.75f, 0.0f, 0.0f);    //빨간색 설정
            
            double radius = 0.08;    //원의 반지름
            
            glBegin(GL_POLYGON);
            for(int i=0;i<360;i++)  //원 생성
            {
                double angle = i*3.141592 / 180;
                double x = radius*cos(angle);
                double y = radius*sin(angle);
                glVertex2f(x+0.43,y+0.5);    //생성된 원의 좌표를 설정
            }
            glEnd();
            glFlush();
            break;
        }
    case '3':
        {
            glColor3f(1.0f, 1.0f, 1.0f);    //흰색 설정
                
            glBegin(GL_POLYGON);    //삼각형1 생성
            glVertex2f(0.495, 0.5);
            glVertex2f(0.585, 0.525);
            glVertex2f(0.545, 0.48);
            glEnd();
        
            glBegin(GL_POLYGON);    //삼각형2 생성
            glVertex2f(0.53, 0.55);
            glVertex2f(0.53, 0.45);
            glVertex2f(0.561, 0.495);
            glEnd();
            
            glBegin(GL_POLYGON);    //삼각형3 생성
            glVertex2f(0.53, 0.55);
            glVertex2f(0.585, 0.473);
            glVertex2f(0.531, 0.487);
            glEnd();
            
            glFlush();
            break;
        }
    case '\n':
    case '\r':
        {
            glColor3f(1.0f, 1.0f, 1.0f);    //흰색 설정
            
            double radius = 0.1;    //원의 반지름
            
            glBegin(GL_POLYGON);
            for(int i=0;i<360;i++)  //원 생성
            {
                double angle = i*3.141592 / 180;
                double x = radius*cos(angle);
                double y = radius*sin(angle);
                glVertex2f(x+0.4,y+0.5);    //생성된 원의 좌표를 설정
            }
            glEnd();
            
            glColor3f(0.75f, 0.0f, 0.0f);    //빨간색 설정
            
            double radius1 = 0.08;    //원의 반지름
            
            glBegin(GL_POLYGON);
            for(int i=0;i<360;i++)  //원 생성
            {
                double angle = i*3.141592 / 180;
                double x = radius1*cos(angle);
                double y = radius1*sin(angle);
                glVertex2f(x+0.43,y+0.5);    //생성된 원의 좌표를 설정
            }
            glEnd();
            
            glColor3f(1.0f, 1.0f, 1.0f);    //흰색 설정
                
            glBegin(GL_POLYGON);    //삼각형1 생성
            glVertex2f(0.495, 0.5);
            glVertex2f(0.585, 0.525);
            glVertex2f(0.545, 0.48);
            glEnd();
        
            glBegin(GL_POLYGON);    //삼각형2 생성
            glVertex2f(0.53, 0.55);
            glVertex2f(0.53, 0.45);
            glVertex2f(0.561, 0.495);
            glEnd();
            
            glBegin(GL_POLYGON);    //삼각형3 생성
            glVertex2f(0.53, 0.55);
            glVertex2f(0.585, 0.473);
            glVertex2f(0.531, 0.487);
            glEnd();
            
            glFlush();
            
            break;
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);    // GLUT 상태를 초기화
    // 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 창의 크기와 위치 설정
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("turkiye");    // 윈도우 생성
    init();
    
    glutKeyboardFunc(keyboardProcess);
    // 필요한 콜백함수 등록
    glutDisplayFunc(display);
    glutMainLoop();    // 이벤트 처리엔진 시작
    return 0;
}
