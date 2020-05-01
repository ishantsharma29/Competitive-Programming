#include<stdio.h>
#include<math.h>
int main()
{
int r,b,c,d,e,a;
scanf("%d %d",&r,&b);
a=b+r;
e=(r+4)/2;
c=e;
c=c*c;
c=c-4*a;
d=sqrt(c);
printf("%d %d",(e+d)/2,(e-d)/2);
return 0;
}
