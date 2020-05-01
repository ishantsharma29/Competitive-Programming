#include <bits/stdc++.h>

using namespace std;

void Union(int p1,int p2,int parent[],int rank[]);
int find(int x,int parent[]);

int main()
{
int n,m,a,b;
long long int w;

scanf("%d %d",&n,&m);

vector<pair<long long int,pair<int,int> > > v;

int parent[n+1];
int rank[n+1];
while(m--)
{
scanf("%d",&a);
scanf("%d",&b);
scanf("%lld",&w);
pair<int, int> p;
p=make_pair(a,b);
pair<long long int,pair<int,int> > p1;
p1=make_pair(w,p);
v.push_back(p1);
}
int i;
sort(v.begin(),v.end());
/*for(i=0;i<v.size();i++)
{
printf("%d %d \n",v[i].second.first,v[i].second.second);
}*/
int count=0;
long long int sum=0;

for(i=1;i<=n;i++)
{
parent[i]=i;
rank[i]=1;
}

for(i=0;i<v.size();i++)
{
int p1=find(v[i].second.first,parent);
int p2=find(v[i].second.second,parent);

if(p1!=p2)
{
Union(p1,p2,parent,rank);
sum=sum+v[i].first;
}
}
printf("%lld",sum);
}
int find(int x,int parent[])
{

if(parent[x]!=x)
parent[x]=find(parent[x],parent);

return parent[x];
}

void Union(int p1,int p2,int parent[],int rank[])
{
if(rank[p1]==rank[p2])
{
parent[p1]=p2;
rank[p2]++;
}
else if(rank[p1]<rank[p2])
{
parent[p1]=p2;
}
else
{
parent[p2]=p1;
}

}
