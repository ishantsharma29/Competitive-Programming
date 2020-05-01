#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if(x%2==1 && x>0)
		{
			if(y<=x+1 && y>=1-x)
				{
				cout<<"YES"<<endl;
				continue;
				}
			
		}
		if(x%2==0 && x<0)
		{
			if(y<=-x && y>=x)
				{
				cout<<"YES"<<endl;
				continue;
				}
		}
		if(y<0 && y%2==0)
		{
			if(x<=-y && x>=y+1)
				{
				cout<<"YES"<<endl;
				continue;
				}
		}
		if(y>0 && y%2==0)
		{
			if(x<=y-2 && x>=1-y)
				{
				cout<<"YES"<<endl;
				continue;
				}
		}
		if(x==0 && y==0)
				{			
				cout<<"YES"<<endl;
				continue;
				}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}												
