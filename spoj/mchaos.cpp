#include <stdio.h>
#include <string>
#include <map>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long int ull;

const int NMAX = 100000+5;
ull BIT[NMAX];
int LIM = 0;
map<ull, int> dict,d2;
char vs[NMAX][12], sq[NMAX][12];
ull vecs[NMAX], seq[NMAX];
ull read (int v) {
    ull sum = 0;
    while (v) {
        sum += BIT[v];
        v -= (v &-v);
    }
    return sum;
}

void update (int v, int val) {
    
    while (v <= LIM) {
        BIT[v] += val;
        v += (v & -v);
    }
}

void reverse(char *s) {
    char c;
    int l = strlen(s);
    for (int i=0; i <= l/2-1; i++) {
        c = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = c;
    }
}
ull hash(char *s){   
    ull sum = 0;
    for (int i = 0; i < strlen(s); i++) sum = sum * 31 + s[i]-'a'+1;
    for (int i = strlen(s); i < 10; i++) sum *= 31;
    return sum;
}
int main () {
    int N;
    memset(BIT, 0, sizeof(BIT));
    memset(vecs, 0, sizeof(vecs));
    memset(seq, 0, sizeof(seq));
    cin >> N;
    string s;
    for (int i=0; i < N; i++) scanf("%s", vs[i]);
    for (int i=0; i < N; i++) {vecs[i] = hash(vs[i]);d2[vecs[i]] = i;}
    sort(vecs, vecs+N);
    for (int i = 0; i < N; i++) {
        strcpy(sq[i],vs[d2[vecs[i]]]);
        reverse(sq[i]);
        seq[i] = hash(sq[i]);
    }
    sort(seq, seq+N);
    for (int i = 0; i < N; i++) dict[seq[i]] = i+1;
    LIM = N+1;
    ull bad_pairs = 0;
    for (int i = N-1; i >= 0; i--) {
        bad_pairs += read(dict[hash(sq[i])]);
        update(dict[hash(sq[i])], 1);
    }
    cout << bad_pairs << endl;
    return 0;
}
