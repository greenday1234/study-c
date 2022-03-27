#include <stdio.h>
#include <windows.h>
#include <math.h>
#pragma comment(linker,"/STACK:10737418240") //2GB 2147483648
#define NUMBER_SIZE 16777216
#define CARD_SIZE 25

GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main()
{
    int card[NUMBER_SIZE][CARD_SIZE];
    char data[CARD_SIZE]; //�Է¹��� 0 �Ǵ� 1 ���� �����ϴ� �迭
    int think = 0;
    int n, text,i, j, num, k, cnt, set, a;
    char enter;
    int in = 0; //ī�� ��� �� ī�带 ��Ÿ���� ����
    int count, ch;
    GotoXY(30, 10);
    printf("����������������������������������������������������������������������������������������������������������������������������\n");
    GotoXY(30, 11);
    printf("��                                                            ��\n");
    GotoXY(30, 12);
    printf("��                                                            ��\n");
    GotoXY(30, 13);
    printf("��                �����Ǽ���� ����� �ʴ��մϴ�              ��\n");
    GotoXY(30, 14);
    printf("��                 �غ�Ǹ� ���͸� �����ּ���                 ��\n");
    GotoXY(30, 15);
    printf("��                                                            ��\n");
    GotoXY(30, 16);
    printf("��                                                            ��\n");
    GotoXY(30, 17);
    printf("����������������������������������������������������������������������������������������������������������������������������\n");
    getchar();
    
    
        system("cls");
        GotoXY(0, 0);
        printf("������ ī�带 ���ðڽ��ϱ�?");
        scanf("%d", &n);
        printf("\n");
        printf("1~%d������ ���� �� �ϳ��� �������ּ���.\n\n", (int)pow(2, n) - 1);
        Sleep(2000);
        for (i = 0; i < n; i++) //ī�� �� ��
        {
            num = 1; //���� �迭�ȿ� ���� ����
            set = 0;
            for (j = 0; j < (int)pow(2, n); j++) //ī��ȿ� �� ����
            {
                cnt = num;
                for (k = 0; k < n; k++) //���Ǹ��缭 �ֱ�
                {
                    if (cnt > 0)
                    {
                        data[k] = cnt % 2;
                        cnt /= 2;
                    }
                }
                if (data[i] == 1)
                {
                    card[set][i] = num;
                    set++;
                }
                num++;
            }
        }
        for (i = 0; i < CARD_SIZE; i++)
        {
            data[i] = 0;
        }
        system("cls");
        int code = 65;

        while (in != n) //������ ������ ������ �迭�� ����
        {
            printf("\n     \t\t\t\t      %cī��\n", code);
            code++;
            printf("��");
            for (k = 0; k < 10; k++)
            {
                printf("����������������");
            }
            printf("��\n��");
            count = 0;
            ch = 0;
            for (i = 0; i < (int)pow(2, n - 1); i++)
            {
                if (count == 10)
                {
                    printf("��\n��");
                    count = 0;
                    ch = 0;
                }
                printf("%8d", card[i][in]);
                count++;
                ch++;
            }
            if (ch != 10)
            {
                for (i = ch; i < 10; i++)
                {
                    printf("        ");
                }
            }
            printf("��");
            printf("\n��");
            for (k = 0; k < 10; k++)
            {
                printf("����������������");
            }
            printf("��\n");
            printf("ī�忡 ������ ���ڰ� �ִٸ� 1, ���ٸ� 0�� �Է����ּ���.");
            scanf("%d", &a);
            data[in] = a;
            in++;
            system("cls");
        }
        for (i = 0; i < n; i++) //�迭�� ����� ���� �������� �̿��� ���
            think += (int)pow(2, i) * data[i];
        GotoXY(30, 10);
        printf("����������������������������������������������������������������������������������������������������������������������������");
        GotoXY(30, 11);
        printf("��                                                            ��");
        GotoXY(30, 12);
        printf("��                                                            ��");
        GotoXY(30, 13);
        printf("��             ����� ������ ���ڴ� %8d �Դϴ�.          ��", think);
        GotoXY(30, 14);
        printf("��                                                            ��");
        GotoXY(30, 15);
        printf("��                                                            ��");
        GotoXY(30, 16);
        printf("����������������������������������������������������������������������������������������������������������������������������");
        GotoXY(0, 20);
    
    return 0;
}

