#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int check[32000];
int prime[10000];
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
    int t,n,temp;long long int total=1;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
	int count=0,i,j,k;
	temp=n;
	total=1;
	k=0;
	for(j=prime[k];j*j<=temp;j=prime[++k])
	{
	    count=0;
	    while(temp%j==0)
	    {
	        count++;
	        temp/=j;
	    }
	    ll t2=pow(j,count+1);
	    ll t3=t2-1;
	    t3=(t3/(j-1));
	    total *=t3;//n=p^a * q^b then no of divisors of n will be (a+1)*(b+1)
	}
	if(temp!=1)
	    total*=(temp+1);
	 printf("%lld\n",total);	
    }
   
    return 0;
}
