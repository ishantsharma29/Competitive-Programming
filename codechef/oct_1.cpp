#include<bits/stdc++.h>
using namespace std;
#define M 100000
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,a[M]={0},max=INT_MIN,i,sum=0;
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(max<a[i])
				max=a[i];
			sum+=a[i];
		}
		sum=sum+m;
		if((sum%n)!=0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			int p=max*n;
			int diff=sum-p;
			if(diff%n==0)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}							
			
