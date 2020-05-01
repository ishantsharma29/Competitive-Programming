#include<bits/stdc++.h>
using namespace std;

int BIT[30005];
struct node
{
	int start;
	int end;
	int value;
	int q;
}base[230005];	



int cmp(node a,node b)
{
	if(a.value==b.value)
		return a.end > b.end;
	else
		return a.value > b.value;
}	
void update(int index,int size)
{
	int idx;
	for(idx=index;idx<=size;idx+=idx&(-idx))
	{
		BIT[idx]+=1;
	}
}

int query(int index)
{
	int idx;
	int sum=0;
	for(idx=index;idx>0;idx-=idx&(-idx))		
	{
		sum+=BIT[idx];
	}
	return sum;
}
void print(int n)
{
	int i;
	for(i=1;i<=n;i++)
		cout<<BIT[i]<< " ";
}		
int main()
{
	int n,i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&base[i].value);
		base[i].start=i+1;
		base[i].end=-1;
		BIT[i]=0;		
	}
	scanf("%d",&m);
	int ans[m+1];
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&base[i+n].start,&base[i+n].end,&base[i+n].value);	
		base[i+n].q=i;
	}
	sort(base,base+n+m,cmp);
	for(i=0;i<n+m;i++)
	{
		
		if(base[i].end == -1 )
		{
			update(base[i].start,n);
		
		}
		else
		{
			ans[base[i].q]=( query(base[i].end)-query(base[i].start-1) );
		}		
	}
	for(i=0;i<m;i++)
		printf("%d\n",ans[i]);
	return 0;
}			
