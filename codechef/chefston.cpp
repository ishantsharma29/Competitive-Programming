#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define getcx getchar_unlocked

inline void inpl( ll &n )
{
n=0; ll ch=getcx();ll sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
int main()
{
	int t;
	//scanf("%d",&t);
	inp(t);
	while(t--)
	{
		int n,i;
		ll k;
		//scanf("%d %lld",&n,&k);
		inp(n);
		inpl(k);
		ll a[n+1],b[n+1],x;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			a[i]=x;
		}
		for(i=1;i<=n;i++)
		{
			//scanf("%lld",&x);
			inpl(x);
			b[i]=x;
		}
		//double d,maxi=0;
		//int pos;
		ll no,ans=0;
		for(i=1;i<=n;i++)
		{
			no=k/a[i];
			ll temp=no*b[i];
			if(temp>ans)
			{
				ans=temp;
			}	
					
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}					
