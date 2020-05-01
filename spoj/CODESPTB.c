#include<stdio.h>
#define M 1000000
void msort(int a[],int,int);
void merge(int a[],int,int,int,int);
int i,t,n,a[M],c,tmp[M],x;
long long int p;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
      p=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    msort(a,0,n-1);
    printf("%lld\n",p);
    //for(i=0;i<n;i++)
    //printf("%d",a[i]);
  }
  return 0;
}
void msort(int a[],int s,int e)
{
  int m;
  if(s!=e)
   {
    m=(s+e)/2;
    msort(a,s,m);
    msort(a,m+1,e);
    merge(a,s,m,m+1,e);
   }
}
void merge(int a[],int l1,int u1,int l2,int u2)
{
    c=l1;
    x=l1;
  while(l1<=u1&&l2<=u2)
  {
    if(a[l1]>a[l2])
    {
        p=p+l2-c;
     tmp[c++]=a[l2++];
     ;
    }
    else
    tmp[c++]=a[l1++];
  }
  while(l1<=u1)
  tmp[c++]=a[l1++];
  while(l2<=u2)
  tmp[c++]=a[l2++];
   for(i=u2;i>=x;i--)
    a[i]=tmp[i];
}
