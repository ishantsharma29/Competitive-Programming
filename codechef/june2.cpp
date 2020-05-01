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

int n,t;

int main()
{

	int t;
	inp(t);
	while(t--)
	{
		inp(n);
		if(n%6==0)
			printf("Misha\n");
		else
			printf("Chef\n");
	}
	return 0;
}				
