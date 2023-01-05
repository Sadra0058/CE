#include <stdio.h>
#include <stdlib.h>
#define true 1

int main()
{
    int *a;
    while (true)
    {
        a = (int *)malloc(100 * sizeof(int));
        for (int i = 0; i < 100; i++)
        {
            scanf("%d", &num);
            *(a + i) = num;
            for (int j = 0; j < i; j++)
                if (num == a[i])
                    a[i]++;
            printf("%d\n", a[i]);
        }
    }
}