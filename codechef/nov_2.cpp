#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,x,k;
	cin>>t;
	while(t--)
	{
		cin>>x>>k;
		long long int level=log2(k);
		//cout<<level<<endl;
		long long int no_of_term=1<<level;
		long long int index=k-(1<<level);
		//cout<<index<<endl;
		long double division=(long double)x/no_of_term;
		//cout<<division<<endl;
		long double ans=division*index+division/2;
		//long double ans=(long double)(division*(2*index+1))/2;
		
		cout<< setprecision(100)<<ans<<endl;
	}
	return 0;
}		
