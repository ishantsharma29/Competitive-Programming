#include<bits/stdc++.h>
using namespace std;
#define M 101
int main()
{
	int a[M][M]={0};
	int x,y;
	vector< pair<int,int> > v;
	int n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
	}
	long long int c=0;
	int flag=0;
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=m;j++)
		{
			if(flag==0)
			{
				if(a[i][j]==0)
				{
					c++;
					//cout
					v.push_back(make_pair(i,j));
					flag=1;	
				}
			}
			else
			{
				if(a[i][j]==0)
				{}
				else
				{
					flag=0;
				}
			}
		}
	}
	cout<<c<<endl;
	vector< pair<int,int> >:: iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		cout<<it->first<<" "<<it->second<<" 0"<<endl;
	}
	return 0;
}						
					
