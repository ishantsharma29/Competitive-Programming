#include<bits/stdc++.h>
#define rep(i,x,n) for(i=x;i<n;i++)
using namespace std;
struct way
{
	long long int node;
	long long int cost;
};

bool operator <(way a,way b)
{
	return a.cost>b.cost;
}

int main()
{
	long long int n,m,i,j,k,u,v,c;
	scanf("%lld %lld",&n,&m); //nodes, edges
	vector<way> adj[10005];
	
	rep(i,0,m)
	{
		scanf("%lld %lld %lld",&u,&v,&c); //edge btw u and v with cost c
		adj[u].push_back((way){v,c});
		adj[v].push_back((way){u,c});
	}
	
	long long int st,mincost=0;
	st=1;
	
	priority_queue<way> pq;
	
	rep(i,0,adj[st].size())
		pq.push(adj[st][i]);
	int visited[10005]={0};
	visited[st]=1;
	
	while(!pq.empty())
	{
		way x=pq.top();
		pq.pop();
		if(visited[x.node]==1)continue;
		visited[x.node]=1;
		mincost+=x.cost;
		rep(i,0,adj[x.node].size())
			pq.push(adj[x.node][i]);
	}
	cout<<mincost<<endl;
	return 0;
}
