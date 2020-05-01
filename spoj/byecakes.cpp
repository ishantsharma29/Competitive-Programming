#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,c,max,pos,no_of_cakes,mod;
	long long int a[10];
	while(1)
	{
		for(i=0;i<8;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(a[0]==-1||a[1]==-1||a[2]==-1||a[3]==-1||a[4]==-1||a[5]==-1||a[6]==-1||a[7]==-1)
		{
			break;
		}
		if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)
		{
			cout<<"0 0 0 0"<<endl;
		}
		else if(a[0]<a[4] && a[1]<a[5] && a[2]<a[6] && a[3]<a[7])
		{
			cout<<a[4]-a[0]<<" "<<a[5]-a[1]<<" "<<a[6]-a[2]<<" "<<a[7]-a[3]<<endl;
		}	
		else
		{
			
			max=INT_MIN;
			mod=0;
			for(i=0;i<4;i++)
			{
				if(a[i]>=a[i+4])
				{
					c=a[i]/a[i+4];
					
					if(c==max)
					{
						max=c;
						if(a[i]%a[i+4]>mod)
						{
							pos=i;
							mod=a[i]%a[i+4];
						}
							
					}
					if(c>max)
					{
						max=c;
						pos=i;
						mod=a[i]%a[i+4];
							
					}
				
				}
				
			}
			if(mod==0)
			{
				no_of_cakes=max;
			}
			else
			{
				no_of_cakes=max+1;
			}
			for(i=4;i<8;i++)
			{
				a[i]=a[i]*no_of_cakes;
				a[i-4]=a[i]-a[i-4];
			}
			for(i=0;i<3;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<a[3]<<endl;
		}
	}
	return 0;
}												
