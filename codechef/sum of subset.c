#include<stdio.h>
#define S 100
int c=0,n,w[S],r=0,M,x[S],i;
void sos(int s,int r,int k)
{
  x[k]=1;
if (s+w[k]==M)
  {c++;
   printf("subset %d",c);
   for(i=1;i<=k;i++)
    if (x[i]==1)
    printf("%d ",w[i]);
  }
  else if(s+w[k]+w[k+1]<=M && r-w[k]>=M-(s+w[k]))
  sos(s+w[k],r-w[k],k+1);

  if(s+w[k+1]<=M && r-w[k]>=M-s)
   {
    x[k]=0;
    sos(s,r-w[k],k+1);
   }
}


int main()
{
printf("enter size\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 scanf("%d",&w[i]);
 r=r+w[i];
 }
printf("enter the value of M");
scanf("%d",&M);
sos(0,r,1);
return 0;
}
