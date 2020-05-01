/*
	Created BY--
	Ishant Sharma
	ishantsharma29@gmail.com
*/	


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

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

struct data
{
	int sc1,ec1, ans1;
	int sc2,ec2, ans2;
	int sc3,ec3, ans3;
	int sc4,ec4, ans4;
	int sc5,ec5, ans5;
	int sc6,ec6, ans6;
	int sc7,ec7, ans7;
	int sc8,ec8, ans8;
	int sc9,ec9, ans9;
	int sc10,ec10,ans10;
	int sc11,ec11,ans11;
	int sc12,ec12,ans12;
};
     string se;
     char s,e;
     int l,r,q;
    data t[2000100];
     
    void build (string se, int v, int tl, int tr) {
            if (tl == tr)
            {
		    char val=se[tl-1];
 	            data res;
		    res.sc1=0;res.ec1=0;res.ans1=0;
		    res.sc2=0;res.ec2=0;res.ans2=0;
		    res.sc3=0;res.ec3=0;res.ans3=0;
		    res.sc4=0;res.ec4=0;res.ans4=0;
		    res.sc5=0;res.ec5=0;res.ans5=0;
		    res.sc6=0;res.ec6=0;res.ans6=0;
		    res.sc7=0;res.ec7=0;res.ans7=0;
		    res.sc8=0;res.ec8=0;res.ans8=0;
		    res.sc9=0;res.ec9=0;res.ans9=0;
		    res.sc10=0;res.ec10=0;res.ans10=0;
		    res.sc11=0;res.ec11=0;res.ans11=0;
		    res.sc12=0;res.ec12=0;res.ans12=0;
		    if (val=='c')
		    {
		    	res.sc1=1;res.sc2=1;res.sc3=1;res.ec4=1;res.ec7=1;res.ec10=1;
		    }
		    else if(val=='h')
		    {
		    	res.sc4=1;res.sc5=1;res.sc6=1;res.ec1=1;res.ec8=1;res.ec11=1;
		    }		
		    else if(val=='e')
		    {
		    	res.sc7=1;res.sc8=1;res.sc9=1;res.ec2=1;res.ec5=1;res.ec12=1;
		    }
		    else
		    {
		    	res.sc10=1;res.sc11=1;res.sc12=1;res.ec3=1;res.ec6=1;res.ec9=1;
		    }  
		    t[v]=res;
             
             }
             
            else {
                    int tm = (tl + tr) / 2;
                    build (se, v*2, tl, tm);
                    build (se, v*2+1, tm+1, tr);
                    data l=t[v*2]; data r=t[v*2+1];
                    data res;
		   res.sc1=l.sc1+r.sc1; res.ec1=l.ec1+r.ec1; res.ans1=l.ans1+r.ans1+l.sc1*r.ec1;
		   res.sc2=l.sc2+r.sc2; res.ec2=l.ec2+r.ec2; res.ans2=l.ans2+r.ans2+l.sc2*r.ec2;
		   res.sc3=l.sc3+r.sc3; res.ec3=l.ec3+r.ec3; res.ans3=l.ans3+r.ans3+l.sc3*r.ec3;
		   res.sc4=l.sc4+r.sc4; res.ec4=l.ec4+r.ec4; res.ans4=l.ans4+r.ans4+l.sc4*r.ec4;
		   res.sc5=l.sc5+r.sc5; res.ec5=l.ec5+r.ec5; res.ans5=l.ans5+r.ans5+l.sc5*r.ec5;
		   res.sc6=l.sc6+r.sc6; res.ec6=l.ec6+r.ec6; res.ans6=l.ans6+r.ans6+l.sc6*r.ec6;
		   res.sc7=l.sc7+r.sc7; res.ec7=l.ec7+r.ec7; res.ans7=l.ans7+r.ans7+l.sc7*r.ec7;
		   res.sc8=l.sc8+r.sc8; res.ec8=l.ec8+r.ec8; res.ans8=l.ans8+r.ans8+l.sc8*r.ec8;
		   res.sc9=l.sc9+r.sc9; res.ec9=l.ec9+r.ec9; res.ans9=l.ans9+r.ans9+l.sc9*r.ec9;
		   res.sc10=l.sc10+r.sc10; res.ec10=l.ec10+r.ec10; res.ans10=l.ans10+r.ans10+l.sc10*r.ec10;
		   res.sc11=l.sc11+r.sc11; res.ec11=l.ec11+r.ec11; res.ans11=l.ans11+r.ans11+l.sc11*r.ec11;
		   res.sc12=l.sc12+r.sc12; res.ec12=l.ec12+r.ec12; res.ans12=l.ans12+r.ans12+l.sc12*r.ec12;
		   t[v]=res;
		
            }
    }
     
    data query (int v, int tl, int tr, int le, int re) {
            if (le == tl && tr == re)
                    return t[v];
            int tm = (tl + tr) / 2;
            if (r <= tm)
                    return query (v*2, tl, tm, le, re);
            if (l > tm)
                    return query (v*2+1, tm+1, tr, le, re);
            else
            {        
            
              data l=query (v*2, tl, tm, le, tm);
              data r=query (v*2+1, tm+1, tr, tm+1, re);
              data res;
           res.sc1=l.sc1+r.sc1; res.ec1=l.ec1+r.ec1; res.ans1=l.ans1+r.ans1+l.sc1*r.ec1;
           res.sc2=l.sc2+r.sc2; res.ec2=l.ec2+r.ec2; res.ans2=l.ans2+r.ans2+l.sc2*r.ec2;
           res.sc3=l.sc3+r.sc3; res.ec3=l.ec3+r.ec3; res.ans3=l.ans3+r.ans3+l.sc3*r.ec3;
           res.sc4=l.sc4+r.sc4; res.ec4=l.ec4+r.ec4; res.ans4=l.ans4+r.ans4+l.sc4*r.ec4;
           res.sc5=l.sc5+r.sc5; res.ec5=l.ec5+r.ec5; res.ans5=l.ans5+r.ans5+l.sc5*r.ec5;
           res.sc6=l.sc6+r.sc6; res.ec6=l.ec6+r.ec6; res.ans6=l.ans6+r.ans6+l.sc6*r.ec6;
           res.sc7=l.sc7+r.sc7; res.ec7=l.ec7+r.ec7; res.ans7=l.ans7+r.ans7+l.sc7*r.ec7;
           res.sc8=l.sc8+r.sc8; res.ec8=l.ec8+r.ec8; res.ans8=l.ans8+r.ans8+l.sc8*r.ec8;
           res.sc9=l.sc9+r.sc9; res.ec9=l.ec9+r.ec9; res.ans9=l.ans9+r.ans9+l.sc9*r.ec9;
           res.sc10=l.sc10+r.sc10; res.ec10=l.ec10+r.ec10; res.ans10=l.ans10+r.ans10+l.sc10*r.ec10;
           res.sc11=l.sc11+r.sc11; res.ec11=l.ec11+r.ec11; res.ans11=l.ans11+r.ans11+l.sc11*r.ec11;
           res.sc12=l.sc12+r.sc12; res.ec12=l.ec12+r.ec12; res.ans12=l.ans12+r.ans12+l.sc12*r.ec12;
           
           return res;
    	    }	
    }      	
	
int main()
{
	cin>>se;
	int len=se.length();
	inp(q);
	char y;
	build(se,1,1,len);
	while(q--)
	{
		scanf("%c",&s);
		scanf("%c",&y);
		scanf("%c",&e);
		inp(l);inp(r);
		//cout<<s<<" "<<e<<" "<<l<<" "<<r<<endl;
		//return 0;
		data T=query(1,1,len,l,r);
		if( s=='c' && e=='h')
		{
			out(T.ans1);
		}	
		else if( s=='c' && e=='e')
		{	out(T.ans2); }
		else if( s=='c' && e=='f')
		{	out(T.ans3); }
		else if( s=='h' && e=='c')
		{	out(T.ans4); }
		else if( s=='h' && e=='e')
		{	out(T.ans5); }
		else if( s=='h' && e=='f')
		{	out(T.ans6); }
		else if( s=='e' && e=='c')
		{	out(T.ans7); }
		else if( s=='e' && e=='h')
		{	out(T.ans8); }
		else if( s=='e' && e=='f')
		{	out(T.ans9); }
		else if( s=='f' && e=='c')
		{	out(T.ans10); }
		else if( s=='f' && e=='h')
		{	out(T.ans11); }
		else if( s=='f' && e=='e')
		{	out(T.ans12);	}										
	}
	return 0;		
}	

