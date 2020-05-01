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
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);
#define ll long long int

int t,n,k,e,m,x;

int main()
{
	inp(t);
	while(t--)
	{
		inp2(n,k);inp2(e,m);
		ll a[n+5],s,s1=0;
		rep(i,n-1)
		{
			s=0;
			rep(j,e)
			{
				inp(x);
				s+=x;
			}
			a[i]=s;
		}
		rep(i,e-1)
		{
			inp(x);
			s1+=x;
		}
		sort(a,a+n-1);
		s=a[n-k-1];
		if(s>=s1)
		{
			if( (s-s1)>=m )
			{
				printf("Impossible\n");
			}
			else
			{
				ll diff=s-s1+1;
				printf("%lld\n",diff);
			}
		}
		else 
		{
			printf("0\n");
		}	
					
	}
	return 0;
}			
		
