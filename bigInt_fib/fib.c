#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long x,y,z;
    x=0;
    y=1;
 
    while(x>-1)
    {
        printf("%lli\n",x);

        z=x+y;
        x=y;
        y=z;
    }
}
