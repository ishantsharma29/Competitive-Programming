#include<bits/stdc++.h>
using namespace std;
#define M 10005

int prime[M],i,j;
/*int convert(string s4)
{
	int l=s4.length(),p=0,j;
	for(j=0;j<l;j++)
	{
		p=p*10+(int)s4[j]-48;
	}
	return p;
}*/		
void sieve()
{
	prime[1]=1;
	prime[0]=1;
	for(i=2;i*i<M;i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i;j<M;j+=i)
			{
				prime[j]=1;
			}
		}
	}
}				
int main()
{
	int t;
	scanf("%d",&t);
	sieve();
	/*for(i=100;i<200;i++)
	{
		if(prime[i]==0)
			cout<<i<<" ";
	}*/		
	while(t--)
	{
		int mark[M]={0};
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)
		{
			cout<<"0"<<endl;
			continue;
		}	
		queue < pair< string,int > > q ;
		q.push(make_pair(s1,0));
		mark[atoi(s1.c_str())]=1;
		int level=0,flag=0;
		while(!q.empty())
		{
			
			pair< string,int> ap=q.front();
			level=ap.second+1;
			q.pop();
			string s=ap.first;
			int l=s.length();
			for(i=0;i<l;i++)
			{
				for(j=0;j<10;j++)
				{
					if(i==0 && j==0)
					continue;
					string s3=s;
					s3[i]=j+'0';
					//cout<<" s3 is "<<s3<<endl;
					if(s3==s)
					{
						continue;
					}
					int p=atoi(s3.c_str());
					if(s3==s2 && prime[p]==0)
					{
						cout<<level<<endl;
						flag=1;
						break;
					}						
				
					if(prime[p]==0)
					{					
						if(mark[p]==0)
						{
							//cout<<" s3 is "<<s3<<endl;
							q.push(make_pair(s3,level));
							mark[p]=1;
						}	
					}
				}
				if(flag==1)
				break;
			}
			if(flag==1)
				break;
			
		}
		if(flag==0)
		cout<<"Impossible"<<endl;
	}
	return 0;
}							
						
