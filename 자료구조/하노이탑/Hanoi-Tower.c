#include <stdio.h>
#include <stdlib.h>

void hanoi_tower(int n, char from, char tmp, char to){
    if(n == 1){
        printf("원판1을 %c에서 %c로 이동\n", from, to);
    }
    else{
        hanoi_tower(n-1,from, to, tmp);
        printf("원판 %d을 %c 에서 %c로 이동\n", n, from, to);
        hanoi_tower(n-1,tmp,from,to);
    }
}
int main()
{
    hanoi_tower(4,'A','B','C');
    return 0;
}