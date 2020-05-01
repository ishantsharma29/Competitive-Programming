#include<bits/stdc++.h>
using namespace std;

#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked

typedef long long int ll;
inline void inp(ll &n)
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
//http://apps.topcoder.com/forums/;jsessionid=1561189C2F214AF5CF3C0B6A110179D3?module=Thread&threadID=690857&start=0&mc=14#1300475
void mul_G( int M[3][3], int Q[3][3] )
{
	/*ll x1= ( (M[0][0] * Q[0][0])%mod +( M[0][1] * Q[1][0] ) % mod +( M[0][2]* Q[2][0])% mod ) % mod;
	ll x2= ( (M[0][0] * Q[0][1])%mod +( M[0][1] * Q[1][1] ) % mod + (M[0][2]* Q[2][1]) % mod )% mod;
	ll x3= ( (M[1][0] * Q[0][0])%mod +( M[1][1] * Q[1][0] ) % mod )% mod;
	ll x4= ( (M[1][0] * Q[0][1])%mod +( M[1][1] * Q[1][1] ) % mod )% mod;
	M[0][0]=x1;
	M[0][1]=x2;
	M[1][0]=x3;
	M[1][1]=x4; 

	*/
	int W[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			W[i][j]=0;
			ll tmp=0;
			for(int k=0;k<3;k++)
			{
				tmp+=( (long long)M[i][k] ) * Q[k][j] ;
				 
			}
			W[i][j]= tmp % mod;
		}
	}
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	M[i][j]=W[i][j];		
}

	
void power_G( int Q[3][3] , ll p )
{
	if (p==1)
		return ;
	int I[3][3]= { {1,2,1} ,{0,5,3} ,{0,3,2} };

	power_G( Q,p/2);
	mul_G(Q,Q);
	if(p&1)
	mul_G(Q,I);
}	


void solve(ll n)
{
	if(n==0)
	{
		cout<<"0"<<endl;
		return;
	}
	if(n==1)
	{
		cout<<"2"<<endl;
		return;
	}	
	int Q[3][3]={ {1,2,1} ,{0,5,3} ,{0,3,2} };
	power_G( Q,n );
	int ans= Q[0][1];
	out ( ans );
}	
	

int main()
{
	ll n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		inp(n);
		
		solve(n);
	}
}		
