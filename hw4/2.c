#include <stdio.h>
#define SIZE 6
int main()
{
    int input[SIZE];
    int number;
    int bool = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("enter input %i: ", i);
        scanf("%i", &input[i]);
    }
    printf("enter a number: ");
    scanf("%i", &number);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            for (int k = j + 1; k < SIZE; k++)
            {
                if (input[j] > input[k])
                {
                    int npt = input[j];
                    input[j] = input[k];
                    input[k] = npt;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (number <= input[i] && bool == 0)
        {
            printf("%i", number);
            bool = 1;
        }
        printf("%i", input[i]);
    }
}