//
//  lode.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/05/17.
//
#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLUT/glut.h>
#include <vector>
#include "lodepng.h"

float rotation = 0.0f;
float angularVelocity = 1.5f;
GLuint textureID[2];
std::vector<unsigned char> image2;
void loadTexture(GLuint* texture, const char* path);
GLuint tex;
int count = 0;

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
    glViewport(0, 0, 500, 500);

    glPushMatrix();
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);

    if (count%2 == 0 ) {    //마우스 클릭 값으로 디폴트는 0, 1번 클릭마다 count값이 1증가해 png파일이 다른 것으로 변경
        tex = textureID[0];
    }
    else {
        tex = textureID[1];
    }

    glBindTexture(GL_TEXTURE_2D, tex);  //마우스 클릭 값에 따라서 tex값이 바뀜
    glBegin(GL_QUADS);  //사각형으로 만들기
    //텍스쳐의 좌표와 도형의 좌표를 나타내 둘을 합치는 작업을 함
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-50.0f, -50.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(50.0f, -50.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, 0.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, tex);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(50.0f, -50.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-50.0f, -50.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, 500, 500);
    glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
    glutPostRedisplay();
}

void rotate(int value) {
    rotation += angularVelocity;

    glutTimerFunc(10, rotate, 0);
    glutPostRedisplay();
}

void swap(unsigned char* a, unsigned char* b) {
    const unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void loadTexture(GLuint* texture, const char* path) {
    std::vector<unsigned char> image;
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, path);
    if (!error)
        std::cout << "error" << error << ": " << lodepng_error_text(error) << std::endl;
    size_t u2 = 1;
    while (u2 < width) {
        u2 *= 2;
    }
    size_t v2 = 1;
    while (v2 < height) {
        v2 *= 2;
    }
    image2 = std::vector<unsigned char>(u2 * v2 * 4);
    for (size_t y = 0; y < height; y++)
        for (size_t x = 0; x < width; x++)
            for (size_t c = 0; c < 4; c++) {
                image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
            }
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void initialize() {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    loadTexture(&textureID[0],"1.png");
    loadTexture(&textureID[1],"2.png");
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) {
            count++;
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("20194012_이찬희");
    glClearColor(0, 0, 0, 0);

    initialize();

    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
    glutTimerFunc(10, rotate, 0);
    glutMainLoop();
    return 1;
}
