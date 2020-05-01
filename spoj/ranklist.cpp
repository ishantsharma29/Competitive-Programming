/*
	Created BY--
	Ishant Sharma
	ishantsharma29@gmail.com
*/	


#include<bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long int ll;

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

ll sum[M];

void precompute()
{
	for(int i=1;i<M;i++)
	{
		sum[i]=i+sum[i-1];
	}
}

int main()
{
	precompute();	
	int t,n,res;
	ll s;
	inp(t);
	while(t--)
	{
		inp(n);scanf("%lld",&s);
		if(s==sum[n])
		{
			printf("0\n");
			continue;
		}
		for(int i=n-1;i>0;i--)
		{
			if(s>sum[i] && n-i<=s-sum[i] )
			{
				res=n-i;
				break;
			}
		}
		out(res);
	}
	return 0;
}

	

