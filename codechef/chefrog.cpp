#include<stdio.h>
#include<iostream>
#define M 100007
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
	int n,k,p,a[M],i,value=0,hash[M],e,f,prev;
	vector< pair<int,int> > v;
	cin>>n>>k>>p;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(make_pair(a[i],i));
	}
		
	sort(v.begin(),v.end());
	vector< pair<int,int> > ::iterator it;
	//for(it=v.begin();it!=v.end();it++)
	//{
	//	cout<<it->first<<" "<<it->second<<"\n";
	//}
	//vector< pair<int,int> > ::iterator it;
	it=v.begin();
	hash[it->second]=value;
	prev=it->first;
	for(it=v.begin()+1;it!=v.end();it++)
	{
		if(it->first<=prev+k)
			hash[it->second]=value;
		else
			hash[it->second]=++value;	
		prev=it->first;
	}		
	while(p--)
	{
		cin>>e>>f;
		if(hash[e]==hash[f])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}		
	return 0;
}		
