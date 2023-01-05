#include <stdio.h>
#include <math.h>
void root(float a, float b, float c);
int main()
{
    /*get abc*/
    float a = 0;
    float b = 0;
    float c = 0;
    printf("input:\n");
    scanf("%f , %f , %f", &a, &b, &c);

    /*print output*/
    printf("output:\n");
    root(a, b, c);

    return 0;
}

void root(float a, float b, float c)
{
    /*Calculate delta*/
    float delta = (b * b) - (4 * a * c);
    /*check there is roots or not and print result*/
    if (delta < 0)
    {
        printf("NO ROOT FOUND");
        return;
    }

    /*Calculate the roots and print them*/
    float root1 = (-b + sqrt(delta)) / (2 * a);
    float root2 = (-b - sqrt(delta)) / (2 * a);

    if (root1 == root2)
        printf("%f", root1);
    else
        printf("%f , %f", root1, root2);
    return;
}