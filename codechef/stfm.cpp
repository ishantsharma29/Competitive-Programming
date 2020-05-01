    #include<bits/stdc++.h>
    using namespace std;
    #define M 10005505
    typedef long long ll;
     
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
    int n,m,z=-1;
    ll res[M];
    void precompute()
    {
    res[1]=1;
    ll pre=1,f;
    for(int i=2;i<m;i++)
    {
    pre=(i*pre)%m ;
    if(pre==0)
    {
    // cout<<"I - "<<i<<" res[i-1] "<<res[i-1]<<endl;
    z=i-1;
    break;
    }
    f=(pre*i)%m;
    res[i]=(res[i-1]+f)%m;
    }
    }	
    int main()
    {
    inp(n);inp(m);
    precompute();
    //return 0;
    //cout<<"HELLO"<<endl;
    ll ans=0,x,sum;
    for(int i=1;i<=n;i++)
    {
    scanf("%lld",&x);
    if(x<m)
    {
    if(z!=-1 && x>=z)
    {ans=(ans+res[z])%m ;}
    else
    {
    ans=(ans+res[x])%m;
    }
    if(x%2==1)
    {
    sum=( (x%m) * (((x+1)/2)%m) )%m;
    }
    else
    {
    sum=(((x+1)%m) * (((x)/2)%m) )%m;
    }
    sum=(sum*x)%m;
    ans=(ans+sum)%m;
    }
    else
    {
    // if(z!=-1)
    // ans=(ans+res[z])%m;
    // else
    // ans=(ans+res[m-1])%m;
    ans=(ans+m-1)%m;
    if(x%2==1)
    {
    //sum= ((x+1)>>1);
    //sum=sum%m;
    sum=( (x%m) * ( ( (x+1)>>1 )%m ) )%m;
    }
    else
    {
    //sum= (x>>1);
    //sum=sum%m;
    sum=(((x+1)%m) * ((x>>1)%m) )%m;
    }
    x=x%m;
    sum=(sum*x)%m;
    ans=(ans+sum)%m;
    }
    }
    outl(ans);
    return 0;
    }	


