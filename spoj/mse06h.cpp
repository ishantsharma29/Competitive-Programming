#include<bits/stdc++.h>
using namespace std;

int BIT[1005];
struct highway
{
	int ecity;
	int wcity;
};	

int cmp(struct highway a, struct highway b)
{
	return a.ecity==b.ecity?(a.wcity<=b.wcity?1:0):(a.ecity<b.ecity?1:0);
}	 
void update(int index,int size)
{
	int idx;
	for(idx=index;idx<=size;idx+=idx&(-idx))
	{
		BIT[idx]+=1;
	}
}

long long int query(int index)
{
	int idx;
	long long int sum=0;
	for(idx=index;idx>0;idx-=idx&(-idx))		
	{
		sum+=BIT[idx];
	}
	return sum;
}		
int main()
{
	int n,m,k,i,x,y,no=0,t;
	scanf("%d",&t);
	while(t--)
	{	
		no++;
		scanf("%d%d%d",&n,&m,&k);
		struct highway edges[1000010];
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&x,&y);
			edges[i].ecity=x;
			edges[i].wcity=y;
		}
		memset(BIT,0,sizeof(BIT));
		sort(edges,edges+k,cmp);
		long long cnt=0;
		for(i=0;i<k;i++)
		{
			//cout<<edges[i].ecity<<" "<<edges[i].wcity<<endl;
			cnt+=(query(m)-query(edges[i].wcity));
			update(edges[i].wcity,m);
		}
		printf("Test case %d: %lld\n",no,cnt);
	}	
	return 0;
}			
