#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define M 100
int visited[M],n,e,x,y,i,s,k;
using namespace std;
	vector<int> v[M];
void BFS(int source)
{

	queue<int> q;
	visited[source]=1;
	q.push(source);
	while(!q.empty())
	{
		k=q.front();
		printf("%d ",k);
		q.pop();
		for(i=0;i<v[k].size();i++)
		{
			if(!visited[v[k][i]])
			{
				q.push(v[k][i]);
				visited[v[k][i]]=1;
			}
		}
	}
}

	int main()
	{

		scanf("%d",&n);
		scanf("%d",&e);
		//while(n--)
		//scanf("%d",&v[i]);
		while(e--)
		{
			scanf("%d %d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<v[i].size();j++)
                            {
                             printf("%d %d\n",i,v[i][j]);
			    }
		}index i is the vertex name*/
		/*for(i=0;i<M;i++)
		{ 
			
                   //     printf("%d %d\n",maxi,v[i].size());
                         int c=v[i].size();
 			if(c>maxi)
			  {
				maxi=c;
				idx=i;
			  }
		}
		printf("%d ",idx);the vertex with max degree*/
		scanf("%d",&s);
		BFS(s);
		return 0;
	}
