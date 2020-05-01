#include<stdio.h>
#include<string.h>
#define M 10000007

int t,n,a[M],b[M],c[M],d[M],i,j;
int main()
{
 
scanf("%d",&t);
 while(t--)
  {
    scanf("%d",&n);
     b[0]=0;
    for(i=1;i<=n;i++)
      {
       scanf("%d",&a[i]);
       b[i]=b[i-1]+a[i];
       b[i]=b[i]%n;
      }
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
     for(i=0;i<=n;i++)
    {
      if(c[b[i]]==0)
        {
         c[b[i]]=1;
        d[b[i]]=i;
        }
       else
       {
         int x=d[b[i]];
        printf("%d\n",i-x);
         while(x+1<=i)
         {
           printf("%d",x+1);
           if (x+1<i)
           printf(" ");
           x++;
         }  
       printf("\n");
       break;
     }
    }
  }
return 0;
} 

          
   
     
