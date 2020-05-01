#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	string s;
	scanf("%d",&n);
	cin>>s;
	char ch;
	for(i=0;i<2*n;i+=2)
	{
		if(s[i]=='A' && s[i+1]=='B'||s[i]=='B' && s[i+1]=='A' )// && ch=='C"
		{
			if(ch=='C' && i!=0)
			{
				cout<<"D";
				cout<<"C";
				ch='C';
			}	
			else if(ch=='D' && i!=0)
			{
				cout<<"C";
				cout<<"D";
				ch='D';
			}
			else
			{
				cout<<"D";
				cout<<"C";
				ch='C';
			}
		}
		else if(s[i]=='A' && s[i+1]=='C'||s[i]=='C' && s[i+1]=='A' )// && ch=='C"
		{
			if(ch=='B' && i!=0)
			{
				cout<<"D";
				cout<<"B";
				ch='B';
			}	
			else if(ch=='D' && i!=0)
			{
				cout<<"B";
				cout<<"D";
				ch='D';
			}
			else
			{
				cout<<"B";
				cout<<"D";
				ch='D';
			}
		}
		else if(s[i]=='A' && s[i+1]=='D'||s[i]=='D' && s[i+1]=='A' )// && ch=='C"
		{
			if(ch=='C' && i!=0)
			{
				cout<<"B";
				cout<<"C";
				ch='C';
			}	
			else if(ch=='B' && i!=0)
			{
				//cout<<'B';
				cout<<"C";
					cout<<"B";
				ch='B';				
			}
			else
			{
				//cout<<'B';
				//cout<<'C';
					cout<<"B";
				cout<<"C";
				ch='C';
			}
		}
		else if(s[i]=='C' && s[i+1]=='B'||s[i]=='B' && s[i+1]=='C' )// && ch=='C"
		{
			if(ch=='A' && i!=0)
			{
				cout<<"D";
				cout<<"A";
				ch='A';
			}	
			else if(ch=='D' && i!=0)
			{
				//cout<<'D';
				cout<<"A";
					cout<<"D";
				//cout<<"A";
				ch='D';
			}
			else
			{
				//cout<<'D';
				//cout<<'A';
					cout<<"D";
				cout<<"A";
				ch='A';
			}
		}
		else if(s[i]=='D' && s[i+1]=='B'||s[i]=='B' && s[i+1]=='D' )// && ch=='C"
		{
			if(ch=='C' && i!=0)
			{
				cout<<"A";
				cout<<"C";
				ch='C';
			}	
			else if(ch=='A' && i!=0)
			{
				//cout<<'A';
				cout<<"C";
					cout<<"A";
				//cout<<"C";
				ch='A';
			}
			else
			{
				//cout<<'A';
				//cout<<'C';
					cout<<"A";
				cout<<"C";
				ch='C';
			}
		}
		else if(s[i]=='D' && s[i+1]=='C'||s[i]=='C' && s[i+1]=='D' )// && ch=='C"
		{
			if(ch=='B' && i!=0)
			{
				cout<<"A";
				cout<<"B";
				ch='B';
			}	
			else if(ch=='A' && i!=0)
			{
				//cout<<'A';
				cout<<"B";
				cout<<"A";
				ch='A';
				//cout<<"B";
			}
			else
			{
				//cout<<'A';
				//cout<<'B';
				cout<<"A";
				cout<<"B";
				ch='B';
			}
		}
	}
	cout<<endl;
	return 0;
}			
