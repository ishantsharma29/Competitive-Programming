#include<bits/stdc++.h>
using namespace std;
#define M 1000003
int cubefree[M],i,j;
int freed[M];
void cubefr()
{
	for(i=2;i*i*i<=M;i++)
	{
		if(!cubefree[i*i*i])
		{
			for(j=i*i*i;j<=M;j=j+i*i*i)
			{
				cubefree[j]=1;
			}
		}
	}
}
int main()
{
	int x,t,n,k;
	cubefr();
	k=1;
	for(i=1;i<=M;i++)
	{
		if(cubefree[i]==0)
		{
		freed[i]=k++;
		}
	}		
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n;
		if(freed[n]==0)
			cout<<"Case "<<x<<": Not Cube Free"<<endl;
		else
			cout<<"Case "<<x<<": "<<freed[n]<<endl;	
	}
	return 0;
}			
