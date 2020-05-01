#include <iostream>
using namespace std;
#include<algorithm>
#define K 100010
int a[K];
int beg,end,mid,t,n,m,i,p;
int main()
 {
scanf("%d",&t);
while(t--)
{
p=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
std::sort(a,a+n);
for(i=0;i<n;i++)
{
  beg=i+1;
  end=n-1;
while(beg<=end)
  {
   mid=(beg+end)/2;
   if(a[mid]==(m-a[i]))
     {
       p++;
       break;
      }
   else if(a[mid]>(m-a[i]))
      end=mid-1;
   else
   beg=mid+1;
  }
}
printf("%d\n",p);
}
return 0;
}
