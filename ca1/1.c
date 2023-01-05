#include <stdio.h>

int main()
{
    /*get number*/
    int number = 0;
    printf("input:\n");
    scanf("%i", &number);
    /*Calculating roomnumber*/
    int roomnum = number % 100;
    /*Calculating floornumber*/
    int floor = (number - roomnum) / 100;

    /*get the height of the first jump*/
    float firstjump = 0;
    scanf("%f", &firstjump);

    printf("output: \n");

    /*print area*/
    if (1 <= roomnum && roomnum <= 4)
    {
        printf("1\n");
    }

    if (5 <= roomnum && roomnum <= 8)
    {
        printf("2\n");
    }

    if (9 <= roomnum && roomnum <= 12)
    {
        printf("3\n");
    }

    if (13 <= roomnum && roomnum <= 16)
    {
        printf("4\n");
    }

    /*Calculating min jump height*/
    int height = (floor * 2) + 1;

    /*print The number of jumps*/
    int output = 0;
    for (int i = 1; (firstjump / 2 * i) + firstjump < height; i++)
    {
        output = i;
    }
    printf("%i", ++output);
}