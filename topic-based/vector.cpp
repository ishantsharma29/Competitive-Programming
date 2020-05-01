#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[2000][2000];
	a[0][0]=1;
	cout<<a[0][0]<<endl;
	int i,j;
	vector<int> v;
	v.push_back(100);
	v.push_back(50);
	v.push_back(300);
	v.push_back(400);
	v.erase(v.begin()+1);
	//sort(v.begin(),v.end());
	for(j=0;j<v.size();j++)
	{
		cout<<v[j]<<endl;
	}
	
return 0;
}		
	
