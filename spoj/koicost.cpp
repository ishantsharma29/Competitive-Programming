#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define N 1000000000
long long int parent[M],rank[M],size[M],cs[M];
long long int n,m,x,y,w,i;
long long int ans=0;
vector< pair< long long int, pair< long long int,long long int > > > v;
long long int find(long long int u)
{
	if(u==parent[u])
		return u;
	else 
	return (parent[u]=find(parent[u]));
}		
void _union(long long int u,long long int v)
{
	long long int pu=find(u);
	long long int pv=find(v);
	if(pu!=pv)
	{
		if(rank[pu]>rank[pv])
		{
			parent[pv]=pu;
			size[pu]+=size[pv];
			
		}	
		else if(rank[pv]>rank[pu])
		{
			parent[pu]=pv;
			size[pv]+=size[pu];
			//cout<<cost<<endl;
			
		}	
		else
		{
			parent[pu]=pv;
			rank[pv]++;
			size[pv]+=size[pu];
						//cout<<cost<<endl;
		}
	}
		
}

int main()
{
	long long int sum=0;
	scanf("%lld %lld",&n,&m);
	
	while(m--)
	{
		scanf("%lld %lld %lld",&x,&y,&w);
		v.push_back(make_pair(w,make_pair(x,y)));
	}
	for(i=0;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=1;
		size[i]=1;
	}
	sort(v.rbegin(),v.rend());
	for(i=(long long int)v.size()-1;i>=0;i--)
	{
		sum=(sum+v[i].first)%N;
		cs[i]=sum;
	}
	
	for(i=0;i<v.size();i++)
	{
		long long int pu=find(v[i].second.first);
		long long int pv=find(v[i].second.second);
		if(pv != pu)
        	ans = (ans)+ (((size[pv]*size[pu])%N) * cs[i])%N;
    		ans = ans%N;
		_union(v[i].second.first,v[i].second.second);
		//cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
	}
	cout<<ans<<endl;
	return 0;
}			 
