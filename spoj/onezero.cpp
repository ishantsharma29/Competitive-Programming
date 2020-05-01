#include<bits/stdc++.h>
using namespace std;
	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,y1,y2;
		scanf("%d",&n);
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}	
		queue< pair<string,int> > q;
		string s="1";
		q.push(make_pair(s,1));
		while(!q.empty())
		{
			pair< string,int > ap=q.front();
			q.pop();
			//cout<<ap.first;
			s=ap.first+"0";
			y1=(ap.second*10)%n;
			//cout<<y1<<endl;
			if(y1==0)
			{
				cout<<s<<endl;
				break;
			}	
			q.push(make_pair(s,y1));
			s=ap.first+"1";
			y2=(y1+1)%n;
			//cout<<y2<<endl;
			if(y2==0)
			{
				cout<<s<<endl;
				break;
			}
			q.push(make_pair(s,y2));
		}
	}
	return 0;
}			
	
