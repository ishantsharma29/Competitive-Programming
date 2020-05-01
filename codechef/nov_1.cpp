#include<bits/stdc++.h>
using namespace std;
#define M 100005
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i;
		string s;
		cin>>s;
		int l=s.length();
		int b[30]={0};
		int c=0;
		for(i=0;i<l;i++)
		{
			if(b[(int)s[i]-97]==0)
			{
				b[(int)s[i]-97]=1;
				c++;
			}
		}
						
		cout<<c<<endl;
		
	}
	return 0;
}				
					
