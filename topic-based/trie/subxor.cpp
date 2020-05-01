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


struct trie
{
	int cnt;
	trie* next[2];
	trie()
	{
		this->cnt=0;
		this->next[0]=this->next[1]=NULL;
	}
	void insert(int x);
	ll query(int pre,int k);
	void print(string s);

};
void trie::insert(int x)
{
	trie* temp=this;
	for(int i=18;i>=0;i--)
	{
		int p=( (1<<i)&x)?1:0;
		temp->cnt++;
		if(temp->next[p]==NULL)
		{
			temp->next[p]=new trie();
		}
		temp=temp->next[p];
	}
}				

ll trie::query(int pre, int k)
{
	trie* temp=this;
	ll lans=0;
	for(int i=18;i>=0 && (temp);i--)
	{
		int p=( (1<<i)&pre)?1:0;
		int q=( (1<<i)&k)?1:0;
		if(p==1 && q==0)
		{
			if(temp->next[1]==NULL)
				return lans;
			temp=temp->next[1];
		}
		else if(p==0 && q==1)
		{
			lans=lans+((temp->next[0])?temp->next[0]->cnt:0);
			temp=temp->next[1];
		}
		else if( p==1 && q==1 )
		{
			lans+=((temp->next[1])?temp->next[1]->cnt:0);
			temp=temp->next[0];
		}
		else
		{
			if(temp->next[0]==NULL)
				return lans;
			temp=temp->next[0];
		}
		//chk2(i,lans);
	}
	return lans;
}			

/*void trie::print(string s)
{
	trie* temp=this;
	chk2( temp->cnt , temp->v.size() );
	for(int i=0;i<s.length();i++)
	{
		if( temp->next[ s[i]-'0' ] !=NULL )
			temp=temp->next[ s[i]-'0' ];
		chk2(temp->cnt, temp->v.size() );
	}
}	*/		
				
int main()
{
	int t,n,k,i,x;
	string s;
	inp(t);
	while(t--)
	{
		trie* null;
		int pre=0;ll ans=0;
		inp2(n,k);
		REP(i,0,n-1)
		{
			inp(x);
			if(i==0)
			{
				if(x<k)
				ans=1;
				pre=pre^x;
				null=new trie();
				null->insert(pre);
				/*
				null->insert(5);
				s="101";
				null->print(s);
				break;*/
			}
			else
			{
				pre=pre^x;
		//		chk(pre);
				ans+= null->query(pre,k);
		//		chk2(i,ans);
				if(pre<k)
				ans++;
				null->insert(pre);
			}
			
		}
		outl(ans);
	}
	return 0;
}					
			
		
