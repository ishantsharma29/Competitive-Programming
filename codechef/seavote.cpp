#include<bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked

inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}

int main()
{
	int t,n;
	inp(t);
	while(t--)
	{
		inp(n);
		int x,s=0,a=0,b[n+1],i;
		for(i=1;i<=n;i++)
		{
			inp(x);
			if(x==0)
			a++;
			b[i]=x;
			s+=x;
		}
		//cout<<s<<endl<<" "<< a<< " "<<n<<endl;
		if(s>=100 && s<(100+n-a) )
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}				
			
