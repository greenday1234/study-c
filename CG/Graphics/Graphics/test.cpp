#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

float zoomFactor = 1.0f; // 초기 줌 인/줌 아웃 값

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 뷰 변환 업데이트
    glScalef(zoomFactor, zoomFactor, 1.0f); // X, Y 축 스케일링

    // 장면 그리기
    glColor3f(1.0, 1.0, 1.0);
    glutWireSphere(0.04, 20, 15);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'w':
            move_z -= 10;
            glutPostRedisplay();
            cout << "z : "<< move_z << endl;
            break;
        case 's':
            move_z += 10;
            glutPostRedisplay();
            cout << "z : "<< move_z << endl;
            break;
        case 'a':
            move_x -= 10;
            glutPostRedisplay();
            cout << "x : "<< move_x << endl;
            break;
        case 'd':
            move_x += 10;
            glutPostRedisplay();
            cout << "x : "<< move_x << endl;
            break;
        case 'k':
            move_y += 10;
            glutPostRedisplay();
            cout << "y : "<< move_y << endl;
            break;
        case 'm':
            move_y -= 10;
            glutPostRedisplay();
            cout << "y : "<< move_y << endl;
            break;
            
        default:
            break;
    }
}

void specialKeyboard(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            zoomFactor *= 1.1f; // 줌 인
            break;
        case GLUT_KEY_DOWN:
            zoomFactor /= 1.1f; // 줌 아웃
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Zoom");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyboard);
    glutMainLoop();

    return 0;
}
