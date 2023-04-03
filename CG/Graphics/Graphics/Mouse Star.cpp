//
//  Mouse Star.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/03/26.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <random>
#include <stdio.h>
#define MAX_VER 1000

//RGB 색상
int red = 255, green = 255, blue = 255;
GLfloat Vertices[MAX_VER][2];
GLfloat angle = 0.0f;
int count = 0;
int click = 0;

//선 그리는 함수
void draw_line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

//회전 함수
void idleProcess() {
    //오른쪽 마우스를 누르지 않은 경우
    if(click == 0){
        
    }
    //오른쪽 마우스를 한 번 누른 경우(시계방향)
    else if(click%2 != 0){
        angle += 0.2f;
        if (angle > 360.0)
            angle = 0.0f;
    }
    //오른쪽 마우스를 두 번 누른 경우(반시계방향)
    else if(click%2 == 0 && click != 0){
        angle -= 0.2f;
        if(angle > 360.0)
            angle = 0.0f;
    }
    glutPostRedisplay();
}

//크기 설정 함수
double to_radian(double d)
{
    return d * M_PI / 180.0;
}

//별 그리기 함수
void draw_star(int x, int y, int r)
{
    double radian = to_radian(60);
    
    glColor3ub(red, green, blue);
    
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

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);    // 윈도우 배경을 검은색으로 지정
    glClear(GL_COLOR_BUFFER_BIT);    // 색상 버퍼를 지움
    // 직교 투영: left, right, bottom, top
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
    //초기 별 생성
    glPushMatrix();
    glTranslatef(300, 200, 0.0);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    draw_star(0, 0, 20);
    glPopMatrix();
    glFlush();
    //맨 처음 별의 좌표값 세팅
    Vertices[count][0] = 300;
    Vertices[count][1] = 200;
    count++;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int index = 1; index < count ; index++){
            draw_line(Vertices[index-1][0], Vertices[index-1][1], Vertices[index][0], Vertices[index][1]);
        }
    
    for(int index = 0; index < count ; index++){
        glPushMatrix();
        glTranslatef(Vertices[index][0], Vertices[index][1], 0.0);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        draw_star(0, 0, 20);
        glPopMatrix();
    }
    glFlush();
}

void mouseProcess(int button, int state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //상하반전
        y = 400-y;
        //별 좌표 저장
        Vertices[count][0] = x;
        Vertices[count][1] = y;
        //별 그리기
        display();
        count++;
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        //색상 초기화
        red = rand()%255+1;
        green = rand()%255+1;
        blue = rand()%255+1;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        click++;
        red = rand()%255+1;
        green = rand()%255+1;
        blue = rand()%255+1;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);    // GLUT 상태를 초기화
    // 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
    glutInitDisplayMode(GLUT_RGB);

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
