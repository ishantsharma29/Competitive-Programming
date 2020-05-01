#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct node
{
   ll id,t,b;
   bool ch;
}a[100000];

int main()
{
 ll n,i,t,b,count=0;
    printf("enter the number of process\n");
    scanf("%lld",&n);
    printf("enter the process arrival and burst time\n");
   ll time=100000;
     for(i=0;i<n;i++)
     {
         a[i].id=i;
         a[i].ch=false;
          printf("p%lld: ",i);
         scanf("%lld %lld",&a[i].t,&a[i].b);
        
     }
     time=0;
        //sort(a,a+n,cmp);
      
   /*  for(i=0;i<n;i++)
    {
     printf("process p%lld is executed form %lld to %lld\n",a[i].id,time,time+a[i].b);
     if(i<n-1)
         time=max(time+a[i].b,a[i+1].t);
    }*/
    ll id;
    while(count!=n)
    {
   ll mini=100000;
        for(i=0;i<n;i++)
        {
             if(a[i].t<=time && !a[i].ch)
              {
                if(a[i].b<mini)
            {
                  mini=a[i].b;
                   id=i;
                }
              }
         }
         if(mini!=100000)
         {  printf("process p%lld is executed form %lld to %lld\n",id,time,time+a[id].b);
           time=a[id].b+time;
           count++;
           a[id].ch=true;
         }
         else
         time++;
     
    }
   return 0;  
}
