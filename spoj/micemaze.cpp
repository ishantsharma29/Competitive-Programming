#include<bits/stdc++.h>
using namespace std;
#define M 100


int n,e,s,d,i,j,k,y;
long long int t,m,a[M][M],cnt=1,q;


long long int min(long long int x,long long int y)
{
    if(x>y)
        return y;
    return x;

}

int main()
{
//printf("enter no of vertices\n");
scanf("%d",&n);
scanf("%d",&e);
scanf("%lld",&t);
scanf("%lld",&m);
	while(m--)
	{
		 scanf("%d %d %lld",&s,&d,&q);
		 a[s][d]=q;
 
	}

/*for(i=1;i<=n;i++)
{
  for(j=1;j<=n;j++)
  {
   	cout<<a[i][j]<<"\t";
 }
 cout<<endl;
}

cout<<endl;
cout<<endl;
*/
for(i=1;i<=n;i++)
{
  for(j=1;j<=n;j++)
  {
   if (i==j)
    {
    a[i][j]=0;
    }
   if (a[i][j]==0 && i!=j)
    {
    a[i][j]= LONG_MAX;
    }
 }
}
	for(k=1;k<=n;k++)
	{
	  for(i=1;i<=n;i++)
	  {
		    for(j=1;j<=n;j++)
		    {
       			
      			a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
      		    }
  	  }	
	}
	
	
/*	
for(i=1;i<=n;i++)
{
  for(j=1;j<=n;j++)
  {
   	cout<<a[i][j]<<"\t";
 }
 cout<<endl;
}	
	
*/	
	
for(i=1;i<=n;i++)
{
  //cout<<"outside "<<a[i][e]<<endl;
   if (i!=e)
    {
    	if(a[i][e]<=t)
    	{
    		cnt++;
    //		cout<<"i "<<i<<endl;
    	}	
    }
}	
cout<<cnt<<endl;	
	
return 0;
}



