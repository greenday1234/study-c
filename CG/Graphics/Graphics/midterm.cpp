//
//  midterm.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/14.
//
#define GL_SILENCE_DEPRECATION
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#pragma warning(disable : 4996)

int Width = 500;    //창의 넓이를 저장해주는 변수
int Height = 500;    //창의 높이를 저장해주는 변수
int check = 0;        //도형 만들기의 상태를 지정해주는 변수
/* check가 0이면 점을 찍는 상태, 1이면 도형을 생성한 상태. 2이면 드래그로 지정된 상태, 3이면 드래그중인 상태*/
float max_width, min_width, max_height, min_height;    //도형의 최대 최소 넓이와 높이값을 저장해주는 변수
float drag_x, drag_y;    //드래그를 할 때 사용하는 변수
float mouse_locate[3];    //마우스의 현재 위치를 저장하는 변수
float spin = 0;            //회전을 할 때 쓰이는 변수

typedef struct {            //연결리스트에서 쓰일 자료형/
    float vertex[3];
    int num;
}element;

typedef struct PointNode {    //연결리스트 구조 생성
    element data;
    struct PointNode* link;
}PointNode;

PointNode* head = NULL;        //헤드포인터를 전역변수로 설정

PointNode* Add_Node(PointNode* head, element value) { //연결리스트에 새로운 노드를 추가해주는 함수
    PointNode* p = (PointNode*)malloc(sizeof(PointNode));
    if (head == NULL) {        //도형의 넓이와 높이의 최대 최소값 저장
        max_width = value.vertex[0];
        min_width = value.vertex[0];
        max_height = value.vertex[1];
        min_height = value.vertex[1];
    }
    else {
        if (value.vertex[0] > max_width) max_width = value.vertex[0];
        if (value.vertex[0] < min_width) min_width = value.vertex[0];
        if (value.vertex[1] > min_height) max_height = value.vertex[1];
        if (value.vertex[1] < min_height) min_height = value.vertex[1];

        value.num = head->data.num + 1;    //첫번째 점이 아니라면 이전 점의 숫자에 1을 더해서 저장
    }
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void Init_Node() {    //연결리스트의 동적할당을 해제해주는 함수
    PointNode* next;
    for (PointNode* p = head; p != NULL;) {
        next = p->link;
        free(p);
        p = next;
    }
    head = NULL;    //헤드포인터를 널로 설정
}

void draw_points() {    //점을 찍어주는 함수
    glColor3f(1.0, 1.0, 0.0);    //노란색으로 지정
    glPointSize(5);                //크기는 5/

    glBegin(GL_POINTS);            //연결리스트를 따라 점을 찍음
    for (PointNode* p = head; p != NULL; p = p->link) {
        glVertex3fv(p->data.vertex);
    }
    glEnd();
}

void draw_num() {    //숫자를 그려주는 함수
    int size = 1;    //문자열의 크기를 저장해줄 변수
    char* number;    //문자를 저장해줄 포인터 변수
    for (int temp = head->data.num; temp > 0; size++) temp *= 0.1;//숫자의 자릿수를 구해 문자열의 크기에 저장
    glColor3f(1.0, 1.0, 1.0);    //흰색으로 지정
    number = (char*)malloc(sizeof(char) * size);    //문자열의 크기에 따라 동적할당
    for (PointNode* p = head; p != NULL; p = p->link) {
        float locate[3] = { p->data.vertex[0], p->data.vertex[1] + 5, p->data.vertex[2] }; //문자열의 위치를 지정해주는 변수
        itoa(p->data.num, number, 10);    //정수를 문자열로 변환
        glRasterPos3fv(locate);            //문자열의 위치 지정
        for (int i = 0; i < size; i++) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, number[i]); //문자  출력
    }
}

void draw_line() {    //선을 그려주는 함수
    glColor3f(1.0, 1.0, 1.0);    //흰색으로 지정
    glLineWidth(2.5);            //굵기는 2.5
    glBegin(GL_LINE_STRIP);        //연결리스트를 따라 선을 그림
    if (check == 0) glVertex3fv(mouse_locate);    //check가 0이면 마우스를 따라 움직이는 선을 그어줌
    for (PointNode* p = head; p != NULL; p = p->link)
        glVertex3fv(p->data.vertex);
    glEnd();
}

void draw_poly() {    //도형을 그려주는 함수
    if (check == 2) glColor3f(1.0, 0.7, 0.0);    //check가 2이면 주황색으로 지정
    else glColor3f(1.0, 1.0, 0.0);                //아니면 노란색으로 지정
    //드래그가 된 상태인지 알아보기 쉽게 하기 위해 이렇게 함
    glBegin(GL_POLYGON);    //연결리스트에 저장된 좌표들을 따라 도형을 그려줌
    for (PointNode* p = head; p != NULL; p = p->link)
        glVertex3fv(p->data.vertex);
    glEnd();
}

void dragging() {    //드래그를 눈에 보여주는 함수
    //좌표 지정(드래그를 시작했을 때와 현재의 좌표를 이용하여 지정함)
    float v1[3] = { drag_x, drag_y, 0.0 };
    float v2[3] = { mouse_locate[0], drag_y, 0.0 };
    float v3[3] = { mouse_locate[0], mouse_locate[1], 0.0 };
    float v4[3] = { drag_x, mouse_locate[1], 0.0 };

    glColor3f(1.0, 1.0, 1.0);    //흰색으로 지정
    glLineWidth(1.0);            //굵기는 1
    glBegin(GL_LINE_STRIP);        //좌표에 따라 선을 그음
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glVertex3fv(v4);
    glVertex3fv(v1);
    glEnd();
}

void Draw() {    //엔티티들을 그려주는 함수
    int x = (max_width - min_width) / 2 + min_width;    //현재 도형의 x좌표 계산
    int y = (max_height - min_height) / 2 + min_height;    //현재 도형의 y좌표 계산
    glPushMatrix();    //스택을 만들어줌
    if (check == 2) glTranslatef(mouse_locate[0] - x, mouse_locate[1] - y, 0.0);
    //check가 2이면 도형이 마우스를 따라 움직임
    glTranslatef(x, y, 0.0);    //제자리로 이동
    glRotatef(spin, 0, 0, 1);    //z축을 기준으로 회전
    glTranslatef(-x, -y, 0.0);    //원점으로 이동

    if (check == 0) {        //check가 0이면
        draw_points();    //점을 찍고
        draw_line();    //선을 그려줌
        if (head != NULL) draw_num();//헤드포인터가 널이 아니면 숫자 출력
    }
    if (check != 0) draw_poly();    //check가 0이 아니면 도형을 그려줌
    if (check == 3) dragging();    //check가 3이면 드래그 실행
    glPopMatrix();
}

void Spin_Poly() {    //도형을 회전시켜주는 함수
    check = 2;        //check를 2로 지정해줌
    spin += 0.05;    //spin값에 변화를 주어 회전 실행
    if (spin > 360.0) spin -= 360;    //360이 넘어가면 360을 빼줌
    glutPostRedisplay();    //바뀐 화면 표시
}

void mouseProcess(int button, int state, int x, int y) {    //마우스 작동함수
    element temp = { {x, Height - y, 0.0}, 0 };    //정보들 저장
    switch (button) {
    case GLUT_LEFT_BUTTON:        //왼쪽 버튼의 상태가 변하면
        if (state == GLUT_DOWN) {    //눌린상태라면
            if (check == 0) head = Add_Node(head, temp);    //check가 0이면 새로운 점 추가
            else if (check == 1) {    //check가 1이면
                drag_x = x; drag_y = Height - y;    //드래그 좌표 지정
                check = 3;                            //check를 3으로 지정해 드래그 실행
            }
        }
        else if (state == GLUT_UP) {    //떼진 상태라면
            if (check == 3) {            //check가 3이면
                int max_x, min_x, max_y, min_y;
                //드래그 된 부분의 좌표를 저장할 변수 선언
                //어느 좌표가 더 위에있고 더 오른쪽으로 갔는지 파악 후 각 상황에 맞게 저장
                if (drag_x > mouse_locate[0]) {
                    max_x = drag_x;
                    min_x = mouse_locate[0];
                }
                else {
                    max_x = mouse_locate[0];
                    min_x = drag_x;
                }

                if (drag_y > mouse_locate[1]) {
                    max_y = drag_y;
                    min_y = mouse_locate[1];
                }
                else {
                    max_y = mouse_locate[1];
                    min_y = drag_y;
                }
                //도형이 드래그 된 부분의 안에 있으면 회전이동 실행(아이들함수 이용)
                if ((max_x > max_width) && (min_x < min_width) && (max_y > max_height) && (min_y < min_height)) glutIdleFunc(Spin_Poly);
                check = 1; //check상태를 1로 다시 바꿔줌
            }
        }
        break;
    case GLUT_MIDDLE_BUTTON:    //가운데 버튼의 상태가 변하면
        if (state == GLUT_DOWN) {    //만약 눌린거라면
            Init_Node();        //노드를 초기화시켜주고
            glutIdleFunc(NULL);    //회전이동 멈춤
            spin = 0;            //회전각 초기화 시킴
            check = 0;            //check 0으로 설정
        }
        break;
    case GLUT_RIGHT_BUTTON:            //오른족 버튼의 상태가 변하면
        if (state == GLUT_DOWN)check = 1;    //check를 1로 바꿔줌
        break;
    }
    glutPostRedisplay();        //바뀐 화면 표시
}

void motionProcess(int x, int y) {    //마우스가 움직일 때 쓰는 함수
    mouse_locate[0] = x;            //mouse_locate배열에 현재 마우스의 위치 저장
    mouse_locate[1] = Height - y;
    mouse_locate[2] = 0;
    glutPostRedisplay();        //바뀐 화면 표시
}

void display(void) {                    //디스플레이 함수
    glClear(GL_COLOR_BUFFER_BIT);    //컬러버퍼 초기화
    Draw();                            //Draw함수 실행
    glutSwapBuffers();                //더블 버퍼 사용하기 때문에 버퍼를 스왑해줌
}

void init() {                            //초기화함수
    glClearColor(0.0, 0.0, 0.0, 0.0);    //배경색을 검은색으로
    glMatrixMode(GL_PROJECTION);        //투상행렬로 지정
    glLoadIdentity();                    //단위행렬로 초기화
    gluOrtho2D(0.0, Width, 0.0, Height);//좌표계 영역 지정
}

void reshape(int w, int h) {
    Width = w;
    Height = h;
    glViewport(0.0, 0.0, Width, Height);    //뷰포트를 현재의 넓이와 높이값에 맞춤
    glMatrixMode(GL_PROJECTION);            //투상행렬로 지정
    glLoadIdentity();                        //단위행렬로 초기화
    gluOrtho2D(0.0, Width, 0.0, Height);     //좌표계 영역 재지정
}

int main(int argc, char** argv) {    //메인함수
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //더블버퍼로 디스플레이모드 설정
    glutInitWindowSize(Width, Height);                //윈도우창 크기 지정
    glutInitWindowPosition(300, 300);                //윈도우창 위치 지정
    glutCreateWindow("Midterm Project");            //윈도우창 이름 지정
    init();                                            //초기화

    glutDisplayFunc(display);                        //디스플레이함수
    glutReshapeFunc(reshape);                        //리셰이프함수
    glutMouseFunc(mouseProcess);                    //마우스 함수
    glutPassiveMotionFunc(motionProcess);            //마우스 안눌리고 움직일 때 함수
    glutMotionFunc(motionProcess);                    //마우스 눌리고 움직일 떄 함수
    glutMainLoop();

    return 0;
}
