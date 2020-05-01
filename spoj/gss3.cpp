#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
#define REP(i, n) for(i = 0; i < (n); i++)
#define getcx getchar_unlocked
inline void inp(int &n )
{
	n=0; int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
/// pre code ends:
 
struct T{
        LL sum;
 
        LL ls;
        LL rs;
        LL mx;
} tree[1000000];
 
int p[50001];
int n,m,i,type,x,y;
 
void build(int node, int a, int b){
        if(a==b){
                tree[node].sum = p[a];
                tree[node].ls  = p[a];
                tree[node].rs  = p[a];
                tree[node].mx  = p[a];
                return;
        }
        int mid = (a+b)/2;
        build(2*node, a, mid);
        build(2*node+1, mid+1, b);
 
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
        tree[node].ls = max(tree[2*node].ls, tree[2*node].sum + tree[2*node+1].ls);
        tree[node].rs = max(tree[2*node+1].rs, tree[2*node+1].sum + tree[2*node].rs);
        tree[node].mx = max(max(tree[2*node].mx, tree[2*node+1].mx), tree[2*node].rs+tree[2*node+1].ls);
}
 
T  query(int node, int a, int b, int i,int j){
 
        if(i<=a && j>=b){
                return tree[node];
        }
        int mid = (a+b)/2;
 
        if(j<=mid){
                return query(2*node, a, mid, i, j);
        }
        else if(i>mid){
                return query(2*node+1, mid+1, b, i, j);
        }
        else{
                T p1, p2, p3;
 
                p1 = query(2*node, a, mid, i, j);
                p2 = query(2*node+1, mid+1, b, i, j);
 
                p3.sum = p1.sum + p2.sum;
                p3.ls = max(p1.ls , p1.sum+p2.ls);
                p3.rs = max (p2.rs, p2.sum+p1.rs);
                p3.mx = max(max(p1.mx, p2.mx), p1.rs+p2.ls);
                return p3;
        }
 
 
}
 
 void update(int v,int tl,int tr,int l)
    {
    	if( l>tr || l< tl || tl>tr )
    		return ;
    	if( tl==tr )
    	{
    		tree[v].sum = p[tl];
                tree[v].ls  = p[tl];
                tree[v].rs  = p[tl];
                tree[v].mx  = p[tl];
                return;
    	}
    	
    	int mid=(tl+tr)/2;
    	update(v*2,tl,mid,l);
    	update(v*2+1,mid+1,tr,l);	
    	tree[v].sum = tree[v*2].sum+ tree[v*2+1].sum;
        tree[v].ls= max( tree[v*2].ls , tree[v*2].sum + tree[v*2+1].ls);
        tree[v].rs= max( tree[v*2+1].rs , tree[v*2+1].sum + tree[v*2].rs);
        tree[v].mx = max ( max(tree[v*2].mx , tree[v*2+1].mx ) , tree[v*2].rs+tree[v*2+1].ls );
    	
    	
    } 


    int main() {
 	inp(n);
    //    scanf("%d",&n);
        REP(i,n)
        {
        	inp(p[i]);
        }
        build(1,0,n-1);
       // print (n);
        inp(m);
        while(m--)
        {
        	//scanf("%d %d %d",&type,&x,&y);
        	inp(type);inp(x);inp(y);
        	if(type==0)
        	{
        		p[ x-1 ]=y;
        		update(1,0,n-1,x-1);
        	//print(n);
           	 }
		else
		{
			T answer=query(1,0,n-1,x-1,y-1);
			printf("%lld\n",answer.mx);
		}

        }
     return 0;
    }



