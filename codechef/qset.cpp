#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define M 100005
int a[M];
int main()
{
	int n,m,i,type,x,y;
	cin>>n>>m;
	string s;
	cin>>s;
	for(i=0;i<s.length();i++)
		a[i+1]=(int)s[i]-'0';
	while(m--)
	{
		cin>>type>>x>>y;
		if(type==1)
		{
			a[x]=y;
		}
		else
		{
			int B[3]={0};
			B[0]++;
			ll s=0,ans=0;
			for(i=x;i<=y;i++)
			{
				s=s+a[i];
				s=s%3;
				B[s]++;
			}
			for(i=0;i<3;i++)
			{
				ans+=(B[i]*(B[i]-1))/2;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}							
