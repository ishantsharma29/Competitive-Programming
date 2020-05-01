#include<string.h>
#include<stdio.h>
#define M 256
char a[M],s[1000007]; 
char x,y,e;
int t,n,i,j,b;
int main()
{
//for(i=0;i<=126;i++)
//printf("%d  ",a[i]);


scanf("%d",&t);
while(t--)
{
for(i=33;i<=126;i++)
{
  a[i]=i;
}
 int f=0;
 scanf("%d",&n);
 a['.']='.';
 for(i=1;i<=n;i++)
 {
  scanf("%c",&e);
  scanf("%c %c",&x,&y);
  
  
  a[(int)x]=(int)y;
 // printf("%d",a[(int)x]);
 }


//for(i=0;i<=126;i++)
//printf("%d  ",a[i]);
scanf("%s",s);
int l=strlen(s);

j=0;b=l-1;
for(i=0;i<l;i++)
{
 s[i]=(char)a[(int)s[i]];
 if(s[i]=='.')
  f=1;
}
//printf("%s %d\n",s,l);
//if (s[0]=='0')
//printf("YES\n");
while(s[j]=='0')
{
 j++;
}
if(f)
{
while(s[b]=='0')
 b--;
if(s[b]=='.')
b--;
}
for(i=j;i<=b;i++)
printf("%c",s[i]);
if((b+1)==j)
printf("0");
printf("\n");
}
return 0;
}
