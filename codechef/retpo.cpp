#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t,x,y,p,q,m,d,res;
cin>>t;
while(t--)
{
	res=0;
	cin>>x>>y;
	p=x>0?x:-x;
	q=y>0?y:-y;
	m=p>q?p:q;
        d=m==p?p-q:q-p;
	if(x==0 && y==0)
		res=0;
	else if(y==0)
	{
		if(p%2==0)
			res=2*p;
		else
		res=2*p+1;
	}
	else if(x==0)
	{
		res=q%2==0?2*q:2*q-1;
	}
	else if(p%2==1 && q%2==1)
	{
		res=p+q+d;
	}
	else if(p%2==0 && q%2==1 || p%2==1 && q%2==0)
	{
		res=m==p?2*p+1:2*q-1;
	}
	else
	{
		res=p+q+d;
	}
 cout<<res<<endl;
}
return 0;
}
	
	


