#include<bits/stdc++.h>
using namespace std;

int palin(string s,int st,int e)
{
	int i,j;
	for(i=st,j=e;i<j;i++,j--)
	{
		if(s[i]!=s[j])
			return 0;
	}
	return 1;
}			
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		string s;
		int i,j;
		cin>>s;
		int l=s.length();
		int b[30]={0};
		int odd_char=0;
		//int no_of_one_freq_char=0;
		for(i=0;i<l;i++)
		{
			b[(int)s[i]-97]++;
		}
		for(i=0;i<26;i++)
		{
			if(b[i]%2==1)
				odd_char++;
		}
		int miss=0;
		if(odd_char>2)
		{
			cout<<"NO"<<endl;
		}					
		else
		{
			for(i=0,j=l-1;i<j;i++,j--)
			{
				if(s[i]==s[j]){}
				else
				{
					int q=palin(s,i+1,j);
					int p=palin(s,i,j-1);
					if(p||q)
						cout<<"YES"<<endl;
					else
						cout<<"NO"<<endl;
					miss=1;	
					break;
				}
			}
			if(!miss)
			cout<<"YES"<<endl;
		}					
			
	}
	return 0;
}	
