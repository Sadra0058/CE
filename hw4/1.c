#include <stdio.h>
int main()
{
    int array[100], n, c, d, swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n); /*نمی خواهیم آدرس متغییر چاپ شود*/
    c = 0;                            /*به دلیل وجود حلقه باید مقدار اولیه داشته باشد و از خانه اول آرایه پر شود*/
    while (c < n)                     /*یک بار اضافی انجام می شد*/
    {
        scanf("%d", &array[c]);
        c++;
    }

    for (c = 0; c < n; c++) /*یک بار اضافی تکرار می شد*/
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d]; /*برای جابجایی مقدار ها باید این خط و خط پایین باهم جابجا می شدند*/
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++) /*یک بار اضافی انجام می شد*/
        printf("%d\n", array[c]);
    return 0;
}