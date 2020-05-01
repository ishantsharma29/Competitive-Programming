/*
	Created BY--
	Ishant Sharma
	ishantsharma29@gmail.com
*/	


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

int curr=0,a[500005];

#define cnting(v,l,r) (upper_bound(v.begin(),v.end(),r)- lower_bound(v.begin(), v.end(), l))
struct trie
{
	vector< int > v;
	trie* next[2];
	trie(int value)
	{
		this->next[0]=this->next[1]=NULL;
		this->v.pb(value);
	}
	void insert(int x) ;
	int maxmisexor( int x,int l,int r);
	void deletek(int x);
	int no_of_int(int x,int l,int r);
	int kthsmallest(int x,int l,int ,int);
	void print( string s);
};

trie* null;

void trie::insert(int x)
{
	trie* temp=this;
	for(int i=18;i>=0;i--)
	{
		int p=( (1<<i)&x )?1:0;
		if( ! temp->next[p] )
		{
			temp->next[p]=new trie(curr);
		}
		else
		{
			temp->next[p]->v.pb(curr);
		}	
		temp=temp->next[p];	
	}
}

void trie::print( string s)
{
	trie* copy=this;
	chk( copy->v.size() );	
	for(int i=0;i<s.length();i++)
	{
		chk2( s[i]-'0', copy->next[ s[i]-'0' ]->v.size() );
		copy=copy->next[ s[i]-'0' ];
	}
}

int checkin( vector<int> &v ,int l,int r)
{
	vector<int>::iterator it;
	it=lower_bound(v.begin(), v.end(), l);
	if( it!=v.end() && *it<=r)
		return 1;
	return 0;
}		
int trie:: maxmisexor(int x,int l,int r)
{
	trie* temp=this;
	for(int i=18;i>=0;i--)
	{
		if( temp->v.size() == 1) break;
		int p=((1<<i)&x)?1:0;
		if(p==1)
		{
			if( temp->next[0] && checkin( temp->next[0]->v, l, r ) )
				temp=temp->next[0];
			else
				temp=temp->next[1];
		}
		else
		{
			if(temp->next[1] && checkin( temp->next[1]->v, l, r ) )
				temp=temp->next[1];
			else
				temp=temp->next[0];
		}
	}
	return temp->v[0];
}			
void trie:: deletek( int x)
{
	trie* temp=this;
	for(int i=18;i>=0;i--)
	{
		int p=( ( 1<<i)&x)?1:0;
		temp->next[p]->v.pop_back();
		temp=temp->next[p];
	}
}

int trie::no_of_int( int x ,int l,int r)
{
	trie* temp= this;
	int ans=0;
	for(int i=18;i>=0 && (temp);i--)
	{
		int p=( ( 1<<i)&x)?1:0;
		if(p==1)
		{
			ans+=( (temp->next[0]) ?cnting(temp->next[0]->v,l,r):0 );
			temp=temp->next[1];
		}
		else
		{
			temp=temp->next[0];
		}
	}
	ans+=((temp)?cnting(temp->v,l,r):0 );
	return ans;
	
}				
int trie::kthsmallest(int x,int l,int r,int position)
{
	trie* temp=this;
	//chk4(x,l,r,position);
	while(position<=18)
	{
		int p= ( (temp->next[0]) ?cnting(temp->next[0]->v,l,r):0 );	
	//	chk(p);
		if(p<x)
			return temp->next[1]->kthsmallest(x-p,l,r,position+1);
		else
		{
			temp=temp->next[0];
			position++;
		}	
	}
	return temp->v[0];
}								
int main()
{
	int m,type,x,l,r;
	inp(m);
	while(m--)
	{
		inp(type);
		if(type==0)
		{
			inp(x);
			if(curr==0)
			{
				null=new trie(curr);
			}
			else
			{
				null->v.pb(curr);
			}
			null->insert(x);
			a[curr++]=x;
		}
		else if(type==1)
		{
			inp2(l,r);
			inp(x);
			l--;r--;
			out( a[null->maxmisexor(x,l,r)] );
		}	
		else if(type==2)
		{
			inp(x);
			for(int i=0;i<x;i++)
			{
				null->deletek( a[--curr] );
			}
		}
		else if( type==3 )
		{
			inp2(l,r); inp(x);
			l--;
			r--;
			out(null->no_of_int(x,l,r) );
		}
		else if(type==4)
		{
			inp2(l,r); inp(x);
			l--;
			r--;
			out( a[null->kthsmallest(x,l,r,0)] ) ;
		}		
					
	}
	//string s="110";
	//null->print(s);
	return 0;
}					
										
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
