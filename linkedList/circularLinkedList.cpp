#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * head;

void createLinkedlist(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// display function

void displayLinkedlist(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != NULL);
}

// recursive display function

void recursiveDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head && flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
    flag = 0;
}

// inserting in circular linked list

void insertCircular(struct Node *p, int index, int value)
{
    struct Node *t;
    int i;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next!=head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head=t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

// deleting from circular linked list

int deleteNode(struct Node *p, int index)
{
    struct Node *q;
    int i,value;
    if(index<0)
    {
        printf("Invalid index\n");
        return -1;
    }
    if (index==1)
    {
        while (p->next!=head)
        {
            p = p->next;
        }
        value=head->data;
        if (head==p)
        {
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
    }
    
}



int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    createLinkedlist(arr, 10);
}