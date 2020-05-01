#include<bits/stdc++.h>
using namespace std;
#define M 1000000009


struct node
		{
			char ch;
			int idx;
		};

bool comp(node x,node y)
{
	return x.idx<y.idx;
}
	
int main()
{	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,i,previ,diffi,index;
		char prev,che,e;
		long long int cnt=1;
		scanf("%d %d",&n,&m);
		scanf("%c",&e);
		struct node a[m];	
		for(i=0;i<m;i++)
		{
			scanf("%c",&che);
			scanf("%c",&e);
			scanf("%d",&index);
			scanf("%c",&e);
			a[i].ch=che;
			a[i].idx=index;
			
			//cin>>a[i].ch>>a[i].idx;
		}
		//for(i=0;i<m;i++)
		//{
		//	cout<<a[i].ch<<" "<<a[i].idx<<endl;
		//}	
		sort(a,a+m,comp);	
		prev=a[0].ch;
		previ=a[0].idx;
		for(i=1;i<m;i++)
		{
			//cin>>ch>>idx;
			if(a[i].ch==prev){}
			else
			{
				diffi=a[i].idx-previ;
				cnt=(cnt*diffi)%M;
			}
			prev=a[i].ch;
			previ=a[i].idx;
		}
			
		cout<<cnt<<endl;
	}			
	return 0;
}	
