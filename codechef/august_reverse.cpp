#include<bits/stdc++.h>

using namespace std;

#define M 100002
vector<int> v[M];
vector<int> p[M];

struct way
{
	int node;
	int cost;
};

bool operator <(way a,way b)
{
	return (a.cost>b.cost);	
}

int visited[M];
int n,m,x,y,i,c=0,present=0,d[M];

void dijikstra(int current)
{

priority_queue< way > pq;
	for(int i=0;i<v[current].size();i++)
	{
		pq.push((way){v[current][i],0});
	}	
	for(int i=0;i<p[current].size();i++)
	{
		pq.push((way){p[current][i],1});
	}
	d[1]=0;	
	visited[1]=1;
	while(!pq.empty())
	{
		way x=pq.top();
		pq.pop();
		
		if(visited[x.node]==1)continue;
		else
		{
			visited[x.node]=1;
			d[x.node]=x.cost;
			if(x.node==n)
			{
				c=x.cost;
				present=1;
				break;
			}
			for(int i=0;i<v[x.node].size();i++)
			{
				pq.push((way){v[x.node][i],d[x.node]});
			}	
			for(int i=0;i<p[x.node].size();i++)
			{		
				pq.push((way){p[x.node][i],d[x.node]+1});
			}				
		}
	}
}				

int main()
{
//int j;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		if(x==y)
		{
			continue;
		}
		v[x].push_back(y);
		p[y].push_back(x);
	}
/*	for(i=1;i<=n;i++)
	{
		cout<<" v[i]"<<i;
		for(j=0;j<p[i].size();j++)
		{
			cout<<" "<<p[i][j];
		}
		cout<<endl;
	}*/	
	for(i=1;i<=n;i++)
		d[i]=INT_MAX;
		
	dijikstra(1);
	if(present==1)
		cout<<c;
	else
		cout<<"-1";
	return 0;
}
