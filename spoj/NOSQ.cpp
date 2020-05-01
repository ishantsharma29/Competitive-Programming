#include<bits/stdc++.h>
using namespace std;
#define M 100003

int a[M][11];
int t,p,b,d,i,j,r,c;
int main()
{
	for(i=2;i*i<M;i++)
	{
		if(a[i][10]==0)
		{
			for(j=i*i;j<M;j+=i*i)
			{
				a[j][10]=1;
			}
		}
	}
	
	a[1][1]=1;
	for(i=2;i<M;i++)
	{
		if(a[i][10]==0)
		{
			int n=i;
			while(n>0)
			{
				r=n%10;
				a[i][r]=1;
				n/=10;
			}
		}
	}
	
	for(i=2;i<M;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i][j]=a[i][j]+a[i-1][j];
		}
	}			
			
	cin>>t;
	while(t--)
	{
		c=0;
		cin>>p>>b>>d;
		c=a[b][d]-a[p-1][d];
		cout<<c<<endl;
	}
	return 0;
}		
