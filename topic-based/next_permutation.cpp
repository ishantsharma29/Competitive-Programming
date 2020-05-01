#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int a[M];//b[M];

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		if(next_permutation(s.begin(),s.end())	)
			cout<<s<<endl;
		else
			printf("-1");
		while(next_permutation(s.begin(),s.end()) )	
		{
			cout<<s<<endl;
		}	
		
		printf("\n");
	}
		
	return 0;
}	
// Similarly can be used in array next_permutation(a,a +n) like in JNEXT question on SPOJ

http://www.cplusplus.com/reference/algorithm/next_permutation/ 											
