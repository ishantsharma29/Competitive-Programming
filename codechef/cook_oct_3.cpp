#include<bits/stdc++.h>
using namespace std;

int c[1<<16],a[16];
int b[1<<16];
int main()
{
	int t,n,i;
	cin >> t;
	while(t--)
	{
		cin>>n;
		int m= 1<<n;
		for(i=0;i<m;i++)
			cin>>b[i];
		multiset<int> s;
		sort(b,b+m);
		int k=0,g=0,j,p;
		for(i=1;i<m;i++)
		{
			int expected=-1;
			if(!s.empty())
			{
				expected=*s.begin();	
			}
			if(expected==b[i])
			{
				s.erase(s.begin());
			}		
			else
			{
				a[k]=b[i];
				p=g;
				for(j=0;j<p;j++)
				{
					c[g]=c[j]+a[k];
					s.insert(c[g]);
					g++;
				}
				c[g]=a[k];
				k++;
				g++;
			}
		}
		for(i=0;i<k;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}					
