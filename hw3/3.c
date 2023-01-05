#include <stdio.h>
void chek(int hour);
int main()
{
    /*get input*/
    int h;
    printf("input:\n");
    scanf("%i", &h);
    /*check workers and print the result*/
    printf("output:\n");
    chek(h);
    return 0;
}

/*function for checking workers*/
void chek(int hour)
{
    int day = 0;
    for (; hour >= 24; day++)
    {
        hour -= 24;
    }

    if (day % 2 == 0)
    {
        if (hour < 12)
        {
            printf("A");
            return;
        }
        else
        {
            printf("B");
            return;
        }
    }

    else
    {
        if (hour < 12)
        {
            printf("C");
            return;
        }
        else
        {
            printf("D");
            return;
        }
    }
}