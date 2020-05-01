#include<bits/stdc++.h>
using namespace std;

char a[110][110];
int t,r,c,i,j;
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int visited[110][110];

int safe(int x,int y)
{
	if(x>=0 && x<r && y>=0 && y<c)
		return 1;
	return 0;
}		

int dfs(int x,int y,string s,int index)
{
	
	visited[x][y]=1;
	int i;
	for(i=0;i<8;i++)
	{
		if(safe(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]] )
		{
			if(a[x+dx[i]][y+dy[i]]==s[index])
			{
				
				if(index==9)
				{
					visited[x][y]=0;	
					return 1;
				}				
				int r=dfs(x+dx[i],y+dy[i],s,index+1);
				if(r==1)
				{
					visited[x][y]=0;
					return 1;
				}
			}	
		}
	}
	visited[x][y]=0;
	return 0;
}					
		
	


int main()
{
	
	scanf("%d",&t);
	while(t--)
	{
		vector< pair<int,int> > v;
		int flag=0,k;
		char e;
		scanf("%d %d",&r,&c);
		scanf("%c",&e);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='A')
				{
					v.push_back(make_pair(i,j));
				}	
			}
			
			scanf("%c",&e);
		}
				
		for(k=0;k<v.size();k++)
		{
			
			string s="ALLIZZWELL";
			int res=dfs(v[k].first,v[k].second,s,1);
			
			if(res==1)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}					
