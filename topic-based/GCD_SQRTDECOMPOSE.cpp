#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define getcx getchar_unlocked

/*void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}*/
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}

int a[M],b[M];
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

int gcdRQ(int l, int r,int len)
{
	int cur_gcd = a[l++];
	for(int i = l; i <= r;)
	{
		if (i % len == 0 && i + len - 1 <= r) 
		{
			cur_gcd = getGCD(cur_gcd, b[i / len]);
			i += len; 
		}
		else 
			cur_gcd = getGCD(cur_gcd, a[i++]);
	}
	return cur_gcd;		
}
/*void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}*/
int main()
{
	int t;
	//scanf("%d",&t);
	inp(t);
	while(t--)
	{
		int n,q,x;
		//scanf("%d %d",&n,&q);
		inp(n);
		inp(q);
		int i,k;
		for(i=0;i<n;i++)
		{
			//scanf("%d",&x);
			inp(x);
			a[i]=x;
		}
		int magic=sqrt(n);
		
		int current;
		for(i=0;i<n;i++)
		{
			k=0;
			current=0;			
			while(k<magic)
			{
				current=getGCD(current,a[i+k]);
				k++;
			}
			b[i/magic]=current;
			i=i+magic-1;
		}		
		/*for(i=0;i<;i++)
			cout<<b[i]<<" ";
		cout<<endl;*/
		int l,r,parta,partb,ans;
		while(q--)
		{
			//scanf("%d %d",&l,&r);
			//scanint(l);
			//scanint(r);
			inp(l);inp(r);
			l--;
			r--;
			if(l>0)
			{
				parta=gcdRQ(0,l-1,magic);
			
				if(r<n-1)
				{	
				partb=gcdRQ(r+1,n-1,magic);
					
				ans=getGCD(parta,partb);
				}
				else
				{
					ans=parta;
				}
			}
			else if(r<n-1)
			{
				ans=gcdRQ(r+1,n-1,magic);
			}
			printf("%d\n",ans);
		}			
	}
	return 0;
}					
					
