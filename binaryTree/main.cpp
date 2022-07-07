#include <stdio.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}

int main()
{
    return 0;
}