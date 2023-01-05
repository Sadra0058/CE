#include <stdio.h>
int main()
{
    int x[1] , a = 2; 
    int *b = &a, *x_ptr = &x[0];
    scanf("%d %d", b, x_ptr);
    printf("a=%d , x=[%d]\n", *b, x[0]);
    return 0;
}
