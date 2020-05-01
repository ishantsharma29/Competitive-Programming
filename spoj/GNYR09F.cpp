#include<bits/stdc++.h>
using namespace std;
//typedef long long int ll;
 
int dp[1010][2][1010];
int n,k,p;

int fun(int idx,int prev,int k)
{
	//cout<<idx<<endl;
	if(idx==n)
	return ( (k==0) ? 1:0 );
	if(dp[idx][prev][k]!=-1 )
	return dp[idx][prev][k];
	int ans=0;
	if(prev)
	{
		ans=fun(idx+1,0,k);
		if(k)
		ans+=fun(idx+1,1,k-1);
	}
	else
	{
		ans=fun(idx+1,0,k)+fun(idx+1,1,k);
	}
	//cout<<idx<<" "<<ans<<" "<<endl;
	return (dp[idx][prev][k]=ans);		
}
 
int main()
{
 	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&p,&n,&k);
		memset(dp,-1,sizeof(dp) );
	//	cout<<dp[1][0][1]<<endl;
		int res=fun(0,0,k);
		printf("%d %d\n",p,res);
	}
return 0;
}
