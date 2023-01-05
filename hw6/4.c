#include <stdio.h>
#include <stdlib.h>

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

Node *convert(Point *arr[1000], int size)
{
    int i = 0;
    Node *node = (Node *)malloc(sizeof(Node));
    Node *head = node;
    node->data = *arr[0];
    node->next = NULL;

    for (i = 1; i < size; i++)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        node->next = new;
        new->data = *arr[i];
        new->next = NULL;
        node = new;
    }

    return head;
}

