#include <stdio.h>
void prime(int number);
int main()
{
    /*get input*/
    int number;
    printf("input: \n");
    scanf("%i", &number);
    /*print prime numbers*/
    printf("output:\n");
    prime(number);
}

void prime(int number)
{
    if (number > 2)
        printf("2 ");
    /*check number to be Prime number*/
    for (int i = 3; i < number; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }

            else if (j == i - 1)
            {
                printf("%i ", i);
            }
        }
    }
    return;
}