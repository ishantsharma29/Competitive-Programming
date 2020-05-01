#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define getcx getchar_unlocked

int a[M],b[M],c[M];
int getGCD(int a, int b)
{
	while(a && b)
	{
		if(a < b)
			b %= a;
		else
			a %= b;
	}
	return a + b;
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
	int t,n,q,x,ans,i,l,r;
	inp(t);
	while(t--)
	{
		inp(n);
		inp(q);
		a[0]=0;
		b[0]=0;
		for(i=1;i<=n;i++)
		{
			inp(x);
			a[i]=x;
			b[i]=getGCD(a[i],b[i-1]);
		}
		c[n]=a[n];
		for(i=n-1;i>=1;i--)
		{
			c[i]=getGCD(a[i],c[i+1]);
		}
		c[0]=0;
		c[n+1]=0;	
		while(q--)
		{
			inp(l);inp(r);
			ans=getGCD(b[l-1],c[r+1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}					
