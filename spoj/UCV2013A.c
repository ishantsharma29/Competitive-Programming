#include<stdio.h>
#define M 1000000007
long long x,s,N,L,z;
long long modulo(long long b,long long e)
{
    x=1;
    while(e>0)
    {
        if(e%2==1)
            x=(x*b)%M;
        b=(b*b)%M;
        e=e/2;
    }
    return x;
}
int main()
{

    int i;
    while(1)
    {s=0;
        scanf("%lld %lld",&N,&L);
        if(N==0&&L==0)
            return 0;
        else
        {
            for(i=1;i<=L;i++)
            {
             z=modulo(N,i);
             s=s+z;
            }
            s=s%M;
            printf("%lld\n",s);
        }
     }
     return 0;
}
