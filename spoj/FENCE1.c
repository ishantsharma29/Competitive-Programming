#include<stdio.h>
#include<math.h>
#define P acos(-1)
int main()
{
int L;
double f;
while(1)
 {
 scanf("%d",&L);
  if(L!=0)
  {
    f=(pow(L,2))/(2*P);
   printf("%.2f\n",f);
  }
  else
  return 0;
 }
 return 0;
}
