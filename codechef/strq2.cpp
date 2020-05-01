#include<bits/stdc++.h>
using namespace std;
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

string se;
int q,l,r;
char s,re,e;
struct node
{
	int ccnt,hcnt,ecnt,fcnt;
	ll chans,ceans,cfans,hcans,heans,hfans,ecans,ehans,efans,fcans,fhans,feans;
}a[1000005];	
	
void initialise()
{
	a[0].ccnt=a[0].hcnt=a[0].ecnt=a[0].fcnt=a[0].chans=a[0].ceans=0;
	a[0].cfans=a[0].hcans=a[0].heans=a[0].hfans=a[0].ecans=a[0].ehans=a[0].efans=a[0].fcans=a[0].fhans=a[0].feans=0;
	a[1].ccnt=a[1].hcnt=a[1].ecnt=a[1].fcnt=a[1].chans=a[1].ceans=0;
	a[1].cfans=a[1].hcans=a[1].heans=a[1].hfans=a[1].ecans=a[1].ehans=a[1].efans=a[1].fcans=a[1].fhans=a[1].feans=0;
	if(se[0]=='c')
	a[1].ccnt=1;
	else if(se[0]=='h')
	a[1].hcnt=1;
	else if(se[0]=='e')
	a[1].ecnt=1;
	else 
	a[1].fcnt=1;

}		
void precompute(int l)
{
	initialise();
	for(int i=2;i<=l;i++)
	{
		a[i]=a[i-1];
		if(se[i-1]=='c')
		{
			a[i].ccnt+=1;
			a[i].hcans=a[i].hcans+a[i].hcnt;
			a[i].ecans=a[i].ecans+a[i].ecnt;
			a[i].fcans=a[i].fcans+a[i].fcnt;
		}
		else if(se[i-1]=='h')
		{
			a[i].hcnt+=1;
			a[i].chans=a[i].chans+a[i].ccnt;
			a[i].ehans=a[i].ehans+a[i].ecnt;
			a[i].fhans=a[i].fhans+a[i].fcnt;	
		}
		else if(se[i-1]=='e')
		{
			a[i].ecnt+=1;
			a[i].ceans=a[i].ceans+a[i].ccnt;
			a[i].heans=a[i].heans+a[i].hcnt;
			a[i].feans=a[i].feans+a[i].fcnt;	
		}
		else
		{
			a[i].fcnt+=1;
			a[i].cfans=a[i].cfans+a[i].ccnt;
			a[i].hfans=a[i].hfans+a[i].hcnt;
			a[i].efans=a[i].efans+a[i].ecnt;	
		}
	}
}		
int main()
{
	cin>>se;
	int len=se.length();
	precompute(len);
	inp(q);
	ll x,y,z,ans;
	while(q--)
	{
		scanf("%c",&s);
		scanf("%c",&re);
		scanf("%c",&e);
		inp(l);inp(r);
		if(s=='c' && e=='h')
		{
			x=a[r].chans-a[l-1].chans;//chk(x);
			y=a[r].hcnt-a[l-1].hcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ccnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='c' && e=='e')
		{
			x=a[r].ceans-a[l-1].ceans;//chk(x);
			y=a[r].ecnt-a[l-1].ecnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ccnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='c' && e=='f')
		{
			x=a[r].cfans-a[l-1].cfans;//chk(x);
			y=a[r].fcnt-a[l-1].fcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ccnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='h' && e=='c')
		{
			x=a[r].hcans-a[l-1].hcans;//chk(x);
			y=a[r].ccnt-a[l-1].ccnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].hcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='h' && e=='e')
		{
			x=a[r].heans-a[l-1].heans;//chk(x);
			y=a[r].ecnt-a[l-1].ecnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].hcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='h' && e=='f')
		{
			x=a[r].hfans-a[l-1].hfans;//chk(x);
			y=a[r].fcnt-a[l-1].fcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].hcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='e' && e=='c')
		{
			x=a[r].ecans-a[l-1].ecans;//chk(x);
			y=a[r].ccnt-a[l-1].ccnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ecnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='e' && e=='h')
		{
			x=a[r].ehans-a[l-1].ehans;//chk(x);
			y=a[r].hcnt-a[l-1].hcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ecnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='e' && e=='f')
		{
			x=a[r].efans-a[l-1].efans;//chk(x);
			y=a[r].fcnt-a[l-1].fcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].ecnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='f' && e=='c')
		{
			x=a[r].fcans-a[l-1].fcans;//chk(x);
			y=a[r].ccnt-a[l-1].ccnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].fcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else if(s=='f' && e=='h')
		{
			x=a[r].fhans-a[l-1].fhans;//chk(x);
			y=a[r].hcnt-a[l-1].hcnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].fcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		else
		{
			x=a[r].feans-a[l-1].feans;//chk(x);
			y=a[r].ecnt-a[l-1].ecnt;//chk3(y,a[r].hcnt,a[l-1].hcnt);
			z=a[l-1].fcnt;//chk3(z,a[r].ccnt,a[l-1].ccnt);
			ans=x-y*z;
		}
		
		outl(ans);
	}		
	return 0;
}	

