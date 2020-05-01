#include<bits/stdc++.h>
using namespace std;
//typedef long long int ll;
 
int dp[5010];string s;
int n;

int possible( int n1,int n2)// a, char b)
{
	return (n1*10+n2) <27 ? 1:0 ;
}
 
int fun(int idx)
{
//cout<<" idx "<<idx<<endl;
	if (s[idx]=='0')
		return 0;
	if( idx>=n)	
	return 1;
	if(dp[idx]!=-1)
	return dp[idx];
	int ans=fun(idx+1);
	if( (idx+1)<n && possible(int(s[idx])-48,int(s[idx+1])-48 ) )
	ans+=fun(idx+2);
	return dp[idx]=ans;
}
int calculate( string s)
{
	n=s.size();
	return fun(0);
}
 
int main()
{
 
	cin>>s;
	while(s[0]!='0')
	{	
	//int size=s.size();
		memset(dp,-1,sizeof(dp) );
	//cout<<dp[0]<<endl;
		int c=calculate(s);
	//cout<<c<<endl;
		printf("%d\n",c);
		cin>>s;

	}
return 0;
}
