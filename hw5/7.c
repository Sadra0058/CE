#include <stdio.h>
int main()
{
    char array[][4] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int(*ptr)[4] = array;
    printf("%i %i" , ptr[0] , ptr[2]);
    printf("%c %c\n", (*ptr)[2], (*ptr)[3]);
    ptr += 2;
    printf("%c %c\n", (*ptr)[2], (*ptr)[3]);
    return 0;
}
