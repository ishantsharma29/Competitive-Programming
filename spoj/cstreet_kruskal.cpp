#include<bits/stdc++.h>
#define rep(i,x,n) for(i=x;i<n;i++)
using namespace std;
struct X
{
	int u,v,c;
}edge[300005];


int parent[1005],rank[1005];

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
	//parent[find(u)]=find(v);
	int pu=find(u);
	int pv=find(v);
	if(pu!=pv)
	{
		if(rank[pu]>rank[pv])
			parent[pv]=pu;
		else if(rank[pv]>rank[pu])
			parent[pu]=pv;
		else
		{
			parent[pu]=pv;
			rank[pv]++;
		}
	}					
}


int main()
{
	int i,j,k,n,m,u,v,c,t;
	long long int p;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld",&p);
	scanf("%d",&n);
	scanf("%d",&m); //nodes ,edges
	rep(i,1,n+1)parent[i]=i;
	
	rep(i,1,n+1)rank[i]=1;
	
	rep(i,0,m)
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].c);
	sort(edge,edge+m,cmp);
	//rep(i,0,m)cout<<edge[i].u<<edge[i].v<<edge[i].c<<endl;
	long long int mincost=0;
	rep(i,0,m)
	{
		if(find(edge[i].u)==find(edge[i].v)){}
		else {
			mincost+=edge[i].c;
			_union(edge[i].u,edge[i].v);
		}
	}
	mincost=mincost*p;
	cout<< mincost <<endl;
	}
	return 0;
}
