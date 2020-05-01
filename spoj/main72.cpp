#include<bits/stdc++.h>
using namespace std;
int a[100001][101],b[101];
long long int t,res,sum,i,n,j;
int main()
{
	cin>>t;
	while(t--)
	{
		res=0;
		sum=0;
		cin>>n;
		//int b[n+1];
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			sum+=b[i];
		}	
		
		
		for(i=0;i<=n;i++)
			a[0][i]=1;
		for(i=1;i<=sum;i++)
			a[i][0]=0;
		for(i=1;i<=sum;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=a[i][j-1];
				if(i>=b[j-1])
					a[i][j] = (a[i][j] || a[i - b[j-1]][j-1]);
			}
		}
		for(i=1;i<=sum;i++)
		{
			if(a[i][n]==1)
				res=res+i;
		}
		cout<<res<<endl;
	}
	return 0;
}									
	
