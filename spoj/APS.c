#include<stdio.h>
#define M 10000010
long long s[M];
int t,n,i,j;
int main()
{
 for(i=2;i*i<M;i++)
    {
        if(!s[i])
      { s[i]=i;
        for(j=i*i;j<M;j+=i)
            if(!s[j])
            s[j]=i;
      }
    }
 for(i=2;i<M;i++)
    {
        if(!s[i])
        s[i]=i;
        s[i]+=s[i-1];
     }
scanf("%d",&t);
  while(t--)
  { scanf("%d",&n);
   printf("%lld",s[n]);
  }
return 0;
}
