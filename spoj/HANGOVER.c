#include<stdio.h>
#include<stdlib.h>
int main()
{
 float c,s;
 int i,j;
while( scanf("%f",&c))
{
     if(c==0.00)
  break;

     s=0.00;
     i=2;
     while(1)
     {
          s=s+(1.00/(float)i);
    if(s>=c)
       {
          printf("%d card(s)\n",i-1);
        break;
       }
       i++;
     }

}
return 0;
}
