#include<stdio.h>
#define M 1000010
long long s[M];
int t,n,i,j;
int main()
{
 for(i=2;i<=(M/2);i++)
    {
        for(j=2*i;j<=M;j+=i)
        s[j]+=i;
        s[i]+=1;
        s[i]+=s[i-1];
    }
    for(;i<=M;i++)
    {
            s[i]+=1;
            s[i]+=s[i-1];
            }

   scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
   printf("%lld\n",s[n]);
 }
return 0;
}
