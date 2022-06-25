#include <Stdio.h>
#include <Stdlib.h>
#include <string.h>

typedef int StackObject;

typedef struct StackRec{
    StackObject item;
    struct StackRec *link;
}StackRec;

void initialize(StackRec **top){
    *top = NULL;
}

int isEmpty(StackRec **top){
    return (*top == NULL);
}

void push(StackRec **top, StackObject item){
    StackRec *temp = (StackRec*)malloc(sizeof(StackRec));

    if(temp == NULL)
    fprintf(stderr,"fail to push\n");
    else{
        temp->item = item;
        temp->link = *top;
        *top = temp;
    }
}
StackObject pop(StackRec **top){
    if(isEmpty(&top))
    fprintf(stderr,"stack is empty\n");
    else{
        StackRec *temp = *top;
        int item = temp->item;
        *top = (*top)->link;
        free(temp);
        return item;
    }
}
StackObject peek(StackRec **top){
    if(isEmpty(&top))
    fprintf(stderr,"stack is empty\n");
    else {
        return (*top)->item;
    }
}

int prec(int op){
    switch(op){
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

//중위 -> 후위
void infix_to_postfix(char exp[], char *inpost){
    StackRec *top;
    int len = strlen(exp);
    int i = 0;
    int cnt = 0;
    char ch, top_op;
    initialize(&top);

    for(i = 0;i<len;i++){
        ch = exp[i];
        switch(ch){
            case '+':
            case '-':
            case '*':
            case '/':
            while(!isEmpty(&top) && (prec(ch) <= prec(peek(&top)))){
                inpost[cnt++] = pop(&top);
            }
            push(&top, ch);
            break;

            case '(':   //무조건 Stack에 push
            push(&top,ch);
            break;

            case ')':   //여는 괄호가 나올떄까지 pop
            top_op = pop(&top);
            inpost[cnt++] = top_op;
            top_op = pop(&top);
            break;

            default:    //피연산자
            inpost[cnt++] = ch;
            break;
        }
    }
    while(!isEmpty(&top)){
        inpost[cnt++] = pop(&top);
    }
}

int eval(char exp[]){
    StackRec *top;
    int op1, op2;
    int len = strlen(exp);
    int value;
    char ch;
    initialize(&top);

    for(int i=0; i<len; i++){
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){   //피연산자
            value = ch - '0';   //char -> int
            push(&top, value);
        }
        else{   //연산자
            op2 = pop(&top);
            op1 = pop(&top);

            switch(ch){
                case '+':
                    push(&top, op1 + op2);
                    break;
                case '-':
                    push(&top, op1 - op2);
                    break;
                case '*':
                    push(&top, op1 * op2);
                    break;
                case '/':
                    push(&top, op1 / op2);
                    break;
            }
        }
    }
    return pop(&top);
}

int main(){
    char buf1[] = "(2+3)*4+9";
    char buf2[] = "(1+5)*(3-2)";
    char buf3[] = "5*2+3+(4-2)";
    char buf4[1024] = {0};
    int result;

    printf("중위표기식 %s\n", buf1);
    infix_to_postfix(buf1,buf4);
    printf("후위표기식 %s\n", buf4);
    result = eval(buf4);
    printf("결과값은 %d\n", result);

    printf("중위표기식 %s\n", buf2);
    infix_to_postfix(buf2,buf4);
    printf("후위표기식 %s\n", buf4);
    result = eval(buf4);
    printf("결과값은 %d\n", result);

    printf("중위표기식 %s\n", buf3);
    infix_to_postfix(buf3,buf4);
    printf("후위표기식 %s\n", buf4);
    result = eval(buf4);
    printf("결과값은 %d\n", result);
    
    return 0;
}