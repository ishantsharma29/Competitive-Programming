	

    #include <bits/stdc++.h>
    
     
    using namespace std;
     
    #define REP(i, n) for(i = 0; i < (n); i++)
    #define FOR(i, a, n) for(i = a; i < n; i++)
    #define REV(i, a, n) for(i = a; i > n; i--)
     
    #define getcx getchar_unlocked


	inline void inp(int &n )
	{
	n=0; int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	}
     
    typedef long long ll;
    typedef long double ld;
     
    #define MAXN 50010
    #define INF 1000001000
     
    int n, a[MAXN];
    int i, m, tmp, x,type,y;
     
    struct data {
            int ans;
            int minsum;
    };
     
    data t[200000];
     
    data combine (data l, data r) {
            data res;
            res.ans=l.ans+r.ans;
            res.minsum=min(l.minsum,l.ans+r.minsum);
            return res;
    }
     
    data make_data (int val) {
            data res;
            res.ans = val;
            res.minsum=val;
            return res;
    }
     
    void build (int a[], int v, int tl, int tr) {
            if (tl == tr)
                    t[v] = make_data(a[tl]);
            else {
                    int tm = (tl + tr) / 2;
                    build (a, v*2, tl, tm);
                    build (a, v*2+1, tm+1, tr);
                    t[v] = combine (t[v*2], t[v*2+1]);
            }
    }
     
    data query (int v, int tl, int tr, int l, int r) {
            if ( tl == tr )
                    return t[v];
            int tm = (tl + tr) / 2;
            if (r <= tm)
                    return query (v*2, tl, tm, l, r);
            if (l > tm)
                    return query (v*2+1, tm+1, tr, l, r);
            return combine (
                    query (v*2, tl, tm, l, tm),
                    query (v*2+1, tm+1, tr, tm+1, r)
            );
    }
    
    data update(int v,int tl,int tr,int l,int r)
    {
    	if(tl==l && tl==tr)
    	{
    		t[v]=make_data(a[tl]);
    		return t[v];
    	}	
    	
    	int tm=(tl+tr)/2;
    	if(r<=tm)
    		return t[v]=combine( update(v*2,tl,tm,l,r),t[2*v+1] );
    	if(l>tm)
    		return t[v]=combine(t[2*v], update(v*2+1,tm+1,tr,l,r) );
    		
    	return t[v]=combine( update(v*2,tl,tm,l,r) , update(v*2+1,tm+1,tr,l,r) );
    }			
    	
    void print(int n)
    {
    	for(i=1;i<2*n;i++)
    	{
    		cout<<t[i].ans<<" ";
    	}
    	cout<<endl;
    }		
    	
    int main() {
    
    	int p;
    	for(p=1;p<=10;p++)
	{    
    	string s;
 	inp(n);   
 	//cout<<"n "<<n<<endl;
 	memset(a,0,sizeof(a));
 	
    //    scanf("%d",&n);
        cin>>s;
        //cout<<" s "<<s<<endl;
        REP(i,n)
        {
        	if( s[i]=='(' )
        		a[i+1]=1;
        	else
        		a[i+1]=-1;	
        }
       // for(i=1;i<=n;i++)
        //	cout<<a[i]<<" ";
       // cout<<endl;		
        build(a,1,1,n);
        //print(n);
        inp(m);
        cout<<"Test "<<p<<":"<<endl;
        while(m--)
        {
        	//scanf("%d %d %d",&type,&x,&y);
        	inp(x);
        	if(x!=0)
        	{
        		if( a[x] == 1 )
        		{	a[x] = -1;
        			data useless=update(1,1,n,x,x);
        		}
        		else
        		{
        			a[x]=1;
        			data useless=update(1,1,n,x,x);
        		}
        //		print(n);		
		}
		else
		{
			if( t[1].ans==0 && t[1].minsum==0 )
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}			
				
			
			        
        }
        }
     return 0;   
    }


