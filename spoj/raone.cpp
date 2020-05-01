#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(ll i = 0; i < n; i++)
#define reps(i,a,n) for(ll i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x)) + 1)
#define md(a,b) (((a) + (b)) >> 1)
#define INF ((1LL << 57LL))
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
ll t, u, v, n, k, c, d, m, q;
const int N = 14;
const int U = 205;
const int step = 100;
const ll mod = 1000000007;
ll F[N][U];
string ss;
ll h = 0;
ll rec (int pos, int sum, bool smaller) {
    if (pos == 0) {
        return (ll) (sum == 1);
    }
    if (smaller && F[pos][step + sum] != -1) return F[pos][step + sum];
    ll ret = 0;
    for (int i = 0; i <= (smaller ? 9 : (ss[pos] - '0')); ++i) {
        if (pos & 1) {
            ret += rec(pos - 1, sum - i, (smaller|(i < (ss[pos] - '0'))));
        }
        else ret += rec(pos - 1, sum + i, (smaller|(i < (ss[pos] - '0'))));
    }
    if (smaller) F[pos][step + sum] = ret;
    return ret;
}
 
int main() {
    csl;
    cin >> t;
    memset(F, -1, sizeof(F));
    while (t--) {
        cin >> u >> v;
        u--;
        ss = "0";
        while (v) {
            ss.pb(v % 10 + '0');
            v /= 10;
        }
        ll ans = rec(ss.size() - 1, 0, false);
        ss = "0";
        while (u) {
            ss.pb(u % 10 + '0');
            u /= 10;
        }
        ans -= rec(ss.size() - 1, 0, false);
        cout << ans << '\n';
    }
    return 0;
   } 

