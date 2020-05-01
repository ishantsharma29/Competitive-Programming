#include<stdio.h>
#include<math.h>
int main()
{
int t,i=1;
double n,m,k,a,b,c;
long long int p;
int d;
scanf("%d",&t);
 while(t--)
  {p=0;
  d=0;
   scanf("%lf %lf %lf",&n,&m,&k);
   p=((k*m*n)-1);
   a=(log(n)/log(2));
   //printf("%f\n",a);
   b=(log(k)/log(2));
   c=(log(m)/log(2));
   a=ceil(a);
   b=ceil(b);
   c=ceil(c);
   d=a+b+c;
   printf("Case #%d: %lld %d\n",i,p,d);
   i++;
  }
  return 0;
}
