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
	int n,m,i,j,k,u,v,c;
	cin>>n>>m; //nodes, edges
	vector<way> adj[1000];
	
	rep(i,0,m)
	{
		cin>>u>>v>>c; //edge btw u and v with cost c
		adj[u].push_back((way){v,c});
		adj[v].push_back((way){u,c});
	}
	
	int st,mincost=0;
	cout<<"enter the start vertex"<<endl;
	cin>>st;
	
	priority_queue<way> pq;   // priority_queue< pair<int,int> ,vector< pair<int,int> > ,greater< pair<int,int> > > pq(MINHEAP
				  //	priority_queue< pair<int,int> ,vector< pair<int,int> > > pq maxheap
	
	rep(i,0,adj[st].size())
		pq.push(adj[st][i]);
	int visited[1000]={0};
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
