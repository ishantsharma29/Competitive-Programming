#include<bits/stdc++.h>
using namespace std;
#define M 401

bool operator < (pair<int,int> p, pair<int,int> q)
{
	return p.first>q.first;
}	
int main()
{
	int a[M],b[M],t,n,m,i,j,pos;
	cin>>t;
	while(t--)
	{
		int c[M]={0},present[M]={0};
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>a[i];
			c[a[i]]++;
		}
		priority_queue< pair<int,int> > pq;
		b[0]=a[0];
		c[a[0]]--;
		pq.push(make_pair(0,c[a[0]]));
		present[a[0]]=1;
		int count=1;
		int idx=1;
		for(i=1;i<n && i<m;i++)
		{
			if(present[a[i]]==1)continue;
			else
			{
				b[idx]=a[i];
				present[a[i]]=1;
				count++;
				c[a[i]]--;
				pq.push(make_pair(idx,c[a[i]]));
				idx++;
			}
		}		
		
		cout<<"count "<<count<<endl;
		for(i=n;i<m;i+=n)
		{
			for(j=i;j<i+n && j<m ;j++)
			{
				if(present[a[j]]==1)continue;
				else
				{
					if(idx<n)
					{
						b[idx]=a[j];
						present[a[j]]=1;
						c[a[j]]--;
						pq.push(make_pair(idx,c[a[j]]));
						idx++;
						count++;
						cout<<" count in if"<<" "<<count<<endl;
					}
					else
					{
						pair<int,int> ap;
						ap=pq.top();
						pq.pop();
						cout<<"Element popped "<<b[ap.first]<<endl;
						present[b[ap.first]]=0;
						b[ap.first]=a[j];
						present[a[j]]=1;
						c[a[j]]--;
						count++;
						pq.push(make_pair(ap.first,c[a[j]]));
						cout<<" count in else"<<" "<<count<<endl;
					}	
							
				}
			}
		}		
		cout<<count<<endl;
	}
	return 0;
}						
						
					
					
				
