#include<bits/stdc++.h>
using namespace std;
#define M 105
#define N 1000000007
int n,i,j,k,level,a[M],dp[M][M];

int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(level=0;level<n;level++)
	{
		for(i=1;i<=n;i++)
		{
			j=i+level;
			if(j>n)
				continue;
			if(j==i)
			{
				dp[i][j]=0;
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				for(k=i;k<j;k++)
				{
					if(a[j]>0 && a[k]==-a[j])
					{
						if(k==i)
						{
							dp[i][j]=(dp[i][j]+1+dp[k+1][j-1])%N;
						}
						else
						{
							dp[i][j]=(dp[i][j]+((1+dp[k+1][j-1])*(1+dp[i][k-1]))%N)%N;
						}
					}
				}
			}
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/		
	cout<<dp[1][n]+1<<endl;
	return 0;
}											
