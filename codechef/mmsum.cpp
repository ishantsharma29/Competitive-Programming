#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define a_size(x) sizeof(x)/sizeof(x[0])
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define rep(i, begin, end) for(i = (begin); i != (end) + 1 - 2 * ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep_stl(i, ob) for(auto i = ob.begin(); i != ob.end(); i++)
#define MAX (1e+5) + 1
#define MOD (1e+9) + 7
#define endl "\n"
#define after_dec(a) cout<<fixed<<setprecision((a))
//#define TIMER cout<<endl<<"Time Taken : "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<" seconds."<<endl
//#define FILE freopen("test.in", "r", stdin); freopen("test.out", "w", stdout)
typedef long long ll;
typedef long double ld;
typedef double D;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> matrix;
typedef vector<vi> vii;
clock_t t1 = clock();
 
 
ll a[(ll)MAX],n,t,best=LLONG_MIN,minPrefix=0,minSuffix=0,lefta[(ll)MAX],righta[(ll)MAX],sum=0;
 
int main(){
	FAST;
	#ifdef FILE
		FILE;
	#endif
	cin>>t;
	while(t--){
		minPrefix = 0, minSuffix = 0, sum = 0, best = LLONG_MIN;
		fill(a,0);fill(lefta,0);fill(righta,0);
		cin>>n;
		ll i,j,k;
		rep(i,0,n-1){
			cin>>a[i];
			sum += a[i];
			best = max(best, sum-minPrefix);
			lefta[i] = sum - minPrefix;
			minPrefix = min(minPrefix, sum);
			cout<<"min prefix" << minPrefix<< endl;
		    cout<<"best "<< best << endl;
		    cout<< lefta[i]<<endl;
		} 
				
		sum = 0;
		rep(i,n-1,0){
			sum += a[i];
			righta[i] = sum - minSuffix;
			minSuffix = min(minSuffix, sum);
			cout<<"min Suffix" << minSuffix<< endl;
			cout<< righta[i]<<endl;
		}
 
 		rep(i,0,n-1)
		{
			cout<<lefta[i]<<" ";
		}
		cout<<endl;
		
		rep(i,0,n-1)
		{
			cout<<righta[i]<<" ";
		}
		cout<<endl;
 
		rep(i,0,n-1){
			ll current = 0;
			if(i > 0) current += lefta[i-1];
			if(i < n-1) current += righta[i+1];
			cout<<i<<"  "<<current<<endl;
			best = max(best, current);
		}
		cout<<best<<endl;
	}
	#ifdef TIMER
		TIMER;
	#endif
	return 0;
}
