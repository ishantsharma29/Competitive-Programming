#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;

const int K = 1e5;

int n, q, a[MaxN];
vector < int > d[MaxN];
int prod[K + 10];
long double lg[MaxN], slg[K + 10];

int inv(int x) {
  return x == 1 ? 1 : 1LL * (MOD - MOD / x) * inv(MOD % x) % MOD;
}

int main() {
//  freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    lg[i] = log10l((long double)a[i]);
  }
  for (int step = 1; step <= K; ++step) {
    prod[step] = 1;
    for (int i = 0; i < n; i += step) {
      d[i].push_back(step);
      prod[step] = 1LL * prod[step] * a[i] % MOD;
      slg[step] += lg[i];
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int type, x, y;
    scanf("%d%d", &type, &x);
    if (type == 1) {
      scanf("%d", &y);
      int iv = inv(a[x - 1]);
      long double nv = log10l((long double)y);
      for (int j = 0; j < (int)d[x - 1].size(); ++j) {
        int r = d[x - 1][j];
        prod[r] = 1LL * prod[r] * iv % MOD * y % MOD;
        slg[r] += nv - lg[x - 1];
      }
      a[x - 1] = y;
      lg[x - 1] = nv;
    } else {
      if (x <= K) {
        long double digit = powl(10.0, slg[x] - floorl(slg[x]) + 1e-11);
        while (digit >= 10.0) {
          digit /= 10.0;
        }
        while (digit < 1.0) {
          digit *= 10.0;
        }
        printf("%d %d\n", (int)digit, prod[x]);
      } else {
        int mul = 1;
        long double val = 0;
        for (int i = 0; i < n; i += x) {
          mul = 1LL * mul * a[i] % MOD;
          val += lg[i];
        }
        long double digit = powl(10.0, val - floorl(val) + 1e-11);
        while (digit >= 10.0) {
          digit /= 10.0;
        }
        while (digit < 1.0) {
          digit *= 10.0;
        }
        printf("%d %d\n", (int)digit, mul);
      }
    }
  }
  return 0;
}
