#include <stdio.h>
#include <stdlib.h>

typedef struct icsp_student icsp_std;
struct icsp_student
{
    char *first_name;
    char *last_name;
    char *student_number;
    float mid_term_exam_score;
    float final_exam_score;
    float homework_score;
    icsp_std * next;
};

icsp_std * f(void)
{
    icsp_std * student = (icsp_std*)malloc(sizeof(icsp_std));
    student->next = NULL;

    return  student;
}

int check(icsp_std * list)
{
    if(list->next == NULL)
    return 1;
    return 0;
}

int main()
{
    icsp_std * head = f();
    head->next = f();
    printf("%i\n" , check(head));
    printf("%i\n" , check(head->next));
}