#include<stdio.h>
#include<string.h>
#define k 1002
char s[k];
int i,p,q;
int main()
{
while((scanf("%s",s))!=EOF)
{p=0,q=0;
 for(i=0;i<strlen(s);i++)
 {
   if( (int)s[0]>64 && (int)s[0]<91)
	  {
         if(i%2==0)

         {

           if((int)s[i]>90)
           p++;
           else
           q++;
         }
         else
         {
             if((int)s[i]<97)
              p++;
              else
              q++;
         }
      }
   else
      {
          if(i%2==0)
          {

            if((int)s[i]<97)
            p++;
            else
            q++;
          }
         else
         {
             if((int)s[i]>90)
             p++;
             else
             q++;
         }
       }
 }
 if(q>p)
printf("%d\n",p);
else
printf("%d\n",q);
}
	return 0;
}

