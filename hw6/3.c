#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void p(Node *head)
{
    if (head == NULL)
        return;
    p(head->next);
    printf("%d\t", head->data);
    return;
}
Node *g(Node *head)//اولی
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *cur = head;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    cur->next = head;
    head = cur;
    return head;
}

Node *f(Node *head)
{
    if (!head)
        return head;
    Node *next = head->next;
    head->next = NULL;
    while (next)
    {
        Node *new_next = next->next;
        next->next = head;
        head = next;
        next = new_next;
    }
    return head;
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *new1 = (Node *)malloc(sizeof(Node));
    Node *new2 = (Node *)malloc(sizeof(Node));

    head->data = 3;
    head->next = new1;
    new1->data = 4;
    new1->next = new2;
    new2->data = 5;
    new2->next = NULL;
    Node *temp = head;

    printf("%p\n" , head->data);
    printf("%p\n" , new1->data);
    printf("%p\n" , new2->data);

    head = g(head);
    printf("\n");
    
    printf("%p\n" , head->data);
    printf("%p\n" , new1->data);
    printf("%p\n" , new2->data);
}