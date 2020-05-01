#include<stdio.h>
int a=0,b=0,c=0,s1=0,s2=0,b1=0,b2=0,b3=0,p=0,t,e;
char n;
int main()
{
for(t=0;t<6;t++)
{
scanf("%c ",&n);
if((int)n>47&&(int)n<58)
    n=(int)n-48;
if((int)n==79)
{p++;
if(p==2)break;
if(c%2==0)
{b1=s1;
s1=0;
b++;
c=0;
}
else
{
b2=s1;
s1=0;
a++;
c=0;
}
}
else if((int)n==87||(int)n ==78)
t--;
else if(n%2==0)s1+=n;
else
{
s1+=n;
c++;
e=s1;
s1=s2;
s2=e;
}
}
if(p==0)
{
if(c%2==0)
{b1=s1;
b2=s2;
b3=0;}
else
{
b2=s1;
b1=s2;
b3=0;
}
}
if(p>0)
{
if(a==1&&(c%2==1))
{b1=s1;
b3=s2;}
else if((a==1)&&(c%2==0))
{
b3=s1;
b1=s2;
}
else if((b==1)&&(c%2==0))
{b3=s1;
b2=s2;}
else
{b2=s1;
b3=s2;
}
}
printf("%d\n%d\n%d",b1,b2,b3);
return 0;
}
