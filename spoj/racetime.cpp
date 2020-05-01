#include<bits/stdc++.h>
using namespace std;
#define M 1000010
int n,q;
long long int x,a[M],b[M],val,y;
int binary_search(int s,int e,long long int val)
{
	int si=s;
	while(s<=e)
	{
		int mid=(s+e)>>1;
		if(b[mid]>val)
			e=mid-1;
		else if(b[mid]<=val)
			s=mid+1;
	}
	return (s-si);
}				
int main()
{
	int i,start,end,magic,endstart,nextstart,k,s,e,temp1;
	char ch;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		a[i]=x;
		b[i]=x;
	}
	magic=sqrt(n);
	//cout<<"magic "<<magic<<endl;
	for(i=0;i<n;i++)
	{
		end=(i+magic)<=n?i+magic:n;
		sort(b+i,b+end);
		i=i+magic-1;
	}
	/*for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}*/
	while(q--)
	{
		scanf("%c",&ch);
		scanf("%c",&ch);
		if(ch=='M')
		{
			scanf("%lld%lld",&x,&val);
			a[x-1]=val;
			x=x-1;
			start=(x/magic);
			start=start*magic;
			end=start+magic;
			for(i=start;i<end;i++)
				b[i]=a[i];
			sort(b+start,b+end);
		}
		else
		{
			scanf("%lld%lld%lld",&x,&y,&val);
			x=x-1;
			y=y-1;
			long long int sum=0;
			start=x/magic;
			end=y/magic;
			for(k=start+1;k<end;k++)
			{
				s=k*magic;
				e=s+magic<=n?s+magic:n;
				temp1=binary_search(s,e-1,val);
				//temp1=upper_bound(b+s,b+e,val)-(b+s);
				sum+=temp1;
			}
			nextstart=(start+1)*magic;
			if(y<nextstart)
			{
				for(i=x;i<=y;i++)
				{
					if(a[i]<=val)
					{
						sum++;
					}
				}
			}
			else
			{
				endstart=k*magic;
				for(i=x;i<nextstart;i++)				
				{
					if(a[i]<=val)
					{
						sum++;
					}
				}
				for(i=endstart;i<=y;i++)				
				{
					if(a[i]<=val)
					{
						sum++;
					}
				}
			}
			printf("%lld\n",sum);
		}		
	}			
				
	return 0;
}				
