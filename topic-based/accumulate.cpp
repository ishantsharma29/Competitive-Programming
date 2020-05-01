#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
string s[100];
int a[100], b[100];

int main() {
	int n, m,i;
	cin >> n >> m;
	vector< bool > v(n,0);
	string s;
	s.push_back(48);
	s.push_back(49);
	cout<<s<<endl;
	b[2]=1;
	b[3]=1;
	cout << accumulate(b, b+m, 1);
	v[2]=1;
	for(i=0;i<v.size();i++)
		cout<<v[i]<<" ";


}
