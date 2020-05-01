#include<stdio.h>

#define INT_MAX 9999
#define M 100

int a[M],n,i,r;

int f(int idx,int n)
{
    
 //if(idx==n-1)
 // return 1;
   if(a[idx]==0)
    return INT_MAX;
  if(idx+a[idx]>=n-1)
    return 1;
  int min=INT_MAX;
 for(i=idx+1;i<n && i<=idx+a[idx];i++)
  {
   r=f(i,n)+1;
	//printf("%d\n",r);
   if(r<min)
   min=r;
  }
return min;
}

int main()
{
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
int p=f(0,n);
printf("%d",p);
return 0;
}

