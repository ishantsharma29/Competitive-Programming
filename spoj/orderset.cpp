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

map< int,int > M;
int q,x,invalid;
char ch;
struct trie
{
	int cnt;
	int flag;
	struct trie* next[2];
	trie()
	{
		this->cnt=0;
		this->flag=0;
		this->next[0]=NULL;
		this->next[1]=NULL;
	}	
	trie( int val)
	{
		this->cnt=0;
		this->flag=0;
		this->next[0]=new trie();
		this->next[1]=new trie();
	}	
	void insert(int x);
	void deletex(int x);
	int count_smaller_than_x_POS(int x);
	int count_smaller_than_x_NEG(int x);
	int kth_smallest_elementPOS( int x);
	int kth_smallest_elementNEG( int x);
	void print( string s);
};

trie* root=new trie(0);

void trie::insert(int x)
{
	trie* temp=this;
	temp->cnt+=1;
	int y=x;
	if(x<0)
	{
		//if( !temp->next[1] )
		//temp->next[1]=new trie();
		temp=temp->next[1];
		x=-x;
	}	
	else
	{
		//if( !temp->next[0] )
		//	temp->next[0]=new trie();	
		temp=temp->next[0];
	}
	
	for(int i=30;i>=0;i--)
	{
		temp->cnt+=1;
		int p= (x&(1<<i))?1:0;
		if(!temp->next[p])
		{
			temp->next[p]=new trie();
		}
		temp=temp->next[p];
	}
	temp->cnt=y;
	temp->flag=1;
}

void trie::deletex(int x)
{
	trie* temp=this;
	temp->cnt-=1;
	if(x<0)
	{
		temp=temp->next[1];
		x=-x;
	}	
	else
	{	temp=temp->next[0];}
	
	for(int i=30;i>=0;i--)
	{
		temp->cnt-=1;
		int p= (x&(1<<i))?1:0;
		if(temp->next[p]->cnt==1 && temp->next[p]->flag==0 || temp->next[p]->flag==1 )
		{
			temp->next[p]=NULL;
			return;
		}
		temp=temp->next[p];
	}
}		


int trie::count_smaller_than_x_NEG( int x)
{
	trie* temp=this;
	int ans=0;
	//ans+=((temp->next[1])?temp->next[1]->cnt:0);
	if(!temp->next[1])
		return ans;
	else
		temp=temp->next[1];
	for(int i=30;i>=0;i--)
	{
		int p= (x&(1<<i))?1:0;
		if( p==0)
		{
			if( temp->next[1] )
			{
				if( temp->next[1]->flag==1)
					ans+=1;
				else
					ans+= temp->next[1]->cnt;
			}			
		}
		if(!temp->next[p])
			return ans;
		else
			temp=temp->next[p];
	}
	return ans;
}

int trie::count_smaller_than_x_POS( int x)
{
	trie* temp=this;
	int ans=0;
	ans+=((temp->next[1])?temp->next[1]->cnt:0);
	if(!temp->next[0])
		return ans;
	else
		temp=temp->next[0];
	for(int i=30;i>=0;i--)
	{
		int p= (x&(1<<i))?1:0;
		if( p==1)
		{
			if( temp->next[0] )
			{
				if( temp->next[0]->flag==1)
					ans+=1;
				else
					ans+= temp->next[0]->cnt;
			}			
		}
		if(!temp->next[p])
			return ans;
		else
			temp=temp->next[p];
	}
	return ans;
}			

int trie::kth_smallest_elementPOS(int x)
{
	trie* temp=this;
	if( temp->cnt< x && temp->flag==0)
	{
		invalid=1;
		return 0;
	}	
	//chk3 ( x, temp->cnt, temp->flag );
	while( temp->next[1 ] || temp->next[0])
	{
		//chk2(temp->next[1]->cnt, x);
		if(temp->next[0])
		{
			//chk2(temp->next[1]->cnt, x);
			if( temp->next[0]->flag==1 && x>1)
			{
				x=x-1;
				if(!temp->next[1])
				{
					invalid=1;
					return 0;
				}
				else
				{	
					temp=temp->next[1];
				}
			}				
			else if( temp->next[0]->cnt<x && temp->next[0]->flag==0)
			{
				//chk2(temp->next[1]->cnt, x);
				x=x-temp->next[0]->cnt ;
				if(!temp->next[1])
				{
					invalid=1;
					return 0;
				}
				else
				{	
					temp=temp->next[1];
				}
					
			}
			else
			{
				temp=temp->next[0];
			}
		}
		else
		{
			//chk2(temp->next[1]->cnt, x);
			temp=temp->next[1];	
		}
		//chk3 ( x, temp->cnt, temp->flag );
	}
	return temp->cnt;
	
}

int trie::kth_smallest_elementNEG(int x)
{
	trie* temp=this;
	//chk3 ( x, temp->cnt, temp->flag );
	while( temp->next[1 ] || temp->next[0])
	{
		if(temp->next[1])
		{
			if( temp->next[1]->flag==1 && x>1)
			{
				x=x-1;
				temp=temp->next[0];
			}				
			else if( temp->next[1]->cnt<x && temp->next[1]->flag==0)
			{
	//			chk2(temp->next[1]->cnt, x);
				x=x-temp->next[1]->cnt ;
				temp=temp->next[0];
					
			}
			else
			{
				temp=temp->next[1];
			}
		}
		else
		{
			temp=temp->next[0];	
		}
	//	chk3 ( x, temp->cnt, temp->flag );
	}
	return temp->cnt;
	
}				
void trie:: print( string s)
{
	trie* temp=this;
	for(int i=0;i<s.length();i++)
	{
		chk2(temp->cnt, temp->flag );
		temp=temp->next[ s[i] - '0' ];
	}
	chk2(temp->cnt, temp->flag );
}		

							
int main()
{
	int ans;
	inp(q);
	while(q--)
	{
		scanf("%c",&ch);
		if(ch=='I')
		{
			inp(x);
			if(M[x]==0)
			{
				//chk(x);
				M[x]=1;
				root->insert(x);
			}
		}
		else if(ch=='D')
		{
			inp(x);
			if(M[x]==1)
			{
				M[x]=0;
				root->deletex(x);
			}
		}
		else if( ch=='C')
		{
			inp(x);
			if(x<0)
				ans=root->count_smaller_than_x_NEG(-x);
			else
				ans=root->count_smaller_than_x_POS(x);	
			out(ans);
		}
		else if( ch=='K' )
		{
			inp(x);
			invalid=0;
	//		chk2( root->next[0]->cnt, root->next[1]->cnt );
			if( root->next[1]->cnt < x)
				ans=root->next[0]->kth_smallest_elementPOS(x - root->next[1]->cnt );
			else
				ans=root->next[1]->kth_smallest_elementNEG(x);
			if( invalid == 1)
				printf("invalid\n");//<<endl;
			else		
				out(ans);
		}				
	}
	//root->print("0");
	//cout<<endl;
	//root->print("1110");
	return 0;
}					
	
