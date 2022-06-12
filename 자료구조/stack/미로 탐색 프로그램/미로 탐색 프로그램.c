#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 6

typedef struct{
    short r;
    short c;
}element;

typedef struct {
	element data[MAZE_SIZE];
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
}
int is_empty(StackType *s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
 int is_full(StackType *s) {
	if (s->top == MAZE_SIZE - 1)
		return 1;
	else
		return 0;
}
void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	return (s->data[(s->top)--]);
}
element peek(StackType *s) {
	return s->data[s->top];
}

element here = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

void push_loc(StackType *s, int r, int c){  //위치를 스택에 삽입
    if(r<0 || c<0)  //현재 위치가 미로 안에 없을 경우
    return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){ //벽이나 왔던 길이 아닌 경우(갈 수 있는 길)
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s,tmp);    //갈 수 있는 길을 스택에 push
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){   //미로 출력
    printf("\n");
    for(int r=0;r<MAZE_SIZE;r++){   //행
        for(int c = 0;c<MAZE_SIZE;c++){ //열
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(){
    int r,c;
    StackType s;
    init_stack(&s);

    while(maze[here.r][here.c] != 'x'){ //도착지점에 도착할 떄까지 반복
        r = here.r; //행
        c = here.c; //열
        maze[r][c] = '.';   //현재 위치를 .으로 변경
        maze_print(maze);
        //갈 수 있는 길을 스택에 push
        push_loc(&s, r-1,c);    //왼쪽으로 가기 
        push_loc(&s, r+1,c);    //오른쪽으로 가기
        push_loc(&s, r,c-1);    //아래로 가기
        push_loc(&s, r,c+1);    //위로 가기

        if(is_empty(&s)){   //도착지점에 도착하기 전에 스택이 빌 경우
            printf("실패\n");
            exit(1);
        }
        else
            here = pop(&s);
    }
    printf("성공\n");
    return 0;
}