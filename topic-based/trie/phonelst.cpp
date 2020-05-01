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


struct trie
{
	int flag;
	trie* next[10];
	trie()
	{
		this->flag=0;
		for(int i=0;i<=9;i++)
			this->next[i]=NULL;
	}
	int insert(string s);
	void print(string s);
};

int trie:: insert( string s)
{
	trie* temp=this;
	int newnode=0;
	for(int i=0;i<s.length();i++)
	{
		if(temp->next[ s[i]-'0' ] == NULL )
		{
			temp->next[ s[i] - '0' ] =new trie();
			newnode++;
		}
		if(temp->flag==1)
		{
			return 0;
		}	
		temp=temp->next[ s[i]-'0' ];
	}
	if(newnode==0)
		return 0;
	temp->flag=1;	
	return 1;
}			

int main()
{
	int t,n,i,ans;
	inp(t);
	while(t--)
	{
		inp(n);
		trie* root;
		string s;
		int chk=0;
		REP(i,0,n-1)
		{
			cin>>s;	
			if(i==0)
			{
				root=new trie();
				ans=root->insert(s);
			}
			else
			{
				ans=root->insert(s);
			}
			if(!ans) chk=1;
			
		}
		if(!chk)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		
	}
	return 0;
}					











			
