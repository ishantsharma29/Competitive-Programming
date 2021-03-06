    #include <iostream>
    #include <stdio.h>
    #include <stdint.h>
    #include <vector>
    #include <list>
    #include <queue>
    #include <set>
    #include <utility>
    #include <map>
    #include <string>
    #include <math.h>
    #include <stdlib.h>
    #include <time.h>
    #include <assert.h>
    #include <algorithm>
     
    using namespace::std;
     
    uint64_t mod = 1000000007;
     
    void mat_mult(vector<vector<uint64_t> > &a,
    vector<vector<uint64_t> > &b,
    vector<vector<uint64_t> > &c,
    uint64_t p)
    {
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
    {
    c[i][j] = 0;
    for (int k = 0; k < n; k++)
    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
    }
    }
    }
     
    // Computes the matrix exponentiation, i.e.,
    // b = a^m mod p.
    // Precondition: vector b is resized properly beforehand
    void mat_pow(vector<vector<uint64_t> > &a, vector<vector<uint64_t> > &b, uint64_t m, uint64_t p)
    {
    int n = a.size();
    if (m == 0)
    {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    b[i][j] = ((i == j) ? 1 : 0) % p;
     
    return;
    }
     
    if (m == 1)
    {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    b[i][j] = a[i][j];
     
    return;
    }
     
    vector<vector<uint64_t> > t1(n, vector<uint64_t>(n, 0));
    vector<vector<uint64_t> > t2(n, vector<uint64_t>(n, 0));
     
    mat_pow(a, t1, m/2, p);
    mat_mult(t1, t1, t2, p);
     
    if (m % 2)
    mat_mult(t2, a, b, p);
    else
    {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    b[i][j] = t2[i][j];
    }
    }
     
    int main()
    {
    int T;
    scanf("%d", &T);
     
    for (int t = 0; t < T; t++)
    {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
     
    uint64_t n = (uint64_t) N;
    vector<vector<uint64_t> > A(M, vector<uint64_t>(M, 0));
    for (int i = 0; i < M; i++)
    {
    for (int j = i - 1; j <= i + 1; j++)
    {
    if (j >= 0 && j < M)
    A[i][j] = 1;
    }
    }
     
    vector<vector<uint64_t> > C(M, vector<uint64_t>(M, 0));
    for (int i = 0; i < M; i++)
    {
    for (int j = i - 1; j <= i + 1; j++)
    {
    if (i == j)
    continue;
     
    if (j >= 0 && j < M)
    C[i][j] = 1;
    }
    }
     
    vector<vector<uint64_t> > B(M, vector<uint64_t>(M, 0));
    mat_mult(A, C, B, mod);
    n--;
    vector<vector<uint64_t> > P(M, vector<uint64_t>(M, 0));
    mat_pow(B, P, n/2, mod);
     
    vector<vector<uint64_t> > Q(M, vector<uint64_t>(M, 0));
    if (n & 1)
    mat_mult(C, P, Q, mod);
    else
    {
    for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
    Q[i][j] = P[i][j];
    }
     
    uint64_t ans = 0;
    for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
    ans = (ans + Q[i][j]) % mod;
     
    printf("%d\n", (int) ans);
    }
     
    return 0;
    }

