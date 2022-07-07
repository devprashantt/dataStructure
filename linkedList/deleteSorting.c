#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

void reverseListRecursive(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        reverseListRecursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void sortingList(struct Node *p)
{
    struct Node *t, *q;
    t = p;
    while (t->next != NULL)
    {
        q = t->next;
        while (q->next != NULL)
        {
            if (t->data < q->data)
            {
                int temp = t->data;
                t->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        t = t->next;
    }
}

int main()
{
    int a_size;
    printf("1st linked list size: ");
    scanf("%d", &a_size);
    int A[a_size];
    printf("Enter values of first Linked List: \n");
    for (int i = 0; i < a_size; i++)
    {
        scanf("%d", &A[i]);
    }

    create(A, a_size);
    int c = 0;
    if (a_size % 2 == 0)
    {
        c = a_size / 2;
    }
    else
    {
        c = (a_size + 1) / 2;
    }
    int deleted = Delete(first, 2);

    sortingList(first);

    printf("Final List:");
    Display(first);

    return 0;
}