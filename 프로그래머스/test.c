#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(const char *s){
    int n = strlen(s);
    if(n%2 == 0){
        char * answer = (char*)malloc(2);
        answer[0] = s[n/2 - 1];
        answer[1] = s[n/2];
        return answer;
    }
    else{
        char * answer = (char*)malloc(1);
        answer[0] = s[n/2];
        return answer;
    }
}
int main(){
    char s[100];
    scanf("%s", s);
    printf("%s", solution(s));
    return 0;
    
}