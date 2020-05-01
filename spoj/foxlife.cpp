#include<bits/stdc++.h>
using namespace std;
#define M 1000000
typedef long long int ll;
map< ll,ll > m,m1;
set< ll > s;
vector < ll > v[M];
ll n,e,cnt=0,x,y;

void DFS(ll current)
{
	//cout<<"dfs "<<current<<endl;
	m[current]=2;
	int i;
	for(i=0;i<v[m1[current]].size();i++)
	{
		if(m[v[m1[current]][i]]==1)
		{
			DFS(v[m1[current]][i]);
		}
	}
}			
int main()
{
	scanf("%lld %lld",&n,&e);
	if(e==0)
	{
		cout<<n<<endl;
		return 0;
	}
	ll index=0;
	while(e--)
	{
		scanf("%lld %lld",&x,&y);
		s.insert(x);
		s.insert(y);
		if(m[x]!=1)
		{
			m[x]=1;
			m1[x]=index++;
		}
		if(m[y]!=1)
		{
			m[y]=1;
			m1[y]=index++;
		}	
		v[m1[x]].push_back(y);
		v[m1[y]].push_back(x);
	}
	/*map < ll , ll > :: iterator im;
	for(im=m.begin();im!=m.end();im++)
	{
		cout<< m[im] <<" ";
	}*/
	/*int i,j;
	for(i=0;i<=6;i++)
	{
		cout<<i<<" ";
		for(j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/			
	set< ll > ::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		if(m[*it]==1)
		{
	//		cout<<endl<<*it<<endl;
			DFS(*it);
			cnt++;
		}
	}
	//cout<<"cnt"<<cnt<<endl;
	ll remain=n-m.size();
	//cout<<"remain"<<remain<<endl;
	cnt+=remain;
	cout<<cnt<<endl;		
		
	return 0;
}					
