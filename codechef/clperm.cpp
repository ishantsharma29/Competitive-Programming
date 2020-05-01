#include<bits/stdc++.h>
using namespace std;
 
unsigned long long int k,arr[100005];
 
unsigned long long int s=0;

int main()
{
	int t,n,i;
	scanf("%d",&t);
	int flag;
	while(t--)
	{
		flag=0;
		s=0;
		cin>>n>>k;
 
		for(i=0;i<k;i++)
		{
		cin>>arr[i];
		}
 
		sort(arr,arr+k);
 
		s=((arr[0])*(arr[0]-1))/2;
		if(s<arr[0])
		{
			flag=1;
			if(arr[0]%2==0)
			{
				printf("Mom\n");
			}
			else
			{
				printf("Chef\n");
			}
		}
		if(flag==0)
		{
			for(i=1;i<k;i++)
			{
				s+=((arr[i]*(arr[i]-1))/2 - (arr[i-1]*(arr[i-1]+1))/2);
				if(s<arr[i])
				{
					flag=1;
				if(arr[i]%2==0)
				{
					printf("Mom\n");
				}	
				else
				{
					printf("Chef\n");
				}
				 
				break;
 
				}
			}
 
			s+=((n*(n+1)/2)-(arr[k-1]*(arr[k-1]+1)/2));
		}
 
 
		if(flag==0)
		{
			if(s%2==1)
			{
				printf("Mom\n");
			}
			else
			{
				printf("Chef\n");
			}
		}	
 
 
	}
return 0;
}
