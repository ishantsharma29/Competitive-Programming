#include<stdio.h>
long long int t,n,k,m,f,count,p,c;
int main()
{
scanf("%lld",&t);
while(t--)
{
  f=0;
   count=0; 
c=0;
 scanf("%lld %lld %lld",&n,&k,&m);
   p=n;
 if(k==1)
  {
   printf("%lld\n",n);
   continue;
  }
  while(p%k==0)
  {
    p=p/k;
    c++;
    if(c==m)
     {
      printf("%lld\n",p);
       f=1;
      break;
     }
  }
  if(f==0){  
  m=m-c;
  if(m%2==0)
  printf("%lld\n",p);
  else{ 
   printf("%lld\n",p*k);
  }
  }
}
return 0;
}
   
 
