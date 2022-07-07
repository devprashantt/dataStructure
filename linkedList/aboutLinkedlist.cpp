#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{

    int data;
    struct Node *next;

} *first = NULL, *second = NULL, *third = NULL;

// create functions

void create(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = arr[0];
    second->next = NULL;
    last = second;

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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

// recursive display

void recursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d\n", p->data);
        recursiveDisplay(p->next);
    }
}

// counting nodes

int countNode(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// recursive counting

int recursiveCount(struct Node *p)
{
    if (p != NULL)
    {
        return 0;
    }
    return recursiveCount(p->next) + 1;
}

// sum of nodes data

int add(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// recursive sum

int recursiveAdd(struct Node *p)
{
    int sum = 0;
    if (p == 0)
    {
        return 0;
    }
    return recursiveAdd(p->next) + p->data;
}

// maximum element

int maximumElement(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// recursive maximum

int recursiveMax(struct Node *p)
{
    int max = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    max = recursiveMax(p->next);
    return max > p->data ? max : p->data;
}

// minimum element data

int minimumElement(struct Node *p)
{
    int min = INT32_MAX;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

// recursive minimum

int recursiveMin(struct Node *p)
{
    int min = 0;
    if (p == 0)
    {
        return INT32_MAX;
    }
    min = recursiveMin(p->next);
    return min > p->data ? min : p->data;
}

// searching in linked list (linear search)
// binary search not applicable (no mid value)

Node *searchFunction(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// search recursive

struct Node *searchRecursive(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return searchRecursive(p->next, key);
}

// improving search

struct Node *improvedSearch(struct Node *p, int key)
{
    Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
}

// inserting element

void insertElement(struct Node *p, int index, int k)
{
    struct Node *t;

    if (index < 0 || index > countNode(p))
    {
        printf("Invalid index\n");
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = k;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 1; i < countNode(p) - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// inserting node in sorted list

void sortedInsert(struct Node *p, int k)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = k;
    t->next = NULL;

    if (first = NULL)
    {
        first = t;
    }
    else
    {
        while (p != NULL && p->data < k)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// deleting a node

int deleteNode(struct Node *p, int index)
{
    struct Node *q;
    if (index < 0 || index > countNode(p))
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 1)
    {
        int value = first->data;
        q = first;
        first = first->next;
        free(q);
        return value;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            int data = p->data;
            free(p);
            return data;
        }
    }
}

// checking sorted list

int isSorted(struct Node *p)
{
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
        {
            return 0;
        }
        p = p->next;
    }
    return 1;
}

// second sorting checking method

bool isSortedSecond(struct Node *p)
{
    while (p->next != NULL)
    {
        int x = INT32_MIN;
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

// removing duplicates from sorted list

void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// reversing linked list first method

void reverseLinkedList(struct Node *p)
{
    int *arr;
    struct Node *q = p;
    int i = 0;
    arr = (int *)malloc(sizeof(int) * countNode(p));
    while (q != NULL)
    {
        arr[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = arr[i];
        q = q->next;
        i--;
    }
}

// reversing linked list

void reverseList(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// reversing linked list recursive

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

// concatenation

void concatenate(struct Node *p, struct Node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

// merging two sorted linked lists

void mergeSortedLists(struct Node *p, struct Node *q)
{
    struct Node *third = NULL, *last = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            third = last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            third = last = q;
            q = q->next;
            last->next = NULL;
        }
        while (p != NULL && q != NULL)
        {
            if (p->data < q->data)
            {
                last->next = p;
                last = p;
                p = p->next;
                last->next = NULL;
            }
            else
            {
                last->next = q;
                last = q;
                q = q->next;
                last->next = NULL;
            }
        }
        if (p == NULL)
        {
            last->next = q;
        }
        else
        {
            last->next = p;
        }
    }
}

// checking loops

bool checkLoop(struct Node *p)
{
    struct Node *q, *r;
    p = q = r;
    do
    {
        r = r->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while ((q && r) && (q != r));
    return r == q ? true : false;
}

int main()
{
    struct Node *t1, *t2;
    int arr[] = {3, 5, 7, 8, 9};
    int arr2[] = {1, 2, 4, 6, 10};

    create(arr, 5);
    create2(arr2, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    return 0;
}