#include<bits/stdc++.h>
using namespace std;

#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked

inline void inp(int &n)
{
	int sign=1; n=0;int ch=getcx();
	while( ch < '0' || ch >'9' ) { if(ch=='-') sign=-1;ch=getcx();}
	while( ch >= '0'&& ch <= '9' )  
	n=(n<<3)+(n<<1)+(ch-'0'),ch=getcx();
	n=n*sign;
}	

#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);


vector< pair<int,int> > v;
set<int> s,se;
map<int,int> m;
int lazy[100005];

void check(int idx ,int l,int r)
{
	if(lazy[idx])
	{
		se.insert( lazy[idx] );
		return;
	}
	int mid=(l+r)/2;
	check(idx*2,l,mid);
	check(idx*2+1,mid+1,r);
}		

void shift( int idx )
{
	if(lazy[idx] )
	{
		lazy[2*idx]=lazy[2*idx+1]=lazy[idx];
		lazy[idx]=0;
	}
}		

void update( int idx, int l, int r ,int x, int y, int color )
{
	if( x>r || y<l || l>r ) return ;
	if( l>=x && r<=y )
	{
		lazy[idx]=color;
		return;
	}
	int mid=(l+r)/2;
	shift( idx );
	update( idx*2,l,mid,x,y,color);
	update( idx*2+1,mid+1,r,x,y,color);
}		
int main()
{
	int t,n,x,y;
	inp(t);
	while(t--)
	{
		s.clear();
		se.clear();
		clr(lazy);
		inp(n);
		while(n--)
		{
			inp(x);inp(y);
			v.pb(MP(x,y));
			s.insert(x);
			s.insert(y);
		}
		int i=1;
		set<int> :: iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			m[*it]=i++;
		}
		for(int j=0;j<v.size();j++)
		{
			update(1,1,i-1,m[v[j].first],m[v[j].second],j+1);
		}
		check(1,1,i-1);
		//cout<<se.size()<<endl;
		printf("%d\n",se.size() );
	}
	return 0;
}				
				
