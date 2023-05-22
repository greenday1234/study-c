//
//  Solar System.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/05/19.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float MercuryYear = 0;
float MercuryDay = 0;
float VenusYear = 0;
float VenusDay = 0;
float EarthYear = 0;
float EarthDay = 0;
float MoonYear = 0;
float MoonDay = 0;
float MarsYear = 0;
float MarsDay = 0;
float JupiterYear = 0;
float JupiterDay = 0;
float SaturnYear = 0;
float SaturnDay = 0;
float UranusYear = 0;
float UranusDay = 0;
float NeptuneYear = 0;
float NeptuneDay = 0;

float zoom = 1.0f;  //줌인/줌아웃 변수
float cameraRotation = 0.0f;    //카메라 회전 변수
float RotateX = 1.0;
float RotateY = 1.0;
float RotateZ = 1.0;

GLdouble eyeX = 0.1;
GLdouble eyeY = 0.1;
GLdouble eyeZ = 0.1;
GLdouble centerX = 0.1;
GLdouble centerY = 0.0;
GLdouble centerZ = 0.0;
GLdouble upX = 1.0;
GLdouble upY = 1.5;
GLdouble upZ = 0.0;

void idleProcess() {
    MercuryYear += 4.0;
    MercuryDay += 1.0;
    VenusYear += 1.8;
    VenusDay += 1.0;
    EarthYear += 1.0;
    EarthDay += 1.0;
    MoonYear += 70.0;
    MoonDay += 1.0;
    MarsYear += 0.45;
    MarsDay += 1.0;
    JupiterYear += 0.09;
    JupiterDay += 1.0;
    SaturnYear += 0.04;
    SaturnDay += 1.0;
    UranusYear += 0.015;
    UranusDay += 1.0;
    NeptuneYear += 0.005;
    NeptuneDay += 1.0;
    
    if (MercuryYear > 360.0)
        MercuryYear = 0.0f;
    if(MercuryDay > 360.0)
        MercuryDay = 0.0f;
    
    if (VenusYear > 360.0)
        VenusYear = 0.0f;
    if(VenusDay > 360.0)
        VenusDay = 0.0f;
    
    if (EarthYear > 360.0)
        EarthYear = 0.0f;
    if(EarthDay > 360.0)
        EarthDay = 0.0f;
    
    if (MoonYear > 360.0)
        MoonYear = 0.0f;
    if(MoonDay > 360.0)
        MoonDay = 0.0f;
    
    if (MarsYear > 360.0)
        MarsYear = 0.0f;
    if(MarsDay > 360.0)
        MarsDay = 0.0f;

    if (JupiterYear > 360.0)
        JupiterYear = 0.0f;
    if(JupiterDay > 360.0)
        JupiterDay = 0.0f;
    
    if (SaturnYear > 360.0)
        SaturnYear = 0.0f;
    if(SaturnDay > 360.0)
        SaturnDay = 0.0f;
    
    if (UranusYear > 360.0)
        UranusYear = 0.0f;
    if(UranusDay > 360.0)
        UranusDay = 0.0f;
    
    if (NeptuneYear > 360.0)
        NeptuneYear = 0.0f;
    if(NeptuneDay > 360.0)
        NeptuneDay = 0.0f;

    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 모드로 전환
    glLoadIdentity();           // 모델뷰 행렬 초기화
    
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ); //기본

    glScalef(zoom, zoom, zoom); //zoom in, zoom out
    
    glRotatef(cameraRotation, RotateX, RotateY, RotateZ); // 씬 전체를 회전시킴

    //태양
    glColor3f(1.0, 0.0, 0.0);
    glutWireSphere(0.1, 20, 15);
          
    //수성
    glPushMatrix();
    glColor3f(0.5, 0.1, 0.4);
    glRotatef(MercuryYear, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef(MercuryDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.01, 20, 15);
    glPopMatrix();
    
    //금성
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.0);
    glRotatef(VenusYear, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef(VenusDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.025, 20, 15);
    glPopMatrix();
    
    //지구
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glRotatef(EarthYear, 0.0, 1.0, 0.0);
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef(EarthDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.025, 20, 15);
    
    //달
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glRotatef(MoonYear, 0.0, 1.0, 0.0);
    glTranslatef(0.05, 0.0, 0.0);
    glRotatef(MoonDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.006, 20, 15);
    glPopMatrix();
    glPopMatrix();
    
    //화성
    glPushMatrix();
    glColor3f(0.7, 0.3, 0.3);
    glRotatef(MarsYear, 0.0, 1.0, 0.0);
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(MarsDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.0125, 20, 15);
    glPopMatrix();

    //목성
    glPushMatrix();
    glColor3f(0.8, 1.0, 1.0);
    glRotatef(JupiterYear, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef(JupiterDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.05, 20, 15);
    glPopMatrix();

    //토성
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.5);
    glRotatef(SaturnYear, 0.0, 1.0, 0.0);
    glTranslatef(0.8, 0.0, 0.0);
    glRotatef(SaturnDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.04, 20, 15);
    glPopMatrix();

    //천왕성
    glPushMatrix();
    glColor3f(0.5, 0.2, 0.5);
    glRotatef(UranusYear, 0.0, 1.0, 0.0);
    glTranslatef(0.9, 0.0, 0.0);
    glRotatef(UranusDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.03, 20, 15);
    glPopMatrix();
    
    //해왕성
    glPushMatrix();
    glColor3f(0.2, 0.5, 0.5);
    glRotatef(NeptuneYear, 0.0, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(NeptuneDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.035, 20, 15);
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.000001, -1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Specialkeyboard(int key, int x, int y)
{
    switch(key) {
        //left
        case GLUT_KEY_LEFT:
            cameraRotation -= 5.0f;
            break;
        //right
        case GLUT_KEY_RIGHT:
            cameraRotation += 5.0f;
            break;
        //up
        case GLUT_KEY_UP:
            zoom *= 1.1f;
            break;
        //down
        case GLUT_KEY_DOWN:
            zoom /= 1.1f;
            break;
    }
    glutPostRedisplay();
}

void popupMenu(int value) {
    switch (value) {
    //기본 시점
    case 1:
        zoom = 1;
        cameraRotation = 0.0f;
            eyeX = 0.1;
            eyeY = 0.1;
            eyeZ = 0.1;
            centerX = 0.1;
            centerY = 0.0;
            centerZ = 0.0;
            upX = 1.0;
            upY = 1.5;
            upZ = 0.0;
            RotateX = 1.0;
            RotateY = 1.0;
            RotateZ = 1.0;
        break;
    //위 시점
    case 2:
        zoom = 1;
        cameraRotation  = 0.0f;
        eyeX = 0.0;
        eyeY = 1.0;
        eyeZ = 0.0;
        centerX = 0.0;
        centerY = 0.0;
        centerZ = 0.0;
        upX = 0.0;
        upY = 0.0;
        upZ = -1.0;
        RotateX = 1.0;
        RotateY = 0.0;
        RotateZ = 0.0;
        break;
    //옆 시점
    case 3:
        glutSetWindowTitle("third Menu");
        printf("select third menu.\n");
        break;
    //앞 시점
    case 4:
        printf("OpenGl Program exit.\n");
        break;
    //무작위 시점
    case 5:
        printf("dd");
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Solar System");
    init();
    
    glutCreateMenu(popupMenu);
    glutAddMenuEntry("기본 시점", 1);
    glutAddMenuEntry("위 시점", 2);
    glutAddMenuEntry("옆 시점", 3);
    glutAddMenuEntry("앞 시점", 4);
    glutAddMenuEntry("무작위 시점", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
   
    glutIdleFunc(idleProcess);
    glutSpecialFunc(Specialkeyboard);
    glutMainLoop();
    return 0;
}
