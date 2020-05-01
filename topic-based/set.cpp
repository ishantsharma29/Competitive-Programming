#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,x,i;
	
	int e=abs(-2.330);
	float f=fabs(-2.330);
	cout<<e<<" "<<f;
	set< int > s;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		s.insert(x);
	}	
	set<int> ::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	return 0;
}		
