#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <random>
#include <GLUT/glut.h>
//RGB 색상
int red = 255, green = 255, blue = 255;
GLfloat angle = 0.0f;   //회전각도
int click = 0;  //마우스 클릭
int count = -1; //스페이스바 누르기

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

//회전 함수
void idleProcess() {
    //오른쪽 마우스를 누르지 않은 경우
    if(click == 0){
        angle += 0.005f;
        if(angle > 360.0)
            angle = 0.0f;
    }
    //오른쪽 마우스를 한 번 누른 경우(시계방향)
    else if(click%2 != 0 && click != -1){
        angle -= 0.005f;
        if (angle > 360.0)
            angle = 0.0f;
    }
    //오른쪽 마우스를 두 번 누른 경우(반시계방향)
    else if(click%2 == 0 && click != 0){
        angle += 0.005f;
        if(angle > 360.0)
            angle = 0.0f;
    }
    else if(click == -1){
        //스페이스바를 한 번 누른 경우
        if(count == 0){
            angle = 0;
        }
        //스페이스바를 두 번 누른 경우
        else if(count%2 != 0 && count != -1){
            angle -= 0.5f;
            count = -1;
            if (angle > 360.0)
                angle = 0.0f;
        }
    }
    glutPostRedisplay();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glRotatef(angle, 0, 0, 1);  //회전
    
    glColor3ub(red, green, blue);   //색 설정
    
    glBegin(GL_POLYGON);    //삼각형1 생성
    glVertex2f(-3, 0);
    glVertex2f(3, 1);
    glVertex2f(0, -1);
    glEnd();

    glBegin(GL_POLYGON);    //삼각형2 생성
    glVertex2f(0, 3);
    glVertex2f(-1, -3);
    glVertex2f(1, 0);
    glEnd();
    
    glBegin(GL_POLYGON);    //삼각형3 생성
    glVertex2f(0, 3);
    glVertex2f(2, -2.5);
    glVertex2f(-0.4, -0.4);
    glEnd();
    
    glFlush();
    
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h); //화면 비율 맞추기
    float WidthFactor = (float)w / 500.0;
    float HeightFactor = (float)h / 500.0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    //행렬 초기화
    gluOrtho2D(-5.0*WidthFactor, 5.0*WidthFactor, -5.0*HeightFactor, 5.0*HeightFactor);
}

void keyboardProcess(unsigned char key, int x, int y) {
    switch (key) {
        case ' ':   //스페이스바 누르기
        {
            click = -1;
            count++;
            break;
        }
        case '\e':  //esc누르기
        {
            exit(1);
        }
    }
}

void mouseProcess(int button, int state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //왼쪽 마우스 클릭
        //색상 초기화
        red = rand()%255+1;
        green = rand()%255+1;
        blue = rand()%255+1;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {   //오른쪽 마우스 클릭
        click++;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("20194012 이찬희 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardProcess);
    glutMouseFunc(mouseProcess);
    glutIdleFunc(idleProcess);
    glutMainLoop();
    return 0;
}
