#include <stdio.h>
void sort(int *a, int *b, int *c)
{
    int sorted[3] = {(int)*a, (int)*b, (int)*c};
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
            if (sorted[i] > sorted[j])
            {
                int ptr = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = ptr;
            }
    }
    *c = sorted[2];
    *b = sorted[1];
    *a = sorted[0];
}
