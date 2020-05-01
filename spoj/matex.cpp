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
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);
#define mod 1000000007
typedef long long int ll;

typedef vector< int > row;
typedef vector< row > matrix;
const int nn=18;	

void print ( matrix & E)
{
	for(int i=0;i<nn;i++)
	{
		for(int j=0;j<nn;j++)
		{
			cout<<E[i][j]<<" ";
		}
		cout<<endl;
	}
}

void clear (matrix & A)
{
  for (int i = 0; i < A.size (); i++)
    for (int j = 0; j < A[i].size (); j++)
      A[i][j] = 0;
}


matrix multi( matrix & A, matrix & B)
{
	matrix D=A;
	clear(D);
	for(int i=0;i<D.size();i++)
	{
		for( int j=0; j< D[i].size() ; j++ )
		{
			long long int sum=0;
			for( int k=0;k< A[i].size() ;k++)
			{
				sum+= ( ( (long long) A[i][k]) *( (long long) B[k][j]) % mod ) ;
			}
			D[i][j]=sum % mod;
		}
	}
	return D;
}
				
matrix power ( matrix & A, ll p )
{
	if( p==0 )
	{
		matrix C=A;
		clear(C);
		for(int i=0;i<nn;i++)
		{
			for( int j=0;j<nn;j++)
			{
				if(i==j)
				{
					C[i][j]=1;
				}
			}
		}
		return C;
	}
	matrix C=power( A,p/2);
	//print(C);
	C=multi( C,C);
	//print(C);
	if( p&1 )
	C=multi( C,A);
	//print(C);
	return C;
}
							
int main()
{
	int t,w,i,j,s,d,x;
	ll n;
	inp(w);
	
	matrix M ( nn, row( nn,0) );
	for(i=0;i<w;i++)
	{
		for(j=0;j<w;j++)
		{
			inp(x);
			M[i][j]=x;
		}
	}
	//print( M);	
	matrix Z=M;
	matrix L=M;
	for(int i=0;i<nn;i++)
	{
		for(int j=0;j<nn;j++)
		{
			if(i==j)
			L[i][j]=1;
			else
			L[i][j]=0;
		}
	}		
	ll prev=0,v;
	int b=140;		
	while(b--)
	{
		inp(s); inp(d);scanf("%lld",&n);
		if(n>prev)
		{
			v=n-prev;
			prev=n;
			M=power( M , v);
			M=multi(M,L);
			out ( M[s-1][d-1] );
		}
		else
		{
			
			prev=n;
			v=n;
			M=power( M , v);
		
			out ( M[s-1][d-1] );
		}	
		
		
		L=M;
		M=Z;
	}
	return 0;
}		
