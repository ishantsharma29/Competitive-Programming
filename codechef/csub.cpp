#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t,n,c,p,i;
char s[1000000];
cin>>t;

while(t--)
{
 p=0;
 cin>>n;
 //scanf("%s",s);
 for(i=0;i<n;i++)
  {
 	cin>>s[i];
        if(s[i]=='1')
		p++;
 }
 c=p*(p+1)/2;
 cout<<c<<endl;
}

return 0;
}
