#include<stdio.h>
int gcd(int a,int b)
{
 if(b==0)
 return a;
 else
 return gcd(b,a%b);
 }
int main()
{
int t;
int x,y,z,p,m,n;
scanf("%d",&t);
while(t--)
{
 scanf("%d %d %d",&x,&y,&z);
    p=gcd(x,y);
   // printf("%d\n",p);
    if(x>=y)
      {
        m=x;
        n=y;
      }
    else
    {
        m=y;
        n=x;
    }
    //printf("%d %d\n",m,n);
    if(z%p==0&&z<=m)
        printf("YES\n");
    else
        printf("NO\n");
}
 return 0;
}
