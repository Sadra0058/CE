#include <stdio.h>
#include <stdlib.h>
#define INPUT_TXT_ADDRESS "input.txt"
#define OUTPUT_FILE_ADDRESS "output.txt"

void append()
{
    int save;
    char read;
    FILE *input = fopen(INPUT_TXT_ADDRESS, "r");
    FILE *output = fopen(OUTPUT_FILE_ADDRESS, "a");
    while ((save = fgetc(input)) != EOF)
    {
        read = save;
        fwrite(&read, sizeof(char), 1, output);
    }
    fclose(input);
    fclose(output);
}

int main()
{
    append();
}
