#include<bits/stdc++.h>
using namespace std;
#define M 1001
int n,m,cnt=0,visited[M][M]={0};
char a[M][M],e;


int safe(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
		return 1;
	return 0;
}		
void Dfs(int x ,int y)
{
	
	visited[x][y]=1;
	if(a[x][y]=='S' && visited[x+1][y]==0 && safe(x+1,y))
		Dfs(x+1,y);
	else if(a[x][y]=='N' && visited[x-1][y]==0 && safe(x-1,y))
		Dfs(x-1,y);
	else if(a[x][y]=='E' && visited[x][y+1]==0 && safe(x,y+1))
		Dfs(x,y+1);
	else if(a[x][y]=='W' && visited[x][y-1]==0 && safe(x,y-1))
		Dfs(x,y-1);
	if(a[x][y+1]=='W' && visited[x][y+1]==0 && safe(x,y+1))
		Dfs(x,y+1);
	if(a[x-1][y]=='S' && visited[x-1][y]==0 && safe(x-1,y))
		Dfs(x-1,y);
	if(a[x][y-1]=='E' && visited[x][y-1]==0 && safe(x,y-1))
		Dfs(x,y-1);
	if(a[x+1][y]=='N' && visited[x+1][y]==0 && safe(x+1,y))
		Dfs(x+1,y);
}							
	
int main()
{
	int i,j;
	string s;
	scanf("%d %d",&n,&m);
	scanf("%c",&e);
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=0;j<m;j++)
		{
			
			a[i][j]=s[j];
		}
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			
			if(visited[i][j]==0)
			{
				cnt++;
				Dfs(i,j);
				
						
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}						
