#include<stdio.h>
#define M 1001
int n(int a)
{
    if(a==2||a==4||a==6||a==9||a==11)
        return 0;
    else
        return 1;
}
int isleap(int r)
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
struct code
{
int d;
int m;
int y;
int c;
}s[M];
int N,i,d,f,e;
long long p;
int main()
{
 while(1)
 {
  scanf("%d",&N);
  if(!N)
  return 0;
  else
  {p=0;d=0;
  for(i=0;i<N;i++)
  scanf("%d %d %d %d",&s[i].d,&s[i].m,&s[i].y,&s[i].c);
  for(i=1;i<N;i++)
  {
      f=isleap(s[i].y);
      e=n(s[i-1].m);
          if(s[i-1].y==s[i].y)
          {
              if(s[i].m==s[i-1].m&&(s[i-1].d+1)==s[i].d)
              {
                  d++;
                  p=p+s[i].c-s[i-1].c;
              }
              if(s[i].m==(s[i-1].m+1)&&s[i].d==1)
              {
                  if(e==1&&s[i-1].d==31)
                    {
                        d++;
                        p=p+s[i].c-s[i-1].c;
                    }
                  if(e==0&&s[i-1].d==30)
                  {
                      d++;
                      p=p+s[i].c-s[i-1].c;
                  }
                   if(s[i-1].d==28&&f==0&&s[i-1].m==2)
                  {
                      d++;
                      p=p+s[i].c-s[i-1].c;
                  }
                  if(s[i-1].d==29&&f==1&&s[i-1].m==2)
                  {
                      d++;
                      p=p+s[i].c-s[i-1].c;
                  }

              }
          }
            else
            {
                if(s[i].d==1&&s[i-1].d==31&&s[i].m==1&&s[i-1].m==12&&(s[i-1].y+1==s[i].y))
                  {
                   d++;
                    p=p+s[i].c-s[i-1].c;
                  }
            }
     }
  printf("%d %lld\n",d,p);
  }
 }
return 0;
}
