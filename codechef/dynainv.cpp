#include<bits/stdc++.h>
using namespace std;
 
long long int n,q,b[1000007],a[1000007],t,tmp[1000007],p,i,x,y;
 
 
void merge(long long int a[],long long int l1,long long int u1,long long int l2,long long int u2)
{
long long int c=l1;
long long int d=l1;
while(l1<=u1&&l2<=u2)
{
if(a[l1]>a[l2])
{
p=p+l2-c;
tmp[c++]=a[l2++];
}
else
tmp[c++]=a[l1++];
}
while(l1<=u1)
tmp[c++]=a[l1++];
while(l2<=u2)
tmp[c++]=a[l2++];
for(i=u2;i>=d;i--)
a[i]=tmp[i];
}
 
void msort(long long int a[],long long int s,long long int e)
{
long long int m;
if(s!=e)
{
m=(s+e)/2;
msort(a,s,m);
msort(a,m+1,e);
merge(a,s,m,m+1,e);
}
}
 
 
 
int main()
{
 
cin>>n>>q;
 p=0;
for(i=1;i<=n;i++)
cin>>b[i];
for(i=1;i<=n;i++)
a[i]=b[i];
msort(a,1,n);
//cout<<p<<endl;
while(q--)
{
 
cin>>x>>y;
p+=1;
/*t=b[x];
b[x]=b[y];
b[y]=t;
*/
p=p%2;
cout<<p<<endl;

}
return 0;
}
