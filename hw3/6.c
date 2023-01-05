#include <stdio.h>
void date(int n);
int main()
{
    /*get input*/
    int day = 0;
    printf("input:\n");
    scanf("%i", &day);
    /*calculate date and print result*/
    printf("output:\n");
    date(day);
    return 0;
}

/*Function for calculating date*/
void date(int n)
{
    int mounth = 1;
    int day = n + 1;
    int year = 1300;

    while (day > 31)
    {
        for (int i = 0; day > 31 && i < 6; i++)
        {
            day -= 31;
            mounth++;
        }

        for (int i = 0; day > 30 && i < 5; i++)
        {
            day -= 30;
            mounth++;
        }

        for (int i = 0; day > 29 && i < 1; i++)
        {
            day -= 29;
            mounth++;
        }

        if (mounth > 12)
        {
            mounth = 1;
            year++;
        }
    }

    printf("%i.%i.%i", year, mounth, day);
    return;
}