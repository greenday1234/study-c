#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct class {
   int class;
   char name[100];
}Class;

typedef struct student {
   char name[100];
   int class;
   int class_n;
   int math;
   int korean;
   int english;
}Student;

typedef struct ListNode_Class {
   Class class;
   struct ListNode_Class *link;
}ListNode_Class;

typedef struct ListNode_Student {
   Student student;
   struct ListNode_Student *link;
}ListNode_Student;

ListNode_Class*insert_last_class(ListNode_Class *head, Class cl) {
   ListNode_Class *temp = (ListNode_Class*)malloc(sizeof(ListNode_Class));
   ListNode_Class *p = head;
   temp->class = cl;
   temp->link = NULL;
   if (head == NULL) {
      head = temp;
   }
   else {
      while (p->link) {
         p = p->link;
      }
      p->link = temp;
   }

   return head;
}

ListNode_Student* insert_last_student(ListNode_Student *head, Student st) {
   ListNode_Student *temp = (ListNode_Student*)malloc(sizeof(ListNode_Student));
   ListNode_Student *p = head;
   temp->student = st;
   temp->link = NULL;
   if (head == NULL) {
      head = temp;
   }
   else {
      while (p->link) {
         p = p->link;
      }
      p->link = temp;
   }

   return head;
}

void print_class(ListNode_Class *ch, ListNode_Student *sh) {
   ListNode_Class *cp = ch;
   ListNode_Student *sp = sh;
   while (cp) {
      printf("<%d반>\n", cp->class.class);
      printf("담임선생님 : %s\n", cp->class.name);
      printf("|======|========|======|======|======|\n");
      printf("| 번호 |  이름  | 수학 | 국어 | 영어 |\n");
      printf("|======|========|======|======|======|\n");
      while (sp) {
         if (cp->class.class == sp->student.class) {
            printf("| %3d  | %6s | %3d  | %3d  | %3d  |\n",
             sp->student.class_n, sp->student.name, sp->student.math, sp->student.korean, sp->student.english);
         }
         sp=sp->link;
      }
      sp = sh;
      printf("|======|========|======|======|======|\n");
      cp = cp->link;
      printf("\n");
   }
}

void delete_class(ListNode_Class *head) {
   ListNode_Class *p = head;
   while (p != NULL) {
      ListNode_Class* removed = p;
      p = p->link;
      free(removed);
   }
}

void delete_student(ListNode_Student *head) {
   ListNode_Student *p = head;
   while (p != NULL) {
      ListNode_Student* removed = p;
      p = p->link;
      free(removed);
   }
}

void main() {
   char buf[100];
   Class cl;
   Student st;
   ListNode_Class*class_head = NULL;
   ListNode_Student*student_head = NULL;
   FILE *fp = fopen("data03.txt", "r");
   if (fp == NULL) {
      printf("파일 열기 실패");
      return;
   }
   fscanf(fp, "%s", buf);
   while (!feof(fp)) {
      if (strcmp(buf, "class")==0) {
         while (!feof(fp)) {
            fscanf(fp, "%s", buf);
            if (strchr(buf, 's') || strchr(buf, 'c'))
               break;
            cl.class = atoi(buf);
            fscanf(fp, "%s", buf);
            strcpy(cl.name, buf);
            class_head=insert_last_class(class_head, cl);
         }
      }
      else if (strcmp(buf, "student")==0) {
         while (!feof(fp)) {
            fscanf(fp, "%s", buf);
            if (strchr(buf, 's') || strchr(buf, 'c'))
               break;
            strcpy(st.name, buf);
            fscanf(fp, "%d", &st.class);
            fscanf(fp, "%d", &st.class_n);
            fscanf(fp, "%d", &st.math);
            fscanf(fp, "%d", &st.korean);
            fscanf(fp, "%d", &st.english);
            student_head = insert_last_student(student_head, st);
         }
      }
   }

   print_class(class_head, student_head);
   fclose(fp);
   delete_class(class_head);
   delete_student(student_head);
}