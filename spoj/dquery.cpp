#include<bits/stdc++.h>
using namespace std;
#define N 30004
#define M 1000005
int BIT[N];
#define getcx getchar_unlocked

inline void inp(int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}

struct node
{
	int value;
	int next_index;
}a[N];	

int n,b[M],i,x,y,q;
vector< pair< pair<int,int> , int > > v;

void update(int index,int size,int val)
{
	int idx;
	for(idx=index;idx<=size;idx+=idx&(-idx))
	{
		BIT[idx]+=val;
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
	cout<<endl;	
}


int main()
{
	inp(n);
	//scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		inp(x);
		//scanf("%d",&x);
		a[i].value=x;
		a[b[x]].next_index=i;
		b[x]=i;
		
	}
	//cout<<endl;
	/*for(i=1;i<=n;i++)
	{
		cout<<a[i].value<<" " <<a[i].next_index<<endl;
	}*/	
	inp(q);
	//scanf("%d",&q);
	int q_no=1;
	while(q--)
	{
		inp(x);inp(y);
	//	scanf("%d",&x);
	//	scanf("%d",&y);
		v.push_back(make_pair(make_pair(x,y),q_no));
		q_no+=1;
	}
	sort(v.begin(),v.end());
	/*cout<<endl;
	for(i=0;i<v.size();i++)
	{
		cout<<v[i].first.first<<" " << v[i].first.second<<" " <<v[i].second<<endl;
	}*/
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		if(b[a[i].value]==0)
		{
			update(i,n,1);
			b[a[i].value]=1;
		}	
	}		
	//print(n);
	int ans[M];
	int idx=1;
	i=0;
	while( i < v.size() )
	{
		while(	v[i].first.first==idx && i<v.size() )
		{
			ans[v[i].second]=query(v[i].first.second);
			i++;
		}
		if(i<v.size())
		{
			update(idx,n,-1);
			if(a[idx].next_index!=0)
			update(a[idx].next_index,n,1);
			idx=idx+1;
	//		print(n);
		}
	}			
	for(i=1;i<q_no;i++)
	{
		printf("%d\n",ans[i]);
	}				
	return 0;
}			
