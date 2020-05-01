#include<bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long int ll;
ll a[M],ans;
int c,n;

int possible(int distance)
{
	int placed=1;
	int i;
	ll pos=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]-pos>=distance)
		{
			placed++;
			if(placed==c)
				return 1;
			pos=a[i];
		}
	}
	return 0;
}				

ll binar_search()
{
	int s=0,e=a[n-1];
	while(s<=e)
	{
		ll mid=(s+e)>>1;
		if( possible(mid)==1 )
			s=mid+1;
		else
			e=mid-1;
	}
	return s-1;
}				
	

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
	
		scanf("%d %d",&n,&c);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		ans=binar_search();
		printf("%lld\n",ans);
	}
	return 0;
}			
