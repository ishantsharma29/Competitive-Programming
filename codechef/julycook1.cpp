#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,a[100007],i,count;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		count=1;
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
				count+=1;
		}	
		cout<<count<<endl;
	}
	return 0;
}			
					
