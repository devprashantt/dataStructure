#include <iostream>
#include <stdio.h>

using namespace std;

int fibonnaSeries(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fibonnaSeries(n-1) + fibonnaSeries(n-2);
    }
}

int itterative(int n)
{
    int t0=0,t1=1,sum=0,i;
    if(n<=1)
    {
        return n;
    }
    for(i=2;i<=n;i++)
    {
        sum = t0+t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

int array[10];

int modifiedFibonacciSeries(int n)
{
    if(n<=1)
    {
        array[n] = n;
        return n;
    }
    else
    {
        if(array[n-2]==-1)
        {
            array[n-2] = modifiedFibonacciSeries(n-2);
        }
        if(array[n-1]==-1)
        {
            array[n-1]=modifiedFibonacciSeries(n-1);
        }
        array[n] = array[n-2]+array[n-1];
        return array[n-2]+array[n-1];
    }
}

int main()
{
    cout << "Hello world!" << endl;
    printf("Series Sum %d\n",fibonnaSeries(7));
    printf("Series Sum %d\n",modifiedFibonacciSeries(7));
    printf("Series Sum %d\n",itterative(7));
    return 0;
}
