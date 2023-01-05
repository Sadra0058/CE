#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
#define READ_CHAR_SIZE 100
#define WRITE_CHAR_SIZE 100
#define INPUT_TXT_ADDRESS "input.txt"
#define OUTPUT_FILE_ADDRESS "output.txt"

int counter(void)
{
    int output = 0;
    FILE *count = fopen(INPUT_TXT_ADDRESS, "r");
    while (fgetc(count) != EOF)
        output++;
    return output;
}

char *read_input_file()
{
    char *in_order_array = (char *)malloc(READ_CHAR_SIZE * sizeof(char));
    FILE *input = fopen(INPUT_TXT_ADDRESS, "r");

    if (input != NULL)
    {
        fread(in_order_array, sizeof(char), READ_CHAR_SIZE, input);
        return in_order_array;
    }

    else if (input == NULL)
    {
        printf("could not finde the file\n");
    }
}
char *reverse_array(char *in_order_array)
{
    char *reversed_array = (char *)malloc(READ_CHAR_SIZE * sizeof(char));

    for (int i = ZERO; i < counter(); i++)
    {
        reversed_array[i] = in_order_array[counter() - i - 1];
    }
    return reversed_array;
}
void write_reversed_array_in_file(char *in_order_array)
{
    char *reversed_array = reverse_array(in_order_array);
    FILE *output = fopen(OUTPUT_FILE_ADDRESS, "w");

    fwrite(reversed_array, sizeof(char), counter(), output);

    fclose(output);
}
int main()
{
    char *in_order_array = read_input_file();
    write_reversed_array_in_file(in_order_array);
    return 0;
}