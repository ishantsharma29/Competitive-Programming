#include<bits/stdc++.h>
using namespace std;
//typedef long long int ll;
long long int gcd(long long int a,long long int b)
{
	if(a%b==0)
		return b;
	else if(b==0)
		return a;
	else
		return gcd(b,a%b);
}			 
int main()
{
	long long int t,x,num,deno,g,n;
	int i;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		num=0;
		//cout<<s<<endl;
		int l=s.length();
		int pos=l-1;
		for(i=0;i<l;i++)
		{
			if(s[i]=='.')
			{
				pos=i;
			}
			else
			{
				num=num*10+(s[i]-'0');
			}	
		}
		/*if(pos==-1)
		{
			cout<<"1"<<endl;
			continue;
		}*/
		//cout<<"num "<<num<<endl;
		x=pow(10,l-pos-1);
		//cout<<"x "<<x<<endl;
		num=num;
		deno=x;
		g=gcd(num,deno);
		num=num/g;
		deno=deno/g;
		cout<<deno<<endl;
	}
	return 0;
}		
				
