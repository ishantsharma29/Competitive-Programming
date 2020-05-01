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

char st[25005][22];
int curr=0,notaprefix=-1;
map< string,int > mi;

struct trie
{
	//int flag;
	//int index;
	set< string > sp;
	trie* next[26];
	
	trie()
	{
		for(int i=0;i<26;i++)
			this->next[i]=NULL;
	}
	void insert(string s);
	void search(string s);
	void print (string s);
	//void printing();
};

trie* root=new trie();

void trie::insert( string s)
{
	//cout<<s<<endl;
	trie* temp=this;
	for(int i=0;i<s.length();i++)
	{
		temp->sp.insert(s);
		if( temp->next[ s[i]-'a' ] == NULL )
		{
			temp->next[ s[i]-'a' ] = new trie();
		}
					
		temp=temp->next[ s[i]-'a' ];
	}
	//temp->index=curr;
	//temp->flag=1;
	//chk2(temp->index,temp->flag);	
}			

void trie:: search( string s)
{
	trie* temp=this;
	for(int i=0;i<s.length();i++)
	{
		
		if(temp->next[ s[i]-'a' ] ==NULL )
		{
			printf("No match.\n");//<<endl;
			return ;
		}
		temp=temp->next[ s[i] - 'a' ];	
	}
	if(temp->sp.size()==0)
	{
		printf("No match.\n");//<<endl;
			return ;
	}
	set<string> ::iterator it1;
	for(it1=temp->sp.begin();it1!=temp->sp.end();it1++)
		cout<<*it1<<endl;
			
}
			

/*void trie:: print( string s)
{
	cout<<endl<<endl;
	trie* temp=this;
	chk3(this->index,this->flag,this->v.size() );
	for(int i=0;i<s.length();i++)
	{
		temp=temp->next[ s[i]-'a' ];
		chk3(temp->index,temp->flag,temp->v.size() );
	}
}*/
int main()
{
	int n,i,k;
	char s1[22];
	inp(n);
	REP(i,0,n-1)
	{
		//cin>>st[i];
		ins(st[i]);
		if(mi[st[i]]==0)
		{
			root->insert(st[i]);
			mi[ st[i] ]=1;
		}
				
		curr++;
	//	root->print(s[i]);
	}
	inp(k);
	REP(i,0,k-1)
	{
		//cin>>s1;
		ins(s1);
		//cout<<"Case #"<<i+1<<":"<<endl;
		printf("Case #%d:\n",i+1);	
		//notaprefix=-1;
		root->search(s1);
 	}
 	return 0;
}	

















