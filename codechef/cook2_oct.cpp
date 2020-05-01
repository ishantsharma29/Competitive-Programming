#include<bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long int ll;
int main()
{
	ll t,n,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		ll a[M]={0};
		int lp=n-1,rp=0,i,x;
		
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(x>rp)
				rp=x;
			if(x<lp)
				lp=x;
		}
		int c=0;
		for(i=lp;i<n;i++)
		{
			a[i]=c++;
		}
		c=0;				
		for(i=rp;i>=0;i--)
		{
			if(c>a[i])
				a[i]=c;
			c++;	
		}
		for(i=0;i<n;i++)
			printf("%lld ",a[i]);
		printf("\n");		
	}
	return 0;
}		
