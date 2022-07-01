#include <iostream>
#include <stdio.h>

using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
}

int iFact(int n)
{
    int f=1;
    int i;
    for(i=0;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

int main()
{
    int r;
    printf("Factorial\n");
    r = fact(5);
    printf("Factorial Is %d",r);
}
