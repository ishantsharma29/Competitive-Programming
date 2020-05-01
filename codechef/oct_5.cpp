#include<bits/stdc++.h>
using namespace std;
#define M 2005

struct node
{
	int x;
	int y;
}a[M];	


int binary_search(int s,int e,int x,int y)
{
	while(s<=e)
	{
		int mid=(s+e)/2;
		//cout<<"a[mid] "<<a[mid].x<<" "<<a[mid].y<<" "<<x<<" "<<y<<endl;
		if(a[mid].x==x && a[mid].y==y)
			return 1;
		else if(a[mid].x<x|| a[mid].x==x && a[mid].y<y)
			s=mid+1;
		else
			e=mid-1;
	}
	return 0;
}					



bool comp(node X, node Y)
{
	return X.x==Y.x?X.y<Y.y:X.x<Y.x;
}	

int main()
{
	int n,p,q,i,ans,l,m,s,d,l1,m1,s1,d1,min=INT_MAX,j;
	int found=0;
	cin>>n;
	if(n==1)
	{
		ans=3;
		min=3;
		
	}
	else if(n==2)
	{
		ans=2;
		min=2;
	}		
	for(i=0;i<n;i++)
	{
		cin>>p>>q;
		a[i].x=p;
		a[i].y=q;
	}	
	sort(a,a+n,comp);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			l=(a[i].y-a[j].y+a[i].x);
			m=(a[j].x-a[i].x+a[i].y);
			s=(a[i].y-a[j].y+a[j].x);
			d=(a[j].x-a[i].x+a[j].y);
			int p1=binary_search(i+1,j-1,l,m);
			int p2=binary_search(j+1,n-1,l,m);
			int p3=binary_search(i+1,j-1,s,d);
			int p4=binary_search(j+1,n-1,s,d);
		//	cout<<"l "<<l<<" "<<m<<" --- "<<s<<" "<<d<<endl;
		//	cout<<"p1 "<<p1<<" "<<p2<<" --- "<<p3<<" "<<p4<<endl;
			if( (p1||p2) && (p3||p4) )
			{
				ans=0;
				min=0;
				found=1;
				break;
			}
			
			else
			{
				if( (p1||p2) || (p3||p4) )
				{
					ans=1;
					if(ans<min)
					min=ans;
				}
				l1=(a[j].y-a[i].y+a[i].x);
				m1=(a[i].x-a[j].x+a[i].y);
				s1=(a[j].y-a[i].y+a[j].x);
				d1=(a[i].x-a[j].x+a[j].y);
				
				int p5=binary_search(i+1,j-1,l1,m1);
				int p6=binary_search(j+1,n-1,l1,m1);
				int p7=binary_search(i+1,j-1,s1,d1);
				int p8=binary_search(j+1,n-1,s1,d1);
		//		cout<<l1<<" "<<m1<<" --- "<<s1<<" "<<d1<<endl;
		//		cout<<p5<<" "<<p6<<" --- "<<p7<<" "<<p8<<endl;
				if( (p5||p6) && (p7||p8) )
				{
					ans=0;
					min=0;
					found=1;
					break;
				}
				else if( (p5||p6) || (p7||p8) )
				{
					ans=1;
					if(ans<min)
					min=ans;
				}
				else
				{	ans=2;
					if(ans<min)
					min=ans;
				}	
			}
		}
		if(found==1)
		break;				
	}
	cout<<min;
	return 0;
}	
