#include<bits/stdc++.h>
using namespace std;
#define M 10000
int parent[M],rank[M];
vector< pair< int, pair< int,int > > > Graph, Mst;
int find(int u)
{
	if(u==parent[u])
		return u;
	else 
	return (parent[u]=find(parent[u]));
}		
void _union(int u,int v,int c)
{
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
	
         Mst.push_back(make_pair(c,make_pair(u,v)));	
	}
}						

int main()
{
	int n,e,u,v,w,i;
	
	cin>>n;
	cin>>e;
	while(e--)
	{
		cin>>u>>v>>w;
		Graph.push_back(make_pair(w,make_pair(u,v)));
	}
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=1;
	}		
	sort(Graph.begin(),Graph.end());
	vector< pair< int, pair< int,int > > > :: iterator it;
	for(it=Graph.begin();it!=Graph.end();it++)
	{
		//cout<<it->first<<" " <<it->second.first << " " << it->second.second<<endl;
		_union(it->second.first,it->second.second,it->first);
	}
	for(it=Mst.begin();it!=Mst.end();it++)
	{
		cout<<it->first<<" " <<it->second.first << " " << it->second.second<<endl;
		
	}
	return 0;
}		
	
