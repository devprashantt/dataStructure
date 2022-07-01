#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int powerOptimized(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        return powerOptimized(m*m,n/2);
    }
    else
    {
        return m*powerOptimized(m*m,(n-1)/2);
    }
}

int power(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return power(m,n-1)*m;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    int o = powerOptimized(2,5);
    int r = power(2,5);
    printf("%d\n",o);
    printf("%d\n",r);
    return 0;
}
