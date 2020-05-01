#include <stdio.h>
#include<limits.h>
int n,k,i,p,j,l,res,t,x;
int max(int a,int b)
{
  if(a>b)
   return a;
  return b;
}

int balldrop(int n,int k)
{ 
int balldrop[n+1][k+1];
 for(j=0;j<=k;j++)
   balldrop[0][j]=0;
 for(j=0;j<=n;j++)
   balldrop[j][0]=0;
  for(j=1;j<=k;j++)
   balldrop[1][j]=j;
  for(j=1;j<=n;j++)
   balldrop[j][1]=1;
  
for(j=2;j<=n;j++)
  {
   for(l=2;l<=k;l++)
    {
     balldrop[j][l]=INT_MAX;
     for(x=1;x<=k;x++)
       {
        res=1+max(balldrop[j-1][x-1],balldrop[j][l-x]);
      if(res<balldrop[j][l])
          balldrop[j][l]=res;

        }
     }
  }
return balldrop[n][k];
}
int main(void) {
	// your code goes here
 scanf("%d",&t);
 while(t--)
  {
  scanf("%d %d %d",&i,&n,&k);
  p=balldrop(n,k);
  printf("%d %d\n",i,p);
  }  

	return 0;
}

