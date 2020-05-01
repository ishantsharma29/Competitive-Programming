#include<stdio.h>
int n,a[100],i,j;
#include<limits.h>
void lbs()
{
 int l[n+1],p[n+1];
 for(i=0;i<n;i++)
    {l[i]=1;p[i]=1;}
 
 for(i=1;i<n;i++)
 {
   for(j=0;j<i;j++)
     {
       if(a[j]<a[i] && l[j]+1>l[i])
         l[i]=l[j]+1;
       if(a[j]>a[i])
          { if(l[j]>p[j])
               p[i]=l[j]+1;
            else
               p[i]=p[j]+1;
          }
     }
  }
int max=INT_MIN;
for(i=0;i<n;i++){
  printf("%d %d\n",p[i],l[i]);
  if(p[i]>l[i])
   { if(p[i]>max)
       max=p[i];
   }
   else
    {
     if(l[i]>max)
      max=l[i];
    }
  }
printf("max length of bitonic seq--> %d",max);      
}

int main()
{
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  lbs();
 
 return 0;
}
