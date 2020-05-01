#include<bits/stdc++.h>
using namespace std;

#define getcx getchar_unlocked

inline void inp(int &n)
{
	int sign=1; n=0;int ch=getcx();
	while( ch < '0' || ch >'9' ) { if(ch=='-') sign=-1;ch=getcx();}
	while( ch >= '0'&& ch <= '9' ) 
	n=(n<<3)+(n<<1)+(ch-'0'),ch=getcx();
	n=n*sign;
}	
	
#define rep(i,n) for(int i=0;i<n;i++)	
#define inp2(n,m) inp(n), inp(m)

#define M 100010
int q,n,m,a[M],mini=INT_MAX,maxi=INT_MIN;

int main()
{
		//cout<<"hello"<<endl;
		inp2(n,m);
		//cout<<n<<"  "<<m<<endl;
		rep(i,n)
		{
			inp(a[i]);
			mini=min(mini,a[i]);
			maxi=max(maxi,a[i]);
		}
		rep(i,m)
		{
			inp(q);
			if(q>=mini && q<=maxi)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");			
			}
		}
	return 0;
}	
			
			
			
	
