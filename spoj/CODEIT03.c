#include<stdio.h>
int i,t,d,m,y,ch,f,c;
long long x;
int leap(int r)
{
    if(r%100==0)
    {
        if(r%400==0)
            return 1;
        else return 0;
    }
    else if(r%4==0)
    return 1;
    else return 0;

}
int main()
{
 scanf("%d",&t);
 while(t--)
   {c=0;
   x=0;
   ch=0;
   f=-1;
    scanf("%d %d %d",&d,&m,&y);
    for(i=2012;i<=y;i+=4)
    {
     f=leap(i);
     if(f==1)
      c++;
      f=-1;
    }
    x=((y-2012)*365)+c;
     if(m==1)
        x=x+d-10;
    else if(m==2)
        x=x+21+d;
    else if(m==3)
     x=x+49+d;
    else if(m==4)
        x=x+80+d;
    else if(m==5)
        x=x+110+d;
    else if(m==6)
        x=x+141+d;
    else if(m==7)
        x=x+171+d;
    else if(m==8)
        x=x+202+d;
    else if(m==9)
        x=x+233+d;
    else if(m==10)
        x=x+263+d;
    else if(m==11)
        x=x+294+d;
    else
        x=x+324+d;
     if(leap(y)==1&&m<=2)
     x-=1;
    ch=x%7;
      switch(ch)
      {
      case 1:printf("Wednesday\n");
             break;
      case 2:printf("Thursday\n");
             break;
      case 3:printf("Friday\n");
             break;
      case 4:printf("Saturday\n");
             break;
      case 5:printf("Sunday\n");
             break;
      case 6:printf("Monday\n");
             break;
      case 0:printf("Tuesday\n");
             break;
       }

   }
   return 0;
}
