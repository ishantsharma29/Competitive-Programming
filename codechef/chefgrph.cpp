
#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef long long ll;

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

ll n;
int m,k;
ll dp[111][111];

struct way
{
	ll b1,b2;int n1,n2;
}a[100005];

int comp(way a ,way b)
{
	return ((a.b2==b.b2) ? a.n2<b.n2:a.b2<b.b2);
}			

int main()
{
	scanf("%lld",&n); inp(m); inp(k);	
	for(int i=0;i<k;i++)
	{
		scanf("%lld %d %lld %d",&a[i].b1,&a[i].n1,&a[i].b2,&a[i].n2);
		//mi[ make_pair(a[i].b1,a[i].n1) ] = mi[ make_pair(a[i].b2,a[i].n2) ] = -1; 
	}
	sort(a,a+k,comp);
	/*for(int i=0;i<k;i++)
	{
		cout<<a[i].b1<<"  "<<a[i].n1<<" "<<a[i].b2<<" "<<a[i].n2<<endl;
	}*/
	int p=0,i,j;
	for(j=0;j<m;j++)
	{
		dp[j][1]=1;
	}
	
	while(a[p].b2==1 && p<k )
	{
		dp[ a[p].n2 ][1] +=1;
		p++;
	}
	ll sum;	
	for(i=2;i<=n;i++)
	{
		sum=0;
		for(j=0;j<m;j++)
		{
			sum=(sum+dp[j][i-1])%M;
		}	
		for(j=0;j<m;j++)
		{
			dp[j][i]=sum;
		}
		while(a[p].b2==i && p<k )
		{
			if( a[p].b1==0)
			{
				dp[ a[p].n2 ][i]=(dp[ a[p].n2 ][i]+1)%M;
			}
			else
			{	
				dp[ a[p].n2 ][i] +=dp[ a[p].n1][a[p].b1];
				dp[ a[p].n2 ][i]=( dp[ a[p].n2 ][i] )%M;
			}
			p++;
		}
	}
	sum=0;
	for(j=0;j<m;j++)
	{
		sum=sum+dp[j][n];
		sum=sum%M;
	}
	while(p<k)
	{
		sum=sum+ dp[a[p].n1][a[p].b1] ;
		sum=sum%M;
		p++;
	}	
	cout<<sum<<endl;			
	return 0;
}		
