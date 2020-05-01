#include<bits/stdc++.h>
using namespace std;
int findm(int arr[],int n,int visited[]);
int main()
{
int n,m;
cout<<"Enter no. of nodes"<<endl;
cin>>n;

cout<<"enter no of edges"<<endl;
cin>>m;
int x,y,z,i;
vector<pair<int,int> > glis[n];
for(i=0;i<m;i++)
{
pair<int,int> ap;
cin>>x;
cin>>y;
cin>>z;
ap.first=y;
ap.second=z;
glis[x].push_back(ap);
ap.first=x;
ap.second=z;
glis[y].push_back(ap);
}
int parent[n];
int dist[n];
int visited[n];
for(i=0;i<n;i++)
{
parent[i]=-1;
dist[i]=INT_MAX;
visited[i]=0;
}
int itr;
dist[0]=0;int mi;
for(i=0;i<n;i++)
{
mi=findm(dist,n,visited);
visited[mi]=1;

for(itr=0;itr!=glis[mi].size();++itr)
{

if(dist[glis[mi][itr].first]> dist[mi]+glis[mi][itr].second)
{ 
dist[glis[mi][itr].first]=dist[mi]+glis[mi][itr].second;
parent[glis[mi][itr].first]=mi;
}

}
}
for(i=0;i<n;i++)
cout<<i<<" "<<parent[i]<<" "<<dist[i]<<endl;
}
int findm(int arr[],int n,int visited[])
{
int i,m,index;
m=INT_MAX;
index=0;
for(i=0;i<n;i++)
{
if(arr[i]<m && visited[i]==0)
{
m=arr[i];
index=i;
}
}
return index;
}

