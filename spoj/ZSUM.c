#include<stdio.h>
#define M 10000007
int t=10000;
long long x,y,z,q,r,g,n,k;
long long modulo(long long b,long long e)
{
 x=1;
 while(e>0)
 {
  if(e%2==1)
    {
        x=(x*b)%M;
    }
     b=(b*b)%M;
     e=e/2;
 }
  return x;
}
int main()
{
 while(t--)
  {scanf("%lld %lld",&n,&k);
   if(n==0&&k==0)
   return 0;
   else
   {
    y=modulo(n,n);
    z=modulo(n,k);
    q=2*modulo(n-1,k);
    r=2*modulo(n-1,n-1);
    g=(y+z+q+r)%M;
    printf("%lld\n",g);
   }
  }
    return 0;
}
