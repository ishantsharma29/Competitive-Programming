#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long double ans;
		ans=n*log(n)+0.5772156694*n+0.5;
		cout<<ans<<endl;
	}
	return 0;
}		
