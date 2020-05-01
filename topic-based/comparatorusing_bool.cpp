#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,k,l;


struct node
{
 int x,y;
};

typedef struct node ll;
ll arr[100];

bool comp( node a, node b)
{
	return a.x<b.x;
	/*a.x<b.x increasing
	a.x>b.x decreasing
	a.y<b.y increasing
	a.y>b.y decreasing
	*/
	
}	

	
int main()
{
 cin >> n;
 
 for(i=0;i<n;i++)
 {
   cin >> arr[i].x >> arr[i].y;
 }
 

  sort(arr,arr+n,comp);
 for(i=0;i<n;i++)
 {
  cout << arr[i].x << " "<<arr[i].y<<endl;
 }
 
 return 0;
}
