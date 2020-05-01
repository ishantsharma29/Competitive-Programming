#include<bits/stdc++.h>
using namespace std;

#define M 1000010
#define getcx getchar_unlocked
inline void inp( int &n)
{
	int sign=1;n=0;int ch;ch=getcx();
	while(ch<'0'|| ch>'9') { if(ch=='-') sign=-1; ch=getcx();}
	while( ch>='0' && ch<='9' ) 
	n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
	n=n*sign;
}	
int a[M];

#define	rep(i,n) for(int i=1;i<n;i++)
int main()
{
	int t,n,x;
	inp(t);
	while(t--)
	{
		inp(n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			inp(x);
			a[i]=x;
		}	
		int cnt=0,prev=0;
		rep(i,n)
		{
			if(a[i]!=a[i-1])
			{
				if(prev==0)
				{
					cnt+=2;
					prev=1;
				}	
				else
					cnt+=1;
			}
			else
				prev=0;
		}
		printf("%d\n",cnt);
	}
					
			
	return 0;
}		
