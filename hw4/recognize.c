#include <stdio.h>
void recognize(char string[], int size)
{
    int counter = 1;
    /*Check characters*/
    for (int i = 0; i < size; i++)
    {
        for (int j = (i + 1); j < size; j++)
        {
            if (string[i] == string[j])
                break;
            else if (j == size - 1)
                counter++;
        }
    }
    /*check it is fake or not and print the result*/
    if (counter % 2 == 1)
        printf("BLOCK THIS USER");
    else
        printf("CHAT WITH THIS USER");
}
