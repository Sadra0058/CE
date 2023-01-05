#include <stdio.h>

int main()
{
    /*get Coefficients*/
    int a = 0;
    int b = 0;
    int c = 0;
    printf("input:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);

    /*Calculating the biggest Coefficient*/
    int biggest = 0;
    if (a >= b)
    {
        if (a >= c)
        {
            biggest = a;
        }
        else
        {
            biggest = c;
        }
    }
    else
    {
        if (b >= c)
        {
            biggest = b;
        }
        else
        {
            biggest = c;
        }
    }

    /*get input*/
    double input = 0;
    scanf("%lf", &input); 
       
    /*define max,min of input*/
    double max = (biggest * biggest);
    double min = -(biggest * biggest);
    double x = min;

    /*Calculating the roots and print them*/
    printf("output:\n");
    int j = 3;
    for (; min <= x && x <= max; x += input)
    {
        if ((((x * x * x) + (a * x * x) + (b * x) + c) * (((x + input) * (x + input) * (x + input)) + (a * (x + input) * (x + input)) + (b * (x + input)) + c)) <= 0)
        {
            printf("%.4lf\n", x + input);
            j--;
        }
    }

    for (; j > 0; j--)
    {
        printf("bedoon rishe\n");
    }
}