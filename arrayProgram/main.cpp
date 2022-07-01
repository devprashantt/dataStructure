#include <iostream>
#include <stdio.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements Are-\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
    }
};

int main()
{
    struct Array arr;
    int n, i;
    printf("Enter Size Of array");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter Numbers For Array");
    scanf("%d", &n);

    printf("Enter Numbers For Array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    Display(arr);
}
