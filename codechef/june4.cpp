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
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)

#define inp2(n,m) inp(n), inp(m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define outl(n) printf("%lld\n",n);


vector<long long int> v1,v2;
long long int initial[5]={0,2,4,6,8},in,k;
int t;

int main()
{
	in=1;
    for(int i=0;i<20;i++)
    {
    	v1.pb(in);
    	in=in*5;
    }    
    inp(t);
    while(t--)
    {
    	v2.clear();
	    cin>>k;
        if(k==1)
        {
        	cout<<"0"<<endl;
        	continue;
        }
        if(k==2)
        {
        	cout<<"2"<<endl;
        	continue;
        }
        if(k==6)
        {
        	cout<<"20"<<endl;
        	continue;
        }
        k=k-1;
	    long long int c;
        int flag=0;
	    for(int i=0;i<19;i++)
	    {
	    	if(k<=v1[i+1] && k>=v1[i])
	    	{	
	    		if(k==v1[i+1] || k==v1[i])
	    		{
	    			flag=1;
	    		}
	    		c=v1[i];
	    		break;    
	    	}
	    }
        if(flag==1)
        	k++;

	    //chk2(k,c);
	    while(c!=0)
	    {
	    	v2.push_back(k/c);
	    	k = k%c;
	    	c=c/5;
	    }    
	    if(flag)
	    {
	        for(int i=v2.size()-1;i>=0;i--)
		    {
		    	//chk(v2[i]);
		    	cout<<initial[v2[i]];
		    	//chk(initial[7]);
		    }
		    cout<<"0";
		    cout<<endl;	
	    }
	    else
	    {
	       for(int i=0;i<v2.size();i++)
	       {
	       	 //chk(v2[i]);
	    	 cout<<initial[v2[i]];
	       }
	       cout<<endl;		
	    }
    }
	return 0;
}
