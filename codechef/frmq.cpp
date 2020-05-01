#include<bits/stdc++.h>
using namespace std;

#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked
#define M 1000005
/*inline void inp(int &n)
{
	int sign=1; n=0;int ch=getcx();
	while( ch < '0' || ch >'9' ) { if(ch=='-') sign=-1;ch=getcx();}
	while( ch >= '0'&& ch <= '9' )  
	n=(n<<3)+(n<<1)+(ch-'0'),ch=getcx();
	n=n*sign;
}*/	

#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp(n) scanf("%lld",&n)
#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);
#define ll long long int

int e,s;
ll ans=0,n,m,x,y,a[M],b[M],p,k,big;
ll rec(int s,int e,int magic) 
{
	ll big=a[s++];
	for(int i=s;i<=e;)
	{
		
		if(i%magic==0 && i+magic-1<=e )
		{
			big=max( big,b[i/magic] );
			i=i+magic;
		}
		else
			big=max(big,a[i++]);
	}
//	chk(big);
	return big;
}			
int main()
{
	inp(n);
	for(int i=0;i<n;i++)
	{
		inp(p);
		a[i]=p;
	}
	int magic=sqrt(n);
	inp(m);inp2(x,y);
	//int v=max(1000000000,0);
	//cout<<v;
	//return 0;
	
	for(int i=0;i<n;i++)
	{
		k=0;
		big=0;	
		while(k<magic)
		{
			big=max(big,a[i+k]);
			k++;
		}
		b[i/magic]=big;
		i=i+magic-1;	
	}
//	for(int i=0;i<sqrt(n);i++)
//			cout<<b[i]<<" ";
//		cout<<endl;
	int j=0;
	for(;j<m;j++)
	{
		if(j==0)
		{
			s=min(x,y);
			e=max(x,y);			
			ans+=rec(s,e,magic);
		}
		else
		{
			x=(x+7)%(n-1);
			y=(y+11)%n;
//			chk2(x,y);
			s=min(x,y);
			e=max(x,y);			
			ans+=rec(s,e,magic);
		}
	}
	outl(ans);
	return 0;
}			
									
