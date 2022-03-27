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
    char data[CARD_SIZE]; //입력받은 0 또는 1 값을 저장하는 배열
    int think = 0;
    int n, text,i, j, num, k, cnt, set, a;
    char enter;
    int in = 0; //카드 출력 시 카드를 나타내는 변수
    int count, ch;
    GotoXY(30, 10);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    GotoXY(30, 11);
    printf("┃                                                            ┃\n");
    GotoXY(30, 12);
    printf("┃                                                            ┃\n");
    GotoXY(30, 13);
    printf("┃                마술의세계로 당신을 초대합니다              ┃\n");
    GotoXY(30, 14);
    printf("┃                 준비되면 엔터를 눌러주세요                 ┃\n");
    GotoXY(30, 15);
    printf("┃                                                            ┃\n");
    GotoXY(30, 16);
    printf("┃                                                            ┃\n");
    GotoXY(30, 17);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    getchar();
    
    
        system("cls");
        GotoXY(0, 0);
        printf("몇장의 카드를 고르시겠습니까?");
        scanf("%d", &n);
        printf("\n");
        printf("1~%d까지의 숫자 중 하나를 생각해주세요.\n\n", (int)pow(2, n) - 1);
        Sleep(2000);
        for (i = 0; i < n; i++) //카드 장 수
        {
            num = 1; //실제 배열안에 들어가는 숫자
            set = 0;
            for (j = 0; j < (int)pow(2, n); j++) //카드안에 들어갈 숫자
            {
                cnt = num;
                for (k = 0; k < n; k++) //조건맞춰서 넣기
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

        while (in != n) //생각한 숫자의 유무를 배열에 저장
        {
            printf("\n     \t\t\t\t      %c카드\n", code);
            code++;
            printf("┏");
            for (k = 0; k < 10; k++)
            {
                printf("━━━━━━━━");
            }
            printf("┓\n┃");
            count = 0;
            ch = 0;
            for (i = 0; i < (int)pow(2, n - 1); i++)
            {
                if (count == 10)
                {
                    printf("┃\n┃");
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
            printf("┃");
            printf("\n┗");
            for (k = 0; k < 10; k++)
            {
                printf("━━━━━━━━");
            }
            printf("┛\n");
            printf("카드에 생각한 숫자가 있다면 1, 없다면 0을 입력해주세요.");
            scanf("%d", &a);
            data[in] = a;
            in++;
            system("cls");
        }
        for (i = 0; i < n; i++) //배열에 저장된 값을 이진법을 이용해 계산
            think += (int)pow(2, i) * data[i];
        GotoXY(30, 10);
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        GotoXY(30, 11);
        printf("┃                                                            ┃");
        GotoXY(30, 12);
        printf("┃                                                            ┃");
        GotoXY(30, 13);
        printf("┃             당신이 생각한 숫자는 %8d 입니다.          ┃", think);
        GotoXY(30, 14);
        printf("┃                                                            ┃");
        GotoXY(30, 15);
        printf("┃                                                            ┃");
        GotoXY(30, 16);
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
        GotoXY(0, 20);
    
    return 0;
}

