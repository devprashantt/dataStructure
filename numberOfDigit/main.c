#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,count=0;
    printf("What Is The Number\n");
    scanf("%d",&n);
    count = floor(log10(n)) +1;
    printf("Number Of Digits Are - %d",count);
    return 0;
}
