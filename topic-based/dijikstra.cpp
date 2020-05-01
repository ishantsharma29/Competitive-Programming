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
		adj[u].push_back((way){v,c});//make_pair(v,c)
		//adj[v].push_back((way){u,c});
	}
	
	int st,mincost=0;
	cout<<"enter the start vertex"<<endl;
	cin>>st;
	
	priority_queue<way> pq;
	
	rep(i,0,adj[st].size())
		pq.push(adj[st][i]);
	int visited[1000]={0};
	visited[st]=1;
	int d[1000];
	for(i=0;i<=n;i++)
		d[i]=INT_MAX;
	d[st]=0;	
	while(!pq.empty())
	{
		way x=pq.top();//pair<int,int> ap and ap=pq.top() and then ap.first and ap.second 
		pq.pop();
		if(visited[x.node]==1)continue;
		
		visited[x.node]=1;//visited[ap.first]=1
		
		d[x.node]=x.cost;//d[ap.first]=ap.second
		
		cout<<"EDGE "<<x.node<<" DISTANCE OF THIS VERTEX FROM SOURCE-"<<d[x.node]<<endl;
		//mincost+=x.cost;
		
		rep(i,0,adj[x.node].size())//
		{
			//way y=adj[x.node][i];OR pair bp=adj[x.node][i];
			
			pq.push((way){adj[x.node][i].node,adj[x.node][i].cost+d[x.node]});
			
			//(way){adj[x.node][i].node,adj[x.node][i].cost+d[x.node]} OR {y.node,y.cost+d[x.node]} or make_pair(bp.first,bp.second+d[ap.first])
		}	
	}
	/*for(i=1;i<=n;i++)
	{
		//mincost+=d[i];
		cout<<d[i]<<" "<<endl;
	}	*/
	
	return 0;
}
