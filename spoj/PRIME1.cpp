#include <bits/stdc++.h>
using namespace std;
int check[32000];
int prime[10000];
int range[100007];
int i,j,a,b,t,k,x;
void sieve()
{
    for(int i=3;i<=180;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=32000;j+=i)
                check[j]=1;
        }
    }
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=32000;i+=2)
    {
        if(!check[i]){
            prime[j++]=i;
        }
    }
}


int main()
{
	sieve();
		
	cin>>t;
	//cout<<t<<endl;
	while(t--)
	{
		
		cin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		int range[b-a+1];
		for(i=0;i<b-a+1;i++)
			range[i]=0;
		if(a==1)
			range[0]=1;
		j=0;
		for(i=prime[j];i*i<=b;i=prime[++j])
		{
			//cout<<"entered"<<i<<endl;
			
			if(a%i==0)
				x=a/i;
			else
				x=(a/i)+1;	
			//cout<<x<<endl;
			int idx=x*i-a;
			if(idx+a==i)
				idx+=i;
			for(k=idx;k<b-a+1;k+=i)
				range[k]=1;
		}
		for(i=0;i<b-a+1;i++)
		{
			if(range[i]==0)
				cout<<a+i<<endl;
		}
		cout<<endl;
		
	}
	return 0;
}						
