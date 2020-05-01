#include<stdio.h>

long long int e1,o1,e2,o2,x,h,y,n,m,t;
//int n,m,t;
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

scanf("%d",&t);
while(t--)
{
 scanf("%lld %lld",&n,&m);
 o1=n/2;
 e1=n/2;
if(n%2==1)
 o1=o1+1;
 o2=m/2;
 e2=m/2;
if(m%2==1)
 o2+=1;
 x=e1*o2+o1*e2;
  h=m*n;
 y=gcd(x,h);
h=h/y;
x=x/y;
printf("%lld/%lld\n",x,h);
}
return 0;
}
