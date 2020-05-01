#include <bits/stdc++.h>
using namespace std;
#define M 2002

long long int visited[M],level[M];
long long int t,n,e,x,y,i,s,k;

	
int BFS(long long int source, vector<long long int> v[])
{
	queue<long long int> q;
	visited[source]=1;
	level[source]=0;
	//level=1;
	q.push(source);
	while(!q.empty())
	{
		k=q.front();
		
		//printf("%lld ",k);
		q.pop();
		//visited[k]=2;
		for(i=0;i<v[k].size();i++)
		{
			if(visited[v[k][i]]==0)
			{
				q.push(v[k][i]);
				visited[v[k][i]]=1;
				level[v[k][i]]=level[k]+1;
			}
			else if(visited[v[k][i]]==1 && level[k]==level[v[k][i]])
			{
				return 1;
			}	
		}
	}
	return 0;
}

	int main()
	{
		scanf("%lld",&t);
		long long int no=1;
		while(t--)
		{
		vector<long long int> v[M];
		for(i=0;i<M;i++)
		{
			visited[i]=0;
			level[i]=0;
		}	
		scanf("%lld %lld",&n,&e);
		while(e--)
		{
			scanf("%lld %lld",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int flag=0;
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				int res=BFS(i,v);
				if (res==1)
				{
				
					flag=1;
					break;				
				}
			}
		}		
		if(flag==0)
		{
			
			cout<<"Scenario #"<<no<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"Scenario #"<<no<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}	
		no=no+1;
		/*for(i=0;i<v[1].size();i++)
		{
			cout<<v[1][i]<<"\t";
		}
		cout<<endl;*/	
		}
		return 0;
	}
