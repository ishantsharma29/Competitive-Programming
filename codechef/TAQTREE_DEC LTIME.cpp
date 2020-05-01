#include<bits/stdc++.h>
using namespace std;
#define M 1009
long long int sum;
int visited[M];
vector< pair<int,int> > v[M];
vector< pair<int,int> > edge;
int dfs(int current,int end,long long int s)
{
	visited[current]=1;
	//cout<<"sum "<<s<<" current"<<current<<endl;
	int k;
	for(k=0;k<v[current].size();k++)
	{
		if(v[current][k].first==end)
		{
			sum=s+v[current][k].second;
			return 1;
		}
		if(visited[v[current][k].first]==0)
		{
			
			int f=dfs(v[current][k].first,end,s+v[current][k].second);
			if(f==1)
			return 1;
		}
	}
	return 0;
}			

int main()
{
	int n,i,a,b,w,p,q,x,y,j,type,h;
	
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&w);
		v[a].push_back(make_pair(b,w));
		v[b].push_back(make_pair(a,w));
		edge.push_back(make_pair(a,b));
		
	}
	scanf("%d",&h);
	for(i=0;i<h;i++)
	{
		scanf("%d%d%d",&type,&x,&y);
		if(type==1)
		{
			p=edge[x-1].first;
			q=edge[x-1].second;
			for(j=0;j<v[p].size();j++)
			{
				if(v[p][j].first==q)
				{
					v[p][j].second=y;
					break;
				}	
			}
			for(j=0;j<v[q].size();j++)
			{
				if(v[q][j].first==p)
				{
					v[q][j].second=y;
					break;
				}	
			}
		}
		else
		{
			memset(visited,0,sizeof(visited));
			//cout<<" "<<visited[5];
			sum=0;
			int temp=dfs(x,y,0);
			printf("%lld\n",sum);
		}
	}
	return 0;
}				
