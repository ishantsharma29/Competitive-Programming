/*
	Created BY--
	Ishant Sharma
	ishantsharma29@gmail.com
*/	


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked
//typedef long long int ll;

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
#define outl(n) printf("%lld\n",n)


int main()
{
	int n;
	ll x;
	vector< ll > v;
	inp(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x);
		v.pb(x);
	}
	sort(v.rbegin(),v.rend());
	ll sgn=1;
	while(sgn<=v[0])
	sgn=sgn<<1;
	
	sgn=sgn>>1;
	
	for(int t=0; sgn>=1; sgn=sgn>>1 )
	{
		int i=t;
		while(i<n && (sgn&v[i])==0)
		i++;
		
		if(i>=n)
		continue;
		
		swap(v[t],v[i]);
		
		for(int j=t+1;j<n;j++)
		{
			if( (v[j]&sgn) )
			v[j]=v[j]^v[t];
		}
		
		t++;
	}
	ll res=0;
	for(int k=0;k<n;k++)
	{
		//cout<<v[k]<<endl;
		ll temp=res^v[k];
		res=max(res,temp);
	}
	printf("%lld\n",res);
	return 0;
}					
		
		
		
	
	
					
		
