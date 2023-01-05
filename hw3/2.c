#include <stdio.h>
int digit(int number);
int power(int number, int p);
void chek(int number1, int number2);

int main()
{
   /*get inputs*/
   int number1 = 0;
   int number2 = 0;
   printf("input:\n");
   scanf("%i , %i", &number1, &number2);

   /*Compare two numbers and print the result*/
   printf("output:\n");
   chek(number1, number2);
   return 0;
}

/*function for Calculating the number of digits*/
int digit(int number)
{
   int i = 0;
   for (; number != 0; i++)
   {
      number /= 10;
   }
   return i;
}

/*function for power*/
int power(int number, int p)
{
   if (p == 0)
      return 1;
   int output = number;
   for (int i = 1; i < p; i++)
   {
      output *= number;
   }
   return output;
}

/*Function for comparing two numbers*/
void chek(int number1, int number2)
{
   if (digit(number1) != digit(number2))
   {
      printf("NO\n");
      return;
   }

   for (int i = 0, j = (digit(number1) - 1); i < digit(number1) && j >= 0; i++, j--)
   {
      if ((number1 / power(10, i)) % 10 != (number2 / power(10, j)) % 10)
      {
         printf("NO\n");
         return;
      }
   }
   printf("YES\n");
   return;
}
