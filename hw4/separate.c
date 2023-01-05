#include <stdio.h>
void separate(int array[], int size)
{
    int e = 0;
    int o = 0;
    int odd[size];
    int even[size];
    /*Sort input*/
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
    /*Separate odd and even*/
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even[e] = array[i];
            e++;
        }
        else
        {
            odd[o] = array[i];
            o++;
        }
    }

    /*print output*/
    printf("output:\n");
    for (int i = 0; i < e; i++)
    {
        if (i == (e - 1))
            printf("%i", even[i]);
        else
            printf("%i,", even[i]);
    }
    printf("\n");
    for (int i = 0; i < o; i++)
    {
        if (i == (o - 1))
            printf("%i", odd[i]);
        else
            printf("%i,", odd[i]);
    }
    return;
}