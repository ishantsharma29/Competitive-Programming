#include<bits/stdc++.h>
using namespace std;

int main()
{	int n,m,attr,val,pri,id,i;
	cin>>n>>m;
	map< pair<int,int> ,int > V;
	map< pair<int,int> ,int > P;
	for(i=0;i<n;i++)
	{
		cin>>id>>attr>>val>>pri;
		if(V[make_pair(id,attr)]==0)
		{
			V[make_pair(id,attr)]=val;
			P[make_pair(id,attr)]=pri;
		}
		else
		{
			if(P[make_pair(id,attr)]<=pri)
			{
				V[make_pair(id,attr)]=val;
				P[make_pair(id,attr)]=pri;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		cin>>id>>attr;
		cout<<V[make_pair(id,attr)]<<endl;
	}
	return 0;
}					
	
/*	typedef pair<int,int> pii;
map<int,pii> prop[1000001];

void solve_50(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        int id,attr,val,priority;
        scanf("%d %d %d %d",&id,&attr,&val,&priority);

        if(prop[id].find(attr) == prop[id].end()){
            prop[id][attr]=pii(val,priority);
        }
        else{
            pii curr=prop[id][attr];
            if(curr.second <= priority){
                prop[id][attr]=pii(val,priority);
            }
        }
    }
    for(int i=0;i<m;i++){
        int id,attr;
        scanf("%d %d",&id,&attr);
        assert(prop[id].find(attr) != prop[id].end());
        printf("%d\n",prop[id][attr].first);
    }
}

int main(){
    solve_50();
}

*/
