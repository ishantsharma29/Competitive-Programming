#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <assert.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define PER(i,a,b) for(i=b;i>=a;i--)
#define X first
#define Y second
#define all(c) c.begin(),c.end() //eg sort(all(v));
 
#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
#define present(container, element) (container.find(element) != container.end()) //for set,map,etc
#define cpresent(container, element) (find(all(container),element) != container.end()) //for vectors
 
typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define sz(a) int((a).size())
#define clr(a) memset(a,0,sizeof(a))
#define ini(a) memset(a,-1,sizeof(a))
 
 
//i/o
#define inp(n) scanf("%d",&n)
#define inp2(n,m) scanf("%d%d",&n,&m)
#define ins(s) scanf("%s",s);
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define inc(n) scanf("%c",&n)
 
/*
// for Codeforces
#define inll(n) scanf("%I64d",&n)
#define inll2(n,m) scanf("%I64d%I64d",&n,&m)
#define outll(n) printf("%I64d\n",n)
#define outll(n) printf("%I64d\n",n)
#define outll2(n,m) printf("%I64d %I64d\n",n,m)
*/
 
#define inll(n) scanf("%lld",&n)
#define inll2(n,m) scanf("%lld%lld",&n,&m)
#define outll(n) printf("%lld\n",n)
#define outll(n) printf("%lld\n",n)
#define outll2(n,m) printf("%lld %lld\n",n,m)
 
 
 
//cost
#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
 
#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
int G[21][21], deg[21];
int main()
{
	int m, n, i, x, y, cnt, j, k;
	inp2(n, m);
	vector<int> ans(1 << n, INF), unsat(1 << n);
	rep(i, m) 
	{
		inp2(x, y);
		x--;
		y--;
		deg[x]++;
		deg[y]++;
		G[x][y] = G[y][x] = 1;
	}
	ans[0] = unsat[0] = 0;
	rep(i, 1 << n)
	{
		x = i;
		y = cnt = 0;
		vector<int> v;
		while (x)
		{
			if (x & 1)
			v.pb(y);
			x >>= 1;
			y++;
		}
		rep(j, v.size())
		{	
			cnt = 0;
			int prev = i ^ (1 << v[j]);
			rep(k, v.size())
			if(G[v[j]][v[k]])
			cnt++;
			if (ans[i] > ans[prev] + unsat[prev] + deg[v[j]] - 2 * cnt)
			{
				unsat[i] = unsat[prev] - cnt;
				unsat[i] += deg[v[j]] - cnt;
				ans[i] = ans[prev] + unsat[i];
			}
// chk4(i, v[j], unsat[i], ans[i]);
		}
	}
	out(ans[(1 << n) - 1]);
	return 0;
}

