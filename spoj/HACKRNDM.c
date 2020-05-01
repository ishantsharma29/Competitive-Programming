#include<stdio.h>
#define M 10000000
void msort(int [],int,int);
void merge(int [],int,int,int,int);
int bsearch(int [],int,int,int);
int i,t,n,c,x,k,f;
int a[M],tmp[M];
unsigned int p=0;
int main()
{
  scanf("%d %d",&n,&k);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    msort(a,0,n-1);
    for(i=0;i<n-1;i++)
       {
         f=bsearch(a,i+1,n-1,a[i]+k);
         if(f==1)
            p++;
       }
    printf("%d",p);
    //for(i=0;i<n;i++)
    //printf("%d",a[i]);
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
     tmp[c++]=a[l2++];
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
int bsearch(int a[],int b,int e,int t)
{
    int m;
    while(b<=e)
    {
        m=(b+e)/2;
        if(a[m]==t)
            return 1;
        else if(a[m]>t)
            e=m-1;
        else
            b=m+1;
    }
    return -1;
}
