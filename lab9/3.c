#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
#define true 2

typedef struct icsp_student icsp_std;
struct icsp_student
{
    char *first_name;
    char *last_name;
    char *student_number;
    float mid_term_exam_score;
    float final_exam_score;
    float homework_score;
    icsp_std *next;
};

int set_new_std_next_of_head(icsp_std *head_of_list, icsp_std *new_std)
{
    if (new_std == NULL || head_of_list == NULL)
        return 0;
    head_of_list->next = new_std;
    new_std->next = NULL; /*head_of_list->next;*/
    return 1;
}

int add_to_i(icsp_std *head_of_list, icsp_std *new_std, int i)
{
    if (head_of_list == NULL)
        return ZERO;
    icsp_std *current_std = head_of_list->next;
    if (current_std == NULL && i == ZERO)
    {
        new_std->next = head_of_list;
        return ONE;
    }
    else if (current_std == NULL && i != ZERO)
    {
        return ZERO;
    }
    int counter = ZERO;
    while (true)
    {
        if (counter == i)
        {
            new_std->next = head_of_list;
            new_std->next = current_std;
            return ONE;
        }
        counter++;
        if (current_std->next == NULL && counter == i)
        {
            head_of_list->next = new_std;
            new_std->next = current_std;
            return ONE;
        }
        if (current_std->next == NULL && counter < i)
        {
            return ZERO;
        }
        current_std = current_std->next;
    }
}

int main()
{
    icsp_std *head = (icsp_std *)malloc(sizeof(icsp_std));
    icsp_std *new1 = (icsp_std *)malloc(sizeof(icsp_std));
    icsp_std *new2 = (icsp_std *)malloc(sizeof(icsp_std));

    head->next = NULL;
    
    
    printf("%p\n" , head);
    printf("%p\n" , new1);
    printf("%p\n" , new2);

    printf("\n");
    if (add_to_i(head, new1 , 0) == 1)
    {
    printf("%p\n" , new1);
    printf("%p\n" , new1->next);
    printf("%p\n" , new1->next->next);
    }
}
