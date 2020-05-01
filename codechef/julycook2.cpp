#include<bits/stdc++.h>

using namespace std;
long long int n,m,x,coun,a,p,i;
int main()
{
	cin>>n>>m;
	while(m--)
	{
		coun=0;
		cin>>x;
		if(x<n+2 || x>(3*n))
		{
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			if(x<=(2*n+1))
			{
			 a=(x-1);
			 coun=a-n;
			}
			else
			{
				a=(x-n);
				coun=(2*n)-a+1;
			}	 			
		}
		cout<<coun<<endl;
	}
	return 0;
}			
