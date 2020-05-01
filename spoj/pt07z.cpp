#include<bits/stdc++.h>
using namespace std;
#define M 10005
int n,e,x,y;
vector<int> v[M];
int setnode[M],maxi=INT_MIN,node;
void Dfs(int current,int length)
{
    setnode[current]=1;
    int i,flag=0;
    for(i=0;i<v[current].size();i++)
    {
        if(!setnode[v[current][i]])
        {
            flag=1;
            Dfs(v[current][i],length+1);
        }
    }
    if(flag==0)
    {
        if(length>maxi)
        {
            maxi=length;
            node=current;
        }
    }
}

int main()
{
    scanf("%d",&n);
    e=n-1;
    while(e--)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    Dfs(1,0);
    maxi=INT_MIN;
    int i;
    for(i=0;i<M;i++)
    {
        setnode[i]=0;
    }

    Dfs(node,0);
    cout<<maxi<<endl;

}
