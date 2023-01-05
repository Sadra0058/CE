#include <stdio.h>

int main()
{
    /*define food array*/
    int food[] = {329, 127, 61, 83, 156, 296, 496, 73, 34, 16};
    /*get number of days*/
    int day = 0;
    printf("input:\n");
    scanf("%i", &day);

    /*Calculating calory*/
    int cal = 0;
    for (int i = 0; i < day; i++)
    {
        int foodnum = 0;
        scanf("%i", &foodnum);
        cal += (food[foodnum - 1] - 100);
    }

    /*print output*/
    printf("output:\n");
    if (cal < 0)
    {
        printf("lagahr");
    }

    else if (cal > 0)
    {
        printf("chagh");
    }

    else if (cal == 0)
    {
        printf("bedoon taghir");
    }
}