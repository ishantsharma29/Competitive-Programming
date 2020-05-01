#include<bits/stdc++.h>
#define rep(i,x,n) for(i=x;i<n;i++)
using namespace std;
struct X
{
	int u,v,c;
}edge[1000];


int parent[1000];

int cmp(struct X a,struct X b)
{
	return a.c==b.c?(a.u<=b.u?1:0):(a.c<b.c?1:0);
}


int find(int u)
{
	if(parent[u]==u)return u;
	int x=find(parent[u]);
	parent[u]=x;
	return x;
}

void _union(int u,int v)
{
	parent[find(u)]=find(v);
}


int main()
{
	int i,j,k,n,m,u,v,c;
	cin>>n>>m; //nodes ,edges
	rep(i,1,n+1)parent[i]=i;
	
	rep(i,0,m)
		cin>>edge[i].u>>edge[i].v>>edge[i].c;
	sort(edge,edge+m,cmp);
	//rep(i,0,m)cout<<edge[i].u<<edge[i].v<<edge[i].c<<endl;
	int mincost=0;
	rep(i,0,m)
	{
		if(find(edge[i].u)==find(edge[i].v)){}
		else {
			mincost+=edge[i].c;
			_union(edge[i].u,edge[i].v);
		}
	}
	cout<<mincost<<endl;
	return 0;
}
