//
//  test.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/02.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
void display() {
    // 까만 배경색으로 설정
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 태극기 바깥 원 그리기
    glColor3f(0.8f, 0.0f, 0.0f); // 빨간색으로 설정
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // 중심점
    int num_segments = 100; // 원을 구성하는 선분의 개수
    float radius = 0.5f; // 반지름
    for (int i = 0; i <= num_segments; ++i) {
        float theta = i * 2.0f * 3.1415926f / num_segments;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // 태극문양 그리기
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색으로 설정
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // 중심점
    float inner_radius = radius * 0.4f; // 내부 원의 반지름
    float outer_radius = radius * 0.8f; // 외부 원의 반지름
    for (int i = 0; i <= num_segments; ++i) {
        float theta = i * 2.0f * 3.1415926f / num_segments;
        float x = outer_radius * cos(theta);
        float y = outer_radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // 하얀색으로 설정하여, 원과 태극문양을 분리
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // 중심점
    for (int i = 0; i <= num_segments; ++i) {
        float theta = i * 2.0f * 3.1415926f / num_segments;
        float x = inner_radius * cos(theta);
        float y = inner_radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Taegukgi");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
