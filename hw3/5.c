#include <stdio.h>
int fib(int number);
int main()
{
    /*get input*/
    int number;
    printf("input:\n");
    scanf("%i", &number);
    /*Print the Fibonacci sequence for number*/
    printf("output:\n");
    printf("%i", fib(number));
}
/*Fibonacci sequence for number*/
int fib(int number)
{
    if (number == 1)
        return 0;
    if (number == 2 || number == 3)
        return 1;
    return (fib(number - 1) + fib(number - 2));
}