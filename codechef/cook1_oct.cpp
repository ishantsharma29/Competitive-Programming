#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll p=n*(n+1)/2;
		p=p+n;
		printf("%lld\n",p);
	}
	return 0;
}		
