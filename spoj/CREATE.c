#include <stdio.h>
#include<string.h>
#define k 10010
char s1[k],s2[k];
int i,t,j;
int main()
{
scanf("%d\n",&t);//WHEN USING A GETS FUNCTION IN C, A NEWLINE CHARACTER IS REQUIRED IN SCANF FUNCTION USED JUST ABOVE IT
while(t--)
{j=0;
gets(s1);
gets(s2);
for(i=0;i<strlen(s2);i++)
{
    if(s2[i]==s1[0])
      {j=0;
         while(i<strlen(s2)&&j<strlen(s1))
           {
             if(s2[i]==s1[j])
               {  i++;
                  j++;
                  continue;
               }
             else
             break;
           }
      }
   if(j==strlen(s1))
   {
   	printf("possible\n");
    break;
   }
}
if((i==strlen(s2))&&(j<strlen(s1)))
printf("not possible\n");
}

	return 0;
}
/*#include <stdio.h>
#include <string.h>


int main()
{
   const char haystack[20] = "TutorialsPoint";
   const char needle[10] = "Point";
   char *ret;

   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);

   return(0);
}*/
