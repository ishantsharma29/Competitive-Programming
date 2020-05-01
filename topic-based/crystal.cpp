#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,x,i,k,p;
	cin>>n;
	x=(n/2)+1;
	for(i=1;i<=x;i++)
	{
		for(k=i;k<x;k++)
		{
		cout<<"* ";
		}
		for(p=1;p<=(2*i)-1;p++)
		{
			cout<<"D ";
		}
		for(k=i;k<x;k++)
		{
		cout<<"* ";
		}
		cout<<endl;	
	}
	for(i=1;i<=n-x;i++)
	{
		for(k=1;k<=i;k++)
		{
			cout<<"* ";
		}
		for(p=1;p<=(n-2*i);p++)
		{
			cout<<"D ";
		}
		for(k=1;k<=i;k++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}	
	return 0;
}					
