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

char *read_line_from_input_file(FILE *input)
{
    int line_length = ZERO;
    char *line = (char *)malloc(sizeof(char));
    *(line) = '0';
    char temp_char[1] = {' '};
    while (true)
    {
        fread(temp_char, sizeof(char), ONE, input);
        line_length++;
        line = (char *)realloc(line, sizeof(char) * line_length);
        line[line_length - ONE] = NULL;
        switch (temp_char[ZERO])
        {
        case '\n':
            return line;
            break;
        case EOF:
            return line;
            break;
        default:
            line[line_length - ONE] = temp_char[ZERO];
            break;
        }
    }
}

icsp_std **read_students_credentials_from_file(char *file_name)
{
    FILE *input;
    if (input = fopen(file_name, "r"))
    {
        int num_of_lines = atoi(read_line_from_input_file(input));
        icsp_std **students = (icsp_std **)malloc(sizeof(icsp_std *) * num_of_lines);
        for (int i = 0; i < num_of_lines; i++)
        {
            icsp_std *std = (icsp_std *)malloc(sizeof(icsp_std));
            std->first_name = read_line_from_input_file(input);
            std->last_name = read_line_from_input_file(input);
            std->student_number = read_line_from_input_file(input);
            std->mid_term_exam_score = atof(read_line_from_input_file(input));
            std->final_exam_score = atof(read_line_from_input_file(input));
            std->homework_score = atof(read_line_from_input_file(input));
            // Somthing is missing. find it! <<-----------------------------------------------------------------------------------------------------<<
            students[i] = std;
        }
        
        fclose(input);
        return students;
    }
    return NULL;
}

int main()
{
    icsp_std ** std =  read_students_credentials_from_file("input.txt");
    
    icsp_std *head = (icsp_std *)malloc(sizeof(icsp_std));
    icsp_std *new1 = (icsp_std *)malloc(sizeof(icsp_std));
    icsp_std *new2 = (icsp_std *)malloc(sizeof(icsp_std));
    set_new_std_next_of_head(head , new2);
    add_to_i(head , new1 , 1);
    icsp_std * temp = head;
    int i = 0;
    while(temp != NULL)
    {
        temp->first_name = std[i]->first_name;
        temp->last_name = std[i]->last_name;
        temp->student_number = std[i]->student_number;
        temp->mid_term_exam_score = std[i]->mid_term_exam_score;
        temp->final_exam_score = std[i]->final_exam_score;
        temp->homework_score = std[i]->homework_score;
        temp = temp->next;
        i++;
    }

    printf("%s\n" , head->first_name);
    printf("%s\n" , head->next->first_name);
    printf("%s\n" , head->next->next->first_name);
    free(head);   
    free(new1);
    free(new2);
}