#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int e=1000003;
int t,N,L,R;

int l,r,n;
ll ans,ret;


int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 

long long pow(int a, int b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 

long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long factMOD(int n, int MOD)
{
    long long res = 1;
    while (n > 0)
    {
        for (int i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}
 
long long C(int n, int r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
         
 }
int main()
{
	
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>N>>L>>R;
		ans=(C(N+R-L+1,N,e)-1)%e;
		if(ans<0)
		{ 
			ans=ans+e;
		}
		cout<<ans<<endl;
	}
	return 0;
}					
	
