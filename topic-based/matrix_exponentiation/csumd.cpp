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
#define mod 1000000007
typedef long long int ll;


void mul( ll M[2][2], ll Q[2][2] )
{
	ll x1= ( (M[0][0] * Q[0][0])%mod +( M[0][1] * Q[1][0] ) % mod )% mod;
	ll x2= ( (M[0][0] * Q[0][1])%mod +( M[0][1] * Q[1][1] ) % mod )% mod;
	ll x3= ( (M[1][0] * Q[0][0])%mod +( M[1][1] * Q[1][0] ) % mod )% mod;
	ll x4= ( (M[1][0] * Q[0][1])%mod +( M[1][1] * Q[1][1] ) % mod )% mod;
	M[0][0]=x1;
	M[0][1]=x2;
	M[1][0]=x3;
	M[1][1]=x4; 
}

void power( ll M[2][2] , ll p )
{
	if (p==1)
		return ;
	ll Q[2][2]={ {2,2}, {1,0} };

	power( M,p/2);
	mul(M,M);
	if(p&1)
	mul(M,Q);
}	

void solve(int n)
{
	if(n==1)
	{
		cout<<"1"<<endl;
		return;
	}
	if(n==2)
	{
		cout<<"3"<<endl;
		return ;
	}		
	ll M[2][2]={ {2,2}, {1,0} };
	ll F[2][1]={3,1};
	power( M,n-2);
	ll ans=( ( M[0][0] * F[0][0])% mod + (M[0][1]*F[1][0] )%mod ) % mod;
	outl(ans);
}	
	

int main()
{
	int t,n;
	inp(t);
	while(t--)
	{
		inp(n);
		solve(n);
	}
}		
