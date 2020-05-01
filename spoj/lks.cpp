#include<bits/stdc++.h>
using namespace std;
#define M 501
#define Q 2000001
int B[2][Q];

int n,w[M],i,j,b[M],W;//,B[M][Q];
int main()
{

scanf("%d %d",&W,&n);

for(i=1;i<=n;i++)
{
	scanf("%d %d",&b[i],&w[i]);
}
//BOTTOM-UP APPROACH 
for(i=1;i<=n;i++)
{
	if(i%2)
	{
		for(j=1;j<=W;j++)
		{
		if(w[i]>j)
		{
		     B[1][j]=B[0][j];
		}
       		else
       		{
        	    B[1][j]=max(b[i]+B[0][j-w[i]],B[0][j]);
       		}
       		}
	}
	else
	{
		
		for(j=1;j<=W;j++)
		{
		if(w[i]>j)
		{
		     B[0][j]=B[1][j];
		}
       		else
       		{
        	    B[0][j]=max(b[i]+B[1][j-w[i]],B[1][j]);
       		}
       		}
       	}	
}


//printf("Printing the items taken\n");

printf("%d\n",B[n%2][W]);
return 0;
}

