#include<bits/stdc++.h>
using namespace std;

  typedef long long ll;
  struct data {
            ll csum,rem0,rem1,rem2;
    };
     ll a[100005];
    data t[1000000];
    ll n,m,i,x,y,type;
     
    data combine (data l, data r) {
            data res;
           // cout<<l.rem0<<" "<<l.rem1<<" "<<l.rem2<<endl;
           // cout<<r.rem0<<" "<<r.rem1<<" "<<r.rem2<<endl;
            res.csum = (l.csum + r.csum)%3;
            if(l.csum==0)
            {
            	res.rem0=l.rem0+r.rem0;
            	res.rem1=l.rem1+r.rem1;
            	res.rem2=l.rem2+r.rem2;
            	res.rem0--;
            }
            else if(l.csum==1)
            {
            	r.rem0--;
            	res.rem0=l.rem0+r.rem2;
            	res.rem1=l.rem1+r.rem0;
            	res.rem2=l.rem2+r.rem1;
            }
            else
            {	
            	r.rem0--;
            	res.rem0=l.rem0+r.rem1;
            	res.rem1=l.rem1+r.rem2;
            	res.rem2=l.rem2+r.rem0;
            }		
            return res;
    }
     
    data make_data (ll val) {
            data res;
            res.csum = val%3;
            if(val%3==0)
            {
            	res.rem0=1;
            	res.rem1=0;
            	res.rem2=0;
            }
            else if(val%3==1)
            {
            	res.rem1=1;
            	res.rem0=0;
            	res.rem2=0;
            }
            else
            {
            	res.rem2=1;
            	res.rem1=0;
            	res.rem0=0;
            }
            
            res.rem0++;			
            return res;
    }
     
    void build (ll a[], int v, int tl, int tr) {
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
            if (l == tl && tr == r)
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
		//cout<<"tl "<<tl<< "  tr "<<tr<<endl;
		if(l==tl && tl==tr)
		{
			//cout<<"tl "<<tl<< "  tr "<<tr<<endl;
			t[v]=make_data(a[tl]);
			return t[v];
		}	
		int tm=(tl+tr)/2;
		if(r<=tm)
			return t[v]=combine (update(v*2,tl,tm,l,r),t[v*2+1]);
		else
			return t[v]=combine(t[2*v],update(v*2+1,tm+1,tr,l,r));
	}			

void print(int n)
{
	int i;
	for(i=1;i<2*n;i++)
	{
		cout<<"INDEX "<<i<<"CSUM "<<t[i].csum<<"  "<<t[i].rem0<<"  "<<t[i].rem1<<" "<<t[i].rem2<<endl;
	}
	cout<<endl;
}		
	

int main()
{
	string s;
	
	scanf("%lld %lld",&n,&m);
	cin>>s;
	for(i=0;i<n;i++)
	{
		a[i+1]=(int)s[i]-'0';
	}
	/*for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;*/		
	build(a,1,1,n);
	/*for(i=1;i<2*n;i++)
	{
		cout<<t[i].csum<<"  "<<t[i].rem0<<"  "<<t[i].rem1<<" "<<t[i].rem2<<endl;
	}
	cout<<endl;*/	
	//print(n);
	while(m--)
	{
		scanf("%lld %lld %lld",&type,&x,&y);
		if(type==2)
		{
		data obj=query(1,1,n,x,y);
		//cout<<obj.rem0<<" "<<obj.rem1<< " " <<obj.rem2<<endl;
		ll ans=(obj.rem0*(obj.rem0-1))/2+(obj.rem1*(obj.rem1-1))/2+(obj.rem2*(obj.rem2-1))/2;
		printf("%lld\n",ans);
		}
		else
		{
			a[x]=y;
			data useless=update(1,1,n,x,x);
			//print(n);
		}	
	}
	return 0;
}		
