#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <queue>
#include <cassert>
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5 + 10, mod = 1e9+7;

char input[2000][2000];
static int cumXor[2000][2000];
bitset<2000> bits[2000];
int n, m;

long long ans = 0;

int main() {
	//rf;// wf;
	ios::sync_with_stdio(0);

	cin >> n >> m;
	rep(i, 0, n-1){
		cin >> input[i];
	}

	rep(i, 1, n) rep(j, 1, m) {
		cumXor[i][j] = input[i-1][j-1] - '0';
		cumXor[i][j] ^= cumXor[i-1][j];
		cumXor[i][j] ^= cumXor[i][j-1];
		cumXor[i][j] ^= cumXor[i-1][j-1];

		bits[i][j] = cumXor[i][j];
	}
	rep(i,0,n){ rep(j,0,m) {
		cout<<bits[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	rep(i, 1, n) rep(j, 0, i-1) {
		int x = (bits[i]^bits[j]).count();
		int y = m+1 - x;
		cout<<"i "<<i<<endl;
		cout<<x<<" "<<y<<endl;

		ans += (1ll*x*(x-1))/2;
		ans += (1ll*y*(y-1))/2;
		cout<<"ans "<<ans<<endl;
	}
	cout << ans << endl;

	return 0;
}
/*
#include <iostream>
#include <string>
#include <bitset>
using namespace std;


//ifstream cin("input01.txt");
//ofstream cout("out01.txt");
int n,m;
int fld[1111][1111];
string st;
bitset<1111> bt[1111];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>st;
		for(int j=0;j<m;j++){
			fld[i+1][j+1]=st[j]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			fld[i][j]+=fld[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			fld[i][j]+=fld[i-1][j];
			fld[i][j]%=2;
			bt[i][j]=fld[i][j];
		}
	}
	long long sol=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int c= ( bt[i] ^ bt[j]).count();
			int d= m+1-c;
			sol += c*1ll*(c-1)/2;
			sol += d*1ll*(d-1)/2;
		}
	}
	cout<<sol<<endl;
}
*/
