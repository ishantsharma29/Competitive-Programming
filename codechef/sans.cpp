#include<bits/stdc++.h>

using namespace std;

int found,n; 
long long a[21],subsum;
int mark[21];
void findsubset(int i,long long sum)
{ 
   int j,k;
   sum+=a[i];
   if(sum==subsum)
   {
     found=1; 
     mark[i]=1;
     return; 
   }
   else if(sum>subsum)
   { 
     found=0;
     return;
   }
   for(j=i+1;j<n;j++) 
   { 
     if(!mark[j])
     {
      findsubset(j,sum);
      if(mark[i]!=found) 
       {
       	mark[i]=1;
      //  cout<<i<<" "<<mark[i]<<" "; 
        return;
       }
     }
   }
   
}
          
int main()
{
   int t,i;
   long long k;
   scanf("%d",&t);
  while(t--) 
  { 
    found=0; 
    subsum=0;
    scanf("%d%lld",&n,&k);
    for(i=0;i<n;i++)
    {
        mark[i]=0;
        scanf("%lld",&a[i]);
        subsum+=a[i];
    }
    if(subsum%k!=0)
    {
         printf("no\n");
         continue; 
    }
    else if(subsum==0) 
    {
         if(n>=k)
         {
                printf("yes\n"); 
         } 
         else
         {
                printf("no\n");
         }
         continue; 
     }
     else 
     {
          subsum=subsum/k;
          for(i=0;i<k;i++)
          { 
                if(!mark[i])
                findsubset(i,0); 
                if(!mark[i]) 
                break;
           }
      }
      if(i==k) 
      	printf("yes\n");
      else
        printf("no\n");
  }
  return 0;
}  
  
