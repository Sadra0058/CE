#include <stdio.h>
#define FALSE 1
#define TRUE 0
int strlen(char *string);
int compare(char *first_array, char *second_array);

int main()
{
    char first_array[70], second_array[70];
    scanf("%s", first_array);
    scanf("%s", second_array);
    if (compare(first_array, second_array) == TRUE)
        printf("True");
    else
        printf("False");
}

int compare(char *first_array, char *second_array)
{
    int counter = 0;
    for (int i = 0; first_array[i] != '\0'; i++, ++counter)
    {
        int j = i;
            if (second_array[j] != first_array[i] || strlen(first_array) != strlen(second_array))
                return FALSE;
    }
        return TRUE;
}

int strlen(char *string)
{
    int counter = 0;
    for (int i = 0; string[i] != '\0'; i++)
        counter++;
    return counter;
}
