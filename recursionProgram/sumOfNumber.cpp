#include <iostream>
#include <stdio.h>

using namespace std;

int sum(int n)
{
    int s = 0, i;
    if(n==0)
        return 0;
    return sum(n-1)+n;
}

int usingFor(int n)
{
    int sum=0,i;
    for(i=0;i<=n;i++)
    {
        sum=sum+i;
    }
    return sum;
}

int main()
{
    int r,z;
    cout << "Hello world!" << endl;
    r = sum(5);
    z = usingFor(10);
    printf("%d\n",r);
    printf("%d\n",z);
    return 0;
}
