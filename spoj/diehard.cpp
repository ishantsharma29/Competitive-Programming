#include<bits/stdc++.h>
using namespace std;
//typedef long long int ll;
 
int dp[3][1010][1010];
int h,a;

int fun(int flag,int h,int a)
{
	if( h<=0 || a<=0 )
		return 0;
	if(dp[flag][h][a]!=-1)
		return dp[flag][h][a];
	int ans=0;
	if(flag==0)
	{
		if( h-5 >0 && a-10 > 0 )
		ans=fun(1,h-5,a-10);
		if( h-20>0 && a+5>0 )
		ans=max(ans,fun(2,h-20,a+5) );
	}
	else if(flag==1)
	{	
		ans=fun(0,h+3,a+2);
		if( h-20>0 && a+5>0 )
		ans=max(ans,fun(2,h-20,a+5) );
	}
	else
	{
		ans=fun(0,h+3,a+2);
		if( h-5 >0 && a-10 > 0 )
		ans=max(ans,fun(1,h-5,a-10));
	}
	return ( dp[flag][h][a]=ans+1);	
					
}
 
int main()
{
 	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&a);
		memset(dp,-1,sizeof(dp) );
		int cnt=0;
	//	cout<<dp[1][0][1]<<endl;
		int res=max( max(fun(0,h+3,a+2),fun(1,h-5,a-10) ) ,fun(2,h-20,a+5) );
		printf("%d\n",res);
	}
return 0;
}
