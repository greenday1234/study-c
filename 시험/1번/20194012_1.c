
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int StackObject;
typedef struct StackRec {
   StackObject item;
   struct StackRec *link;
}StackRec;
void init(StackRec **top) {
   *top = NULL;
}
int is_empty(StackRec **top) {
   return *top == NULL;
}
int is_full(StackRec **top) {
   return 0;
}

void push(StackRec **top, StackObject item) {
   StackRec *temp = (StackRec *)malloc(sizeof(StackRec));

   if (temp == NULL) {
      printf("fail to push\n");
   }
   else {
      temp->item = item;
      temp->link = *top;
      *top = temp;
   }
}

StackObject pop(StackRec **top) {
   if (is_empty(top)) {
      printf("Stack is empty\n");
   }
   else {
      StackRec *temp = *top;
      int item = temp->item;
      *top = (*top)->link;
      free(temp);
      return item;
   }
}

StackObject peek(StackRec **top) {
   if (is_empty(top)) {
      printf("Stack is empty\n");
   }
   else {
      return (*top)->item;
   }
}

int prec(char op) {
   switch (op)
   {
   case '(':
   case ')':
      return 0;
   case '[':
   case ']':
      return 1;
   case '{':
   case '}':
      return 2;
   case '+':
   case '-':
      return 3;
   case '*':
   case '/':
   case '%':
      return 4;
   }
   return -1;
}
void infix_to_postfix(char exp[], char *inpost) {
   StackRec *s;
   char ch, top_op;
   int len = strlen(exp);
   init(&s);
   int cnt = 0;
   for (int i = 0; i < len; i++) {
      ch = exp[i];
      switch (ch) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
         while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
            inpost[cnt++] = pop(&s);
         }
         push(&s, ch);
         break;
      case '(':
      case '[':
      case '{':
         push(&s, ch);
         break;
      case ')':
         top_op = pop(&s);
         if (ch == '(')
            break;
         if (prec(top_op) >= prec(ch)) {
               inpost[cnt++] = top_op;
               top_op = pop(&s);
         }
         break;
      case ']':
         top_op = pop(&s);
         if (ch == '[')
            break;
         if (prec(top_op) >= prec(ch)) {
            inpost[cnt++] = top_op;
            top_op = pop(&s);
         }
         break;
      case '}':
         top_op = pop(&s);
         if (ch == '{')
            break;
         if (prec(top_op) >= prec(ch)) {
            inpost[cnt++] = top_op;
            top_op = pop(&s);
         }
         break;
      default:
         inpost[cnt++] = ch;
         break;
      }

   }
   while (!is_empty(&s))
      inpost[cnt++] = pop(&s);
}

int eval(char *in) {
   int op1, op2, n, value;
   n = strlen(in);
   char ch;
   StackRec *s;
   init(&s);
   for (int i = 0; i < n; i++) {
      ch = in[i];

      if (ch != '+' && ch != '*' && ch != '-' && ch != '/' && ch != '%') {
         value = ch - '0';
         push(&s, value);
      }
      else {
         op2 = pop(&s);
         op1 = pop(&s);
         switch (ch) {
         case '+': push(&s, op1 + op2); break;
         case '-': push(&s, op1 - op2); break;
         case '*': push(&s, op1 * op2); break;
         case '/': push(&s, op1 / op2); break;
         case '%': push(&s, op1 % op2); break;
         }

      }
   }
   return pop(&s);
}

int check_matching(const char *in) {
   StackRec *s;
   char ch, open_ch;
   init(&s);

   int n = strlen(in);

   for (int i = 0; i < n; i++) { 
      ch = in[i];
      switch (ch)
      {
      case '(': case '[': case '{':
         push(&s, ch);
         break;
      case ')':  case ']': case '}':
         if (is_empty(&s))
            return  0;
         else {
            open_ch = pop(&s);
            if (ch != '(' && open_ch == ')' || ch != '[' && open_ch == ']' || ch != '{' && open_ch == '}')
               return 0;
         }
         break;
      }
   }
   if (!is_empty(&s)) 
      return 0;
   return 1;
}


void main() {
   char buf[1024] = { 0 };
   char *postpix[100];
   FILE *fp;
   fp = fopen("data03.txt", "r");
   if (fp == NULL) {
      fprintf(stderr, "파일 열기 실패\n");
      exit(1);
   }
   int result = 0;
   int count = 0;
   while (!feof(fp)) {
      fscanf(fp, "%s", buf);
      count++;
   }
   rewind(fp);
   
   int *index = (int *)malloc(sizeof(int));
   printf("[입력된 수식]\n");
   int x = 1;
   for (int i = 0; i < count; i++) {
      char buffer[1024] = { 0 };
      fscanf(fp, "%s", buf);
      postpix[i] = buf;
      if (check_matching(postpix[i])) {
         printf("<수식>%d\n",x);
         printf("%s\n", postpix[i]);
         infix_to_postfix(postpix[i], buffer);
         printf("결과 : %d\n", eval(buffer));
      }
      else
         printf("옳바르지 않은 수식입니다.\n");
      x++;
   }
   fclose(fp);
}