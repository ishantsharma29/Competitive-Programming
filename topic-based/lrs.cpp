//LONGEST REPEATED SUBSTRING SUCH THAT OVERLAPPING IS NOT ALLOWED
#include<bits/stdc++.h>
#define M 100005

using namespace std;
struct node
{
char *str;
int idx;
};

int comp(struct node a,struct node b)
{
	return (strcmp(a.str,b.str)<0?1:0);
}	
int main()
{
	int i,j,x,y,count,max=INT_MIN;
	struct node suffix[M];
	string sub="";
	char t[M];
	cin>>t;
	int n=strlen(t);
	char *p=t;
	for(i=0;i<n;i++)
	{
		suffix[i].str=(p+i);
		suffix[i].idx=i;
	}		
	sort(suffix,suffix+n,comp);
	int *arr=new int[n];
	for(i=0;i<n;i++)
	{
		arr[i]=suffix[i].idx;
		cout<<arr[i]<<" ";
	}
	//cout<<*(p+2);
	for(i=0;i<n-1;i++)
	{
		string s;
		count=0;
		j=i+1;
		x=arr[i];
		y=arr[j];
		if(y<x)
		{
			while(y<arr[i] && y<n && x<n)	
			{
	        		if(*(p+x)==*(p+y))
	        		{
	        			s=s+*(p+x);
	        			count++;x++;y++;
	        		}
	        		else
	        			break;
	    	
			}
		}
		else
		{
			while(x<arr[i+1] && y<n && x<n)	
				{
	        		if(*(p+x)==*(p+y))
	        		{
	        			s=s+*(p+x);
	        			count++;x++;y++;
	        		}
	        		else
	        			break;
	    	
				}	
		}
		if(count>max)
			{
			max=count;
			sub=s;
			}
	}	
	//cout<<sub;
	int len=sub.length();
	int f=len*max;
	if(f<n)
		cout<<n;
	else
		cout<<f;	 
		
	return 0;
}				
