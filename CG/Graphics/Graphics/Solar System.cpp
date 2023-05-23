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
#include <time.h>

GLfloat ratio;  //viewport 변수
int count = 0;  //space bar 변수

float MercuryYear = 0; float MercuryDay = 0;
float VenusYear = 0; float VenusDay = 0;
float EarthYear = 0; float EarthDay = 0;
float MoonYear = 0; float MoonDay = 0;
float MarsYear = 0; float MarsDay = 0;
float JupiterYear = 0; float JupiterDay = 0;
float SaturnYear = 0; float SaturnDay = 0;
float UranusYear = 0; float UranusDay = 0;
float NeptuneYear = 0; float NeptuneDay = 0;

float zoom = 1.0f;  //줌인/줌아웃 변수
float cameraRotation = 0.0f;    //카메라 회전 변수
float RotateX = 1.0; float RotateY = 1.0; float RotateZ = 1.0;  //회전 축 변수

//시점 변수
GLdouble eyeX = 0.1; GLdouble eyeY = 0.1; GLdouble eyeZ = 0.1;
GLdouble centerX = 0.1; GLdouble centerY = 0.0; GLdouble centerZ = 0.0;
GLdouble upX = 1.0; GLdouble upY = 1.5; GLdouble upZ = 0.0;

//공전 속도 변수
float MercuryR = 4.0; float VenusR = 1.8; float EarthR = 1.0;
float MoonR = 70.0; float MarsR = 0.45; float JupiterR = 0.09;
float SaturnR = 0.04; float UranusR = 0.015; float NeptuneR = 0.005;

//행성 색 변수
GLfloat sunr = 1.0; GLfloat sunG = 0.0; GLfloat sunB = 0.0;
GLfloat Mercuryr = 0.5; GLfloat MercuryG = 0.1; GLfloat MercuryB = 0.4;
GLfloat Venusr = 0.5; GLfloat VenusG = 0.5; GLfloat VenusB = 0.0;
GLfloat Earthr = 0.0; GLfloat EarthG = 0.0; GLfloat EarthB = 1.0;
GLfloat Moonr = 0.7; GLfloat MoonG = 0.7; GLfloat MoonB = 0.7;
GLfloat Marsr = 0.7; GLfloat MarsG = 0.3; GLfloat MarsB = 0.3;
GLfloat Jupiterr = 0.8; GLfloat JupiterG = 1.0; GLfloat JupiterB = 1.0;
GLfloat Saturnr = 0.2; GLfloat SaturnG = 0.2; GLfloat SaturnB = 0.5;
GLfloat Uranusr = 0.5; GLfloat UranusG = 0.2; GLfloat UranusB = 0.5;
GLfloat Neptuner = 0.2; GLfloat NeptuneG = 0.5; GLfloat NeptuneB = 0.5;


void idleProcess() {
    MercuryYear += MercuryR; MercuryDay += 1.0;
    VenusYear += VenusR; VenusDay += 1.0;
    EarthYear += EarthR; EarthDay += 1.0;
    MoonYear += MoonR; MoonDay += 1.0;
    MarsYear += MarsR; MarsDay += 1.0;
    JupiterYear += JupiterR; JupiterDay += 1.0;
    SaturnYear += SaturnR; SaturnDay += 1.0;
    UranusYear += UranusR; UranusDay += 1.0;
    NeptuneYear += NeptuneR; NeptuneDay += 1.0;
    
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

double randomDouble(void) {
  return (double) rand() / RAND_MAX;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 모드로 전환
    glLoadIdentity();           // 모델뷰 행렬 초기화
    
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ); //기본

    glScalef(zoom, zoom, zoom); //zoom in, zoom out
    
    glRotatef(cameraRotation, RotateX, RotateY, RotateZ); // 씬 전체를 회전시킴
    
    glInitNames();
    
    //태양
    glPushName(1);
    glPushMatrix();
    glColor3f(sunr, sunG, sunB);
    glutWireSphere(0.1, 20, 15);
    glPopMatrix();
    glPopName();
          
    //수성
    glPushName(2);
    glPushMatrix();
    glColor3f(Mercuryr, MercuryG, MercuryB);
    glRotatef(MercuryYear, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef(MercuryDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.01, 20, 15);
    glPopMatrix();
    glPopName();
    
    //금성
    glPushName(3);
    glPushMatrix();
    glColor3f(Venusr, VenusG, VenusB);
    glRotatef(VenusYear, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef(VenusDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.025, 20, 15);
    glPopMatrix();
    glPopName();
    
    //지구
    glPushName(4);
    glPushMatrix();
    glColor3f(Earthr, EarthG, EarthB);
    glRotatef(EarthYear, 0.0, 1.0, 0.0);
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef(EarthDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.025, 20, 15);
    glPopName();
    
    //달
    glPushName(5);
    glColor3f(Moonr, MoonG, MoonB);
    glRotatef(MoonYear, 0.0, 1.0, 0.0);
    glTranslatef(0.05, 0.0, 0.0);
    glRotatef(MoonDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.006, 20, 15);
    glPopMatrix();
    glPopName();

    
    //화성
    glPushName(6);
    glPushMatrix();
    glColor3f(Marsr, MarsG, MarsB);
    glRotatef(MarsYear, 0.0, 1.0, 0.0);
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(MarsDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.0125, 20, 15);
    glPopMatrix();
    glPopName();

    //목성
    glPushName(7);
    glPushMatrix();
    glColor3f(Jupiterr, JupiterG, JupiterB);
    glRotatef(JupiterYear, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef(JupiterDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.05, 20, 15);
    glPopMatrix();
    glPopName();

    //토성
    glPushName(8);
    glPushMatrix();
    glColor3f(Saturnr, SaturnG, SaturnB);
    glRotatef(SaturnYear, 0.0, 1.0, 0.0);
    glTranslatef(0.8, 0.0, 0.0);
    glRotatef(SaturnDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.04, 20, 15);
    glPopMatrix();
    glPopName();

    //천왕성
    glPushName(9);
    glPushMatrix();
    glColor3f(Uranusr, UranusG, UranusB);
    glRotatef(UranusYear, 0.0, 1.0, 0.0);
    glTranslatef(0.9, 0.0, 0.0);
    glRotatef(UranusDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.03, 20, 15);
    glPopMatrix();
    glPopName();

    //해왕성
    glPushName(10);
    glPushMatrix();
    glColor3f(Neptuner, NeptuneG, NeptuneB);
    glRotatef(NeptuneYear, 0.0, 1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(NeptuneDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.035, 20, 15);
    glPopMatrix();
    glPopName();

    glutSwapBuffers();
}

//객체 선택 시 이벤트 발생 함수
void ProcessSelect(GLuint index[64]){
    switch(index[3]){
        case 1:
            sunr = randomDouble();
            sunG = randomDouble();
            sunB = randomDouble();
            break;
        case 2:
            Mercuryr = randomDouble();
            MercuryG = randomDouble();
            MercuryB = randomDouble();
            break;
        case 3:
            Venusr = randomDouble();
            VenusG = randomDouble();
            VenusB = randomDouble();
            break;
        case 4:
            Earthr = randomDouble();
            EarthG = randomDouble();
            EarthB = randomDouble();
            break;
        case 5:
            Moonr = randomDouble();
            MoonG = randomDouble();
            MoonB = randomDouble();
            break;
        case 6:
            Marsr = randomDouble();
            MarsG = randomDouble();
            MarsB = randomDouble();
            break;
        case 7:
            Jupiterr = randomDouble();
            JupiterG = randomDouble();
            JupiterB = randomDouble();
            break;
        case 8:
            Saturnr = randomDouble();
            SaturnG = randomDouble();
            SaturnB = randomDouble();
            break;
        case 9:
            Uranusr = randomDouble();
            UranusG = randomDouble();
            UranusB = randomDouble();
            break;
        case 10:
            Neptuner = randomDouble();
            NeptuneG = randomDouble();
            NeptuneB = randomDouble();
            break;
    }
}


//객체 선택 함수
void SelectObjects(GLint x, GLint y)
{
    GLuint selectBuff[64];
    GLint hits, viewport[4];
   
    glSelectBuffer(64, selectBuff);
    glGetIntegerv(GL_VIEWPORT, viewport);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glRenderMode(GL_SELECT);
    glLoadIdentity();
    gluPickMatrix(x, viewport[3]-y, 2, 2, viewport);
    gluPerspective(90.0f,ratio,0.000001f,1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    display();
    hits = glRenderMode(GL_RENDER);
    if(hits>0) ProcessSelect(selectBuff);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    ratio = (GLfloat)w / (GLfloat)h;
    gluPerspective(90.0, ratio, 0.000001, 1000.0);
}

//마우스 함수
void mouseProcess(int button, int state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        SelectObjects(x, y);
    }
}

//키 입력 함수
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    //+key
    case '+':
            MercuryR += 0.2;
            VenusR += 0.2;
            EarthR += 0.2;
            MoonR += 0.2;
            MarsR += 0.2;
            JupiterR += 0.2;
            SaturnR += 0.2;
            UranusR += 0.2;
            NeptuneR += 0.2;
        break;
    //-key
    case '-':
            if(MercuryR <= 0.0){
                MercuryR = 0.0;
            }
            else{
                MercuryR -= 0.2;
            }
            
            if(VenusR <= 0.0){
                VenusR = 0.0;
            }
            else{
                VenusR -= 0.2;
            }
            
            if(EarthR <= 0.0){
                EarthR = 0.0;
            }
            else{
                EarthR -= 0.2;
            }

            if(MoonR <= 0.0){
                MoonR = 0.0;
            }
            else{
                MoonR -= 0.2;
            }
            
            if(MarsR <= 0.0){
                MarsR = 0.0;
            }
            else{
                MarsR -= 0.2;
            }
            
            if(JupiterR <= 0.0){
                JupiterR = 0.0;
            }
            else{
                JupiterR -= 0.2;
            }
            
            if(SaturnR <= 0.0){
                SaturnR = 0.0;
            }
            else{
                SaturnR -= 0.2;
            }
            
            if(UranusR <= 0.0){
                UranusR = 0.0;
            }
            else{
                UranusR -= 0.2;
            }
            
            if(NeptuneR <= 0.0){
                NeptuneR = 0.0;
            }
            else{
                NeptuneR -= 0.2;
            }
        break;
    //space bar
    case ' ':
            count++;
            if(count%2 != 0){
                glutIdleFunc(NULL);
            }
            else{
                glutIdleFunc(idleProcess);
            }
        break;
    }
    glutPostRedisplay();
}

//특수키 입력 함수
void Specialkeyboard(int key, int x, int y)
{
    switch(key) {
        //left
        case GLUT_KEY_LEFT:
            cameraRotation += 5.0f;
            break;
        //right
        case GLUT_KEY_RIGHT:
            cameraRotation -= 5.0f;
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

//팝업 메뉴 함수
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
        eyeY = 0.1;
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
        zoom = 1;
        cameraRotation = 0.0f;
        eyeX = 0.0;
        eyeY = 0.0;
        eyeZ = -0.1;
        centerX = 0.0;
        centerY = 0.0;
        centerZ = 0.0;
        upX = 0.0;
        upY = -1.0;
        upZ = 0.0;
        RotateX = 0.0;
        RotateY = 1.0;
        RotateZ = 0.0;
        break;
    //앞 시점
    case 4:
        zoom = 1;
        cameraRotation = 0.0f;
        eyeX = 0.1;
        eyeY = 0.0;
        eyeZ = 0.0;
        centerX = 0.0;
        centerY = 0.0;
        centerZ = 0.0;
        upX = 0.0;
        upY = -1.0;
        upZ = 0.0;
        RotateX = 0.0;
        RotateY = 1.0;
        RotateZ = 0.0;
        break;
    //무작위 시점
    case 5:
        zoom = 1;
        cameraRotation = 0.0f;
        eyeX = randomDouble()*0.1;  //0.1을 곱하지 않으면 태양계가 보이지 않는 위치로 시점이 이동할 수 있기 때문에 0.1을 곱해줌
        eyeY = randomDouble()*0.1;
        eyeZ = randomDouble()*0.1;
        centerX = randomDouble();
        centerY = randomDouble();
        centerZ = randomDouble();
        upX = randomDouble();
        upY = randomDouble();
        upZ = randomDouble();
        RotateX = 0.0;
        RotateY = 1.0;
        RotateZ = 0.0;
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
    glutMouseFunc(mouseProcess);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(Specialkeyboard);
    
    glutMainLoop();
    return 0;
}
