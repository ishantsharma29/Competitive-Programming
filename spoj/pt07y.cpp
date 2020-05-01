#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define M 10005
int visited[M],parent[M],n,e,x,y,i,k,flag=0;
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
		//printf("%d ",k);
		q.pop();
		for(i=0;i<v[k].size();i++)
		{
			if(parent[k]==v[k][i])
			{
				continue;
			}
			else if(!visited[v[k][i]])
			{
		                parent[v[k][i]]=k;
				q.push(v[k][i]);
				visited[v[k][i]]=1;
			}
			else
			{
		                flag=1;
		                break;
			}
		}
		if(flag==1)
	            break;
	}
}

	int main()
	{

		scanf("%d %d",&n,&e);
		if(e==0)
        {
        if(n==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        return 0;

        }
		while(e--)
		{
			scanf("%d %d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=1;i<=n;i++)
		{
            parent[i]=i;
		}
		BFS(1);
		for(i=2;i<=n;i++)
		{
            if(visited[i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
		return 0;
	}
