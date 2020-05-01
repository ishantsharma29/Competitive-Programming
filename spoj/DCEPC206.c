#include<stdio.h>
#define M 1000000
void msort(long long int a[],long long int,long long int);
void merge(long long int a[],long long int,long long int,long long int,long long int);
long long int i,t,n,a[M],c,tmp[M],x;
long long int s;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
      s=0;
   scanf("%lld",&n);
   for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    msort(a,0,n-1);
    printf("%lld\n",s);
    //for(i=0;i<n;i++)
    //prlong long intf("%d",a[i]);
  }
  return 0;
}
void msort(long long int a[],long long int s,long long int e)
{
  long long int m;
  if(s<e)
   {
    m=(s+e)/2;
    msort(a,s,m);
    msort(a,m+1,e);
    merge(a,s,m,m+1,e);
   }
}
void merge(long long int a[],long long int l1,long long int u1,long long int l2,long long int u2)
{
    c=l1;
    x=l1;
  while(l1<=u1&&l2<=u2)
  {
    if(a[l1]>=a[l2])
    {
     //   p=p+l2-c;
     tmp[c++]=a[l2++];

    }
    else
    {s=s+(u2-l2+1)*a[l1];
    tmp[c++]=a[l1++];
    }
  }
  while(l1<=u1)
  tmp[c++]=a[l1++];
  while(l2<=u2)
  tmp[c++]=a[l2++];
   for(i=u2;i>=x;i--)
    a[i]=tmp[i];
}
