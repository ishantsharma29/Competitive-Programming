#include<bits/stdc++.h>
using namespace std;


#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

#define getcx getchar_unlocked

inline void inp(int &n)
{
	int sign=1; n=0;int ch=getcx();
	while( ch < '0' || ch >'9' ) { if(ch=='-') sign=-1;ch=getcx();}
	while( ch >= '0'&& ch <= '9' ) 
	n=(n<<3)+(n<<1)+(ch-'0'),ch=getcx();
	n=n*sign;
}	
	
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);
#define ll long long int

const int M  = 1000000007;

vector<ll> q(100010,1);

void computation()
{
  for(int i=2; i<=100005;i++)
        q[i]= (q[i-1]*i) % M;   
} 
 

ll PowerModulo(int a, int b, int M)
{
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>M) x%=M;
        }
        y = (y*y);
        if(y>M) y%=M; 
        b /= 2;
    }
    return x;
}

ll InverseModulo(int n, int M)
{
    return PowerModulo(n,M-2,M);
}
 
ll Combination(int n, int r, int M)
{
    return (q[n]*((InverseModulo(q[r], M) * InverseModulo(q[n-r], M)) % M)) % M;
}
 
int main()
{
    computation();    
    int n,k,p,t;
    inp(t);
    while(t--)
    {
        ll sum =0;
        int x;
        inp2(n,k);
       
            int flag=0,cnt=0;
            rep(i,n)
            {
                inp(x);
                if(x==0)
                {
                    flag=1;
                    cnt++;
                }
            }

            if(flag)
            {
            	n=n-cnt;
            	//cout<<"New n"<<n<<endl;
            	if(k>=n)
            	{
            		printf("%lld\n",PowerModulo(2,(n),M));              
              	}
              else
                {
	              for(int i=k;i>=0;i-=1)
	              {
		                sum = (sum + Combination(n,i,M))%M;    
	              }
	              outl(sum); 
	            }                
            }
            else
            {
            	if(k>=n)
        		{
				    printf("%lld\n",PowerModulo(2,(n-1),M) );
				}
            	else
            	{
		           for(int i=k;i>=0;i-=2)
		           {
		             sum = (sum + Combination(n,i,M))%M;    
		           }
		           outl(sum);
		        }
		               
            }
			    
        }
    
     
    
    return 0;
}
