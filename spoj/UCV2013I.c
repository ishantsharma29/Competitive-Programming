#include<stdio.h>
#include<math.h>
#define P  acos(-1)
double r,x,y,c,z,R,N,t;
int main()
{
    while(1)
    {

        scanf("%lf %lf",&r,&N);
        if(r==0&&N==0)
             return 0;
        else if(N==0&&r!=0)
            printf("0.00\n");
        else
        {
            c=(P/N);
            x=(c*(N-1))/2;
          y=sin(x);
          z=sin(c);
          R=(2*r*y)/z;
           //t=floor(R*1000);
           //if(fmod(t,10.0)>=5)
           //R=0.01*ceil(100*R);
           //else
            //R=0.01*floor(100*R);
           printf("%.2f\n",R);
        }
    }
    return 0;
}
