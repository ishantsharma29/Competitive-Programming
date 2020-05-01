#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,k,c,a[1000],i;
	cin>>t;
	while(t--)
	{
		c=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
				c++;
		}
		if(k==0 && c==n)
			cout<<"NO"<<endl;
		else if(c>=k)
			cout<<"YES"<<endl;	
		else
			cout<<"NO"<<endl;
	}
	return 0;
}						
