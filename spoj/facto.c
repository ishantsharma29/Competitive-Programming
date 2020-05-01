#include<stdio.h>
long long N;
int main()
{
    long long c,i,f;
    scanf("%lld",&N);
while(N)
{
    f=0;
   if(N==0)
    break;
   else
     {
       i=2;
      while(i*i<=N)
      {
          c=0;
       if(N%i==0)
       {

           f++;
         while(N%i==0)
        {
           c++;
           N=N/i;
        }
        if(f>1)
            printf(" ");
       printf("%lld^%lld",i,c);
       }
       i++;
      }
      if(N>1)
      {
          if (f>0)
          printf(" ");
      printf("%lld^1",N);
      }
      printf("\n");
      }
        scanf("%lld",&N);
  }
  return 0;
}
