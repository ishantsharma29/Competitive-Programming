#include<bits/stdc++.h>
using namespace std;
//http://discuss.codechef.com/questions/60006/tasumobc-editorial?page=1#60109
//See Setter's Solution For DIGIT DP
//This solution is based on LAST approach
typedef long long int ll;

ll t,n,r,m,sum,one,two;

int main()
{
	
	scanf("%lld",&t);
	while(t--)
	{
		ll twocnt=0,onecnt=0,tmp1,tmp2;
		sum=0;
		scanf("%lld",&n);
		m=n;
		while(m)
		{
			r=m%3;
			if(r==1)
				onecnt++;
			else if(r==2)
				twocnt++;
			m=m/3;
		}
		tmp1=pow(2,onecnt);
		//cout<<tmp1<<" ";
		tmp2=pow(3,twocnt+1);
		tmp2=tmp2-1;
		sum=tmp1*tmp2;
		sum=sum/2;	
		sum=sum%1000000007;
		cout<<sum<<endl;	
	}
	return 0;
}			
