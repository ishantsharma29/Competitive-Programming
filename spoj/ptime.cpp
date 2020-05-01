#include <bits/stdc++.h>
using namespace std;
long long int check[20000];
long long int prime[15000];
void shieve()
{
    for(int i=3;i*i<20000;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=20000;j+=i)
                check[j]=1;
        }
    }
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=20000;i+=2)
    {
        if(!check[i]){
            prime[j++]=i;
        }
    }
}
int main()
{
	shieve();
	long long int n,k,i,p,count;
	cin>>n;
	k=0;
	for(i=prime[k];i<=n;i=prime[++k])
	{
		count=0;
		p=n;
		while(p>0)
		{
			count=count+p/i;
			p=p/i;
		}
		if(i==2)	
			cout<<i<<"^"<<count;
		else
			cout<<" "<<"*"<<" "<<i<<"^"<<count;
	}	
	return 0;
}	
