#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,k,l;


struct node
{
 int x,y;
};

typedef struct node ll;
ll arr[100];

int comp(const void *a,const void *b)
{
  ll *X = (ll *)a;
  ll *Y = (ll *)b;
  
  return Y->x-X->x;
  /*
  FIRST ELEMENT BASIS
  INCREASING: X->x-Y-x;
  Decresing:  Y->x-X->x
  Second Element Basis:
  INCREASING : X->y-Y->y;
  Decreasing: Y->y-X->y;
 */ 
}

	
int main()
{
 cin >> n;
 
 for(i=0;i<n;i++)
 {
   cin >> arr[i].x >> arr[i].y;
 }
 

  qsort(arr,n,sizeof(ll),comp);
 for(i=0;i<n;i++)
 {
  cout << arr[i].x << " "<<arr[i].y<<endl;
 }
 
 return 0;
}
