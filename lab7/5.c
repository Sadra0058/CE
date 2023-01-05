#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i;
    char *s;
    int *p = (int *)malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++)
        p[i] = i + 48;
    s = (char *)p;
    for (i = 0; i < 40; i++) /* Pay attention to bound of for */
        printf("%c ", s[i]);

        printf("%c\n" , s[1]);  /* What's happening here? what is value of s[1]? why? */
        printf("%c\n" , s[2]);
        printf("%c\n" , s[3]);
        printf("%c\n" , s[4]);
    printf("\n");
    p++;
    printf("p[1] is %d\n", *p);
    free(p); /* What's happening here? */
}
