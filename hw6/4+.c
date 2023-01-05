#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

typedef struct Node
{
    Point data;
    struct Node *next;
} Node;

int power(int a , int b)
{
    for(int i = 1 ; i < b ; i++)
    a *= a;
    return a;
}

void print_distance(Node *head)
{
    if (head == NULL)
        return;
    Node *temp1 = head;
    Node *temp2 = head->next;
    while (temp2 != NULL)
    {
        int powerx = power((temp2->data.x - temp1->data.x), 2.0);
        int powery = power((temp2->data.y - temp1->data.y), 2.0);
        printf("%i\n" , (int)sqrt((powerx + powery)));
        temp1 = temp2;
        temp2 = temp2->next;
    }
}
