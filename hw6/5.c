#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int avr;
    int num;
    char name[20];
} Student;

int buffer(void)
{
    int output = 0;
    while (getchar() != '\n')
        output = 1;

    return output;
}

void sort(Student array[], int count)
{
    for (int i = 0; i <= count; i++)
    {
        for (int j = i + 1; j <= count; j++)
        {
            if (array[i].avr > array[j].avr)
            {
                Student temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main()
{
    int num = 0;
    printf("enter the number of student: ");
    scanf("%i", &num);
    Student *input = (Student *)malloc(sizeof(Student) * num);

    int counter = 0;
    while (1)
    {
        if (num <= counter)
        {
            num *= 2;
            input = (Student *)realloc(input, sizeof(Student) * (num));
        }

        if (input[counter - 1].num == 0)
        {
            counter--;
            break;
        }
        scanf("%s %i %i", &input[counter].name, &input[counter].num, &input[counter].avr);
        counter++;
    }

    sort(input, counter);
    printf("\n");
    for (int i = 0; i <= counter; i++)
        if (input[i].num != 0)
            printf("%s\n", input[i].name);
}