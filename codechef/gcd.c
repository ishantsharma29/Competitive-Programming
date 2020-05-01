#include<stdio.h>

long long int gcd(long long int a,long long int b)
{
 if(b==0)
 return a;
 else if (a%b==0)
  return b;
 else
  return gcd(b,a%b);
}

int main()
{
long long int x,y;
scanf("%lld %lld",&x,&y);
printf("%lld",gcd(x,y));
return 0;
}
