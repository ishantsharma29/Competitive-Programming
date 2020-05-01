#include<stdio.h>
#define M 1000000
#include<limits.h>
int i,a[M],n,c=0,max=INT_MIN;
int m(int a,int b)
{
if(a>b)
return a;
return b;
}
int main()
{
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
if(a[i]!=0)
c++;
else
{max=m(c,max);
c=0;
}
}
max=m(c,max);
printf("%d",max);
return 0;
}
