#include<bits/stdc++.h>
using namespace std;
#define M 100000

int main()
{
	long long int t,n,i,a[M];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<a[0];
		for(i=2;i<n;i+=2)
		{
			cout<<" "<<a[i]<<" "<<a[i-1];
		}
		if(i==n)
			cout<<" "<<a[i-1];
		cout<<endl;
	}
	return 0;
}				
