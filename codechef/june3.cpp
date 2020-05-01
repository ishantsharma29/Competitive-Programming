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
#define out(n) printf("%d\n",n);
#define M 100010

int t,c1,c2,c3,ans;


int main()
{
	inp(t);
	while(t--)
	{
		c1=0,c2=0,c3=0,ans=0;
		string s1,s2;
		cin>>s1;
		cin>>s2;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]!=s2[i])
			{
				if( s1[i]=='1')
					c1++;
				else
					c2++;
			}
			if(s1[i]=='0' && s2[i]=='0')
				c3++;
		}
		//cout<<c1<<" "<<c2<<" "<<c3<<endl;
		if(c2>=c1)
		{
			ans= c1;
			int x=c2-c1;
			//ans+=(x/2);
			int y=s1.length()-c1-c2-c3;
			//cout<<"NO of 1-1"<<y<<endl;
			if( (y+c1)>=1)
			{
				ans+=(c2-c1);
				printf("Lucky Chef\n");
				out(ans);
			}
			else
			{
				printf("Unlucky Chef\n");
			}
					
		}
		else
		{
			ans=c2;
			int x=c1-c2;
			if( (c2+c3)>=1)
			{
				ans+=x;
				printf("Lucky Chef\n");
				out(ans);
			}
			else
			{
				printf("Unlucky Chef\n");
			}
		}			
		
	}
	return 0;
}			
							
