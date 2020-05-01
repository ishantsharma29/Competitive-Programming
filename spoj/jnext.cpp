#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int a[M],b[M];
int binary_search(int b[],int s,int e,int val)
{
	
	while(s<=e)
	{
		int mid=(s+e)>>1;
		if(b[mid]>val)
			e=mid-1;
		else if(b[mid]<=val)
			s=mid+1;
	}
	return s;
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
			
		
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		int idx=1,pos,num,j;
		b[0]=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(a[i]<a[i+1])
			{
				pos=i;
				num=a[i];
				//cout<<i<<endl;
				break;
			}
			else
			{
				b[idx++]=a[i];
			}
		}
		/*int k;
		for(k=0;k<idx;k++)
			cout<<b[k]<<" ";
		cout<<endl;*/	
		if(i<0)
		{
			printf("-1\n");
			continue;
		}
		else
		{	
			int p=binary_search(b,0,idx-1,num);
			a[pos]=b[p];
			b[p]=num;
			j=0;
			for(i=pos+1;i<n;i++)
			{
				a[i]=b[j];
				j++;
			}
			for(i=0;i<n;i++)
				printf("%d",a[i]);
				//cout<<endl;	
			//cout<<"YES"<<endl;
		}
		printf("\n");
	}
		
	return 0;
}	
	
	
	IIND METHOD
	
	
	#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int a[M];//b[M];

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(next_permutation(a,a+n))	
			for(i=0;i<n;i++)
				printf("%d",a[i]);
		else
			printf("-1");
		
		printf("\n");
	}
		
	return 0;
}
											
