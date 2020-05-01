
#include<bits/stdc++.h>
using namespace std;

#define chk(a) coutl << endl << #a << " : " << a << endl
#define chk2(a,b) coutl << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) coutl << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) coutl << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked
typedef long long ll ;

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
#define outf(n) printf("%.1f\n",n);
#define inpl(n) scanf("%lld",&n);

int main()
{
	ll t,n,i,x,y;
	float res;
	inp(t);
	while(t--)
	{
		inp(n);
		priority_queue< ll, vector< ll >  > Mxhp;
		priority_queue< ll , vector< ll > , greater< ll >  > Mnhp;
		rep(i,n)
		{
			if(i==0)
			{
				inp(x);
				outl(x);
			}
			else if(i==1)
			{
				inp(y);
				if( (x+y)%2==0)
				{	outl( (x+y)/2 );}
				else
				{
				res=(float) ( x+y )/2;
				outf(res);
				}
				
				if(x>y)
				{
					Mnhp.push(x);
					Mxhp.push(y);
				}
				else
				{
					Mnhp.push(y);
					Mxhp.push(x);
				}
			}
			else
			{
				if(i%2==0)
				{
					inp(x);
					if( x>=Mxhp.top() && x<= Mnhp.top() )
					{
						outl(x);
					}
					else if( x<Mxhp.top() )
					{
						outl( Mxhp.top() );	
					}
					else
					{
						outl( Mnhp.top() );
					}
				}
				else
				{
					inp(y);				
					if( x< Mxhp.top() && y< Mxhp.top() )
					{
						//cout<<"--1"<<endl;
						Mnhp.push( Mxhp.top() );
						Mxhp.pop();
						Mxhp.push(x);
						Mxhp.push(y);
						if( (Mxhp.top() + Mnhp.top() ) %2==0)
						{	outl( (Mxhp.top()+Mnhp.top() )/2 );}
						else
						{
						res=(float) (Mxhp.top()+Mnhp.top() )/2;
						outf(res);
						}
					}
					else if( x> Mnhp.top() && y> Mnhp.top() )
					{
						//cout<<"--2"<<endl;
						Mxhp.push( Mnhp.top() );
						Mnhp.pop();
						Mnhp.push(x);
						Mnhp.push(y);
						if( (Mxhp.top() + Mnhp.top() ) %2==0)
						{	outl( (Mxhp.top()+Mnhp.top() )/2 );}
						else
						{
						res=(float) (Mxhp.top()+Mnhp.top() )/2;
						outf(res);
						}		
					}
					else
					{
						//cout<<"--3"<<endl;
						if(x<y)
						{
							Mxhp.push(x);
							Mnhp.push(y);
						}
						else
						{
							Mxhp.push(y);
							Mnhp.push(x);
						}
						if( (Mxhp.top() + Mnhp.top() ) %2==0)
						{	outl( (Mxhp.top()+Mnhp.top() )/2 );}
						else
						{
						res=(float) (Mxhp.top()+Mnhp.top() )/2;
						outf(res);
						}
					}
								
				}
			}
		}
	}
	return 0;
}					
	
	
	
	

