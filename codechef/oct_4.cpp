#include<bits/stdc++.h>
using namespace std;

int  main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int r,g,b,m,i,x;
		int max_r=INT_MIN;
		int max_g=INT_MIN;
		int max_b=INT_MIN;
		int glob_min=INT_MAX;
		cin>>r>>g>>b>>m;
		for(i=0;i<r;i++)
		{
			cin>>x;
			//cout<<x<<endl;
			if(x>max_r)
			{
				max_r=x;
				//cout<<"1 "<<max_r<<endl;
			}
		}
		for(i=0;i<g;i++)
		{
			cin>>x;
			//cout<<x<<endl;
			if(x>max_g)
			{
				max_g=x;
				//cout<<"2 "<<max_g<<endl;
			}
		}		
		for(i=0;i<b;i++)
		{
			cin>>x;
			if(x>max_b)
			{
				max_b=x;
			//	cout<<"3 "<<max_b<<endl;
			}
		}
		for(i=0;i<=m;i++)
		{
			if(max_r>max_g)
			{
				if(max_r>max_b)
				{
					if(max_r<glob_min)
					{
	                                 	glob_min=max_r;
	                                 }
	                                 max_r=(max_r/2);
	                         }
	                         else
	                         {
	                         	if(max_b<glob_min)
					{
	                                 	glob_min=max_b;
	                                 }
	                                 max_b=(max_b/2);
	                          }
	                 }                
	                 else
	                 {
				if(max_g>max_b)
				{
					if(max_g<glob_min)
					{
	                                 	glob_min=max_g;
	                                 }
	                                 max_g=(max_g/2);
	                         }
	                         else
	                         {
	                         	if(max_b<glob_min)
					{
						
	                                 	glob_min=max_b;
	                              //   	cout<<"max_b  "<<max_b<<endl;
	                                 }
	                                 max_b=(max_b/2);
	                                // cout<<"max_b  "<<max_b<<endl;
	                          }
	                 } 
	             //    cout<<"3 "<<max_b<<"  2 "<<max_g<<"  1 "<<max_r<<endl;
	        }                        
					
		cout<<glob_min<<endl;
	}
	return 0;
}				
