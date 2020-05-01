#include<stdio.h>
#include<string.h>
#include<limits.h>
#define M 100009
int l[M],i,a[100],b[100],p,x,y,z,j,c,k;
char s[M];

int min(int a,int b)
{
if(a>b)
return b;
else
return a;
}


int main()
{
scanf("%s",s);
p=strlen(s);
l[0]=0;
l[-1]=INT_MAX;
//printf("%d\n",l[-1]);
for(k=48;k<=57;k++)
{
 a[k]=-1;
 b[k]=-1;
}
a[s[0]]=0;
for(i=1;i<p;i++)
{
  if(a[s[i]]==-1)
     {
        a[s[i]]=i;
        l[i]=l[i-1]+1;
     }
  else
    {
        x=l[a[s[i]]];
        y=l[i-1];
        z=min(x,y);
        l[i]=z+1;
//printf("%d %d\n",i,l[i]);
        if(z==y && x!=y)
          {
            a[s[i]]=i;
          }
        
       
        else if(z==x && a[s[i]]!=(i-1))
          {   
              for(k=48;k<=57;k++)
               {
                b[k]=-1;
               }
              j=i-1;
              while(j>a[s[i]])
               {
                  if(b[s[j]]==-1)       
                    {
                      b[s[j]]=j;
                      if(l[j]>l[j+1]+1)
                        {
                         l[j]=l[j+1]+1;
                         a[s[j]]=j;
                         j--;
                        }
                       else
                        break; 
//                     printf("%d\n",l[j]);
                    }
                   else
                   {
                       
                       c=min(l[j+1],l[b[s[j]]]);
                       if(c+1<l[j])
                         {
                           l[j]=c+1;
                           if(c==l[j+1] && (s[j+1]!=s[j]))
                           a[s[j]]=j;
                            j--;                              
                         }
                         else
                         break;
                    }
                 }
           }
     }                      
 }
//for(i=0;i<p;i++)
//printf("l[%d] %d\n",i,l[i]);
printf("%d\n",l[p-1]);
return 0;
}                        

