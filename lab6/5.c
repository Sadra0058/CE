#include <stdio.h>
#include <string.h>
#define FALSE 1
#define TRUE 0

int main()
{
    char first_array[70], second_array[70];
    scanf("%s", first_array);
    scanf("%s", second_array);
    if (strcmp(first_array, second_array) == 0)
    {
        printf("True\n");
        printf("length = %i", strlen(first_array));
        return 0;
    }
    else
        printf("False\n");
        strcpy(second_array , first_array);
        printf("first_array = %s \n" , first_array);
        printf("second_array = %s \n" , second_array);
        return 0;
}
