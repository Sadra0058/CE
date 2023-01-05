#include <stdio.h>
int main()
{
    int array[4] = {1, 4, 7, 10};
    int *ptr1 = (int *)(&array + 1);
    printf("%d\n", ptr1 - array);
    int *ptr2 = (int *)(array + 1);
    printf("%d\n", ptr2 - array);
    return 0;
}