#include<bits/stdc++.h>
using namespace std;


#define getcx getchar_unlocked


inline void inp(int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}


int main()
{
	int t,n,m,i,l,r;
	inp(t);
	while(t--)
	{
		inp(n);
		vector < pair<int,int> > v;
		m=n;
		i=0;
		while(m--)
		{	inp(l);
			inp(r);
			v.push_back(make_pair(r,-l));			
		}
		
		sort(v.begin(),v.end());
		
		int cnt=0;
		int m=-1;
		for(i=0;i<v.size();i++)
		{
			//cout<<-v[i].second<<" "<<v[i].first<<endl;
			
			if(-v[i].second>=m)
			{
				cnt++;
				m=v[i].first;
			}	
										
		}
		printf("%d\n",cnt);
		//cout<<cnt<<endl;
		
	}
	return 0;
}				
		
