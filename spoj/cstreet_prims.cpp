#include<bits/stdc++.h>
#define rep(i,x,n) for(i=x;i<n;i++)
using namespace std;
struct way
{
	int node;
	int cost;
};

bool operator <(way a,way b)
{
	return a.cost>b.cost;
}

int main()
{
	int n,m,i,j,k,u,v,c,t,p;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&p);
	scanf("%d",&n);
	scanf("%d",&m);
	vector<way> adj[1005];
	
	rep(i,0,m)
	{
		scanf("%d %d %d",&u,&v,&c); //edge btw u and v with cost c
		adj[u].push_back((way){v,c});
		adj[v].push_back((way){u,c});
	}
	
	int st,mincost=0;
	st=1;
	priority_queue<way> pq;
	
	rep(i,0,adj[st].size())
		pq.push(adj[st][i]);
	int visited[1005]={0};
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
	mincost=mincost*p;
	cout<<mincost<<endl;
	}
	return 0;
}

