#include<bits/stdc++.h>
using namespace std;
#define INF 999999999

int ans[1 << 22];		//to store the intermediate answers----dp
int unsat[ 1 << 22]={0}; //to store the number of unsatisfied pairs in the current permutation
int main()
{
	int n,m,x,y,pos,i,j,cnt,prev,k;
	int Graph[22][22]={0};
	int degree[22]={0};
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		degree[x]++;
		degree[y]++;
		Graph[x][y]=Graph[y][x]=1;
	}
		
	for(i=0;i<(1<<22);i++)   //initialize the whole ans array as infinity
		ans[i]=INF;
	
	ans[0]=unsat[0]=0; 		//if there is no element in permutation 
	for(i=0;i<(1<<n);i++)
	{
		x=i;
		pos=0;
		vector<int> v;
		while(x)
		{
			if(x & 1)//to check whether the least significant bit is 1 
				v.push_back(pos);//store the position of bit which is 1
			pos++;
			x=x/2;//right shift one bit
		}
		for(j=0;j<v.size();j++)
		{
			prev= i ^ (1<<v[j]);
			cnt=0;
			for(k=0;k<v.size();k++)
				if(Graph[v[j]][v[k]])
					cnt++;
			if(ans[i]>ans[prev]+unsat[prev]+degree[v[j]]-2*cnt)
			{
				unsat[i]=unsat[prev]-cnt+degree[v[j]]-cnt;
				ans[i]=ans[prev]+unsat[i];
			}
		}
		//cout<<"ans[i]"<<": "<<ans[i]<<endl;
	}
	cout<<ans[(1<<n)-1]<<endl;
	return 0;
}			
						
							
		
