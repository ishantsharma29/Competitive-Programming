#include<bits/stdc++.h>
using namespace std;
#define M 100007
struct way
{
	int no;
	int idx;
};	

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		int a[M];
		vector<way> v[3];
		long long int cost=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>=0)
			{
				v[0].push_back((way){a[i],i});
			}
			else
			{
				v[1].push_back((way){abs(a[i]),i});
			}
		}
		/*for(i=0;i<v[0].size();i++)
		{
			cout<<"Node "<<v[0][i].no<<" Index "<<v[0][i].idx<<endl;
		}*/			
		
		int j=0,k=0;
		while(j<v[0].size() && k<v[1].size())
		{
			way x=v[0][j];
			way y=v[1][k];
			if(x.no<y.no)
			{
				v[1][k].no-=v[0][j].no;
				cost=cost+(abs(v[1][k].idx-v[0][j].idx))*v[0][j].no;
				j++;
		//		cout<<"Cost is inside if"<<cost<<endl;
			}
			else
			{
				v[0][j].no-=v[1][k].no;
				cost=cost+(abs(v[1][k].idx-v[0][j].idx))*v[1][k].no;
				k++;		
		//		cout<<"Cost is inside else"<<cost<<endl;
			}
		}
		cout<<cost<<endl;	
	}
	return 0;
}			
		
			
