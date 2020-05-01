#include<stdio.h>
int main()
{
int i,j,N;
scanf("%d",&N);
while(N--)
{
scanf("%d %d",&i,&j);
if((i==j)&&(i%2==0))
printf("%d",i+j);
else if((i==j)&&(i%2==1))
printf("%d",i+j-1);
else if((i==j+2)&&(i%2==0))
printf("%d",i+j);
else if((i==j+2)&&(i%2==1))
printf("%d",i+j-1);
else
printf("No Number");
}
return 0;
}
