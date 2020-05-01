#include<iostream>
#include<algorithm>
using namespace std;
struct node {
int arrtime;
int burtime;
int endtime;
}a[100005];
int fun(struct node const &p,struct node const &q)
{
return (p.arrtime<q.arrtime);
}
int main()
{
int p,i;
cout << "enter the no. of processes" <<endl;
cin >> p;
cout << "enter the arrrival time and burst time of processes" << endl;
for(i=0;i<p;i++)
{
cin >> a[i].arrtime >> a[i].burtime ;
}
sort(a,a+p,fun);
int c=0;
	for(i=0;i<p;)
	{
		if(a[i].arrtime<=c)
		{
			c+=a[i].burtime;
			a[i].endtime=c;
			i++;
		}
		else
		{
			c=a[i].arrtime;
		}	
	}
	
	float asum=0,awt=0;
	cout<<"Arrival Time"<<" "<<"End Time:"<<" " <<"waiting time "<<"turnaround time "<<endl;
	int wt,sum;
	for(i=0;i<p;i++)
	{
	
		sum=a[i].endtime-a[i].arrtime;
		asum+=sum;
		wt=sum-a[i].burtime;
		awt+=wt;
	cout<<a[i].arrtime<<" "<<a[i].endtime<<" "<<wt<<" "<<sum<<endl;
	}
	cout<<"avg turn around time is="<<asum/p<<endl;
	
	cout<<"avg waiting  time is="<<awt/p<<endl;
	cout<<"Time required is="<<c;

	return 0;
}
