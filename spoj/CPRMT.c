#include<stdio.h>
#include<string.h>
#define M 1001
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
 }
char B[26],C[26];
char str1[M],str2[M];
char A[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
int i,j;
while((scanf("%s",str1))!=EOF)
{

 scanf("%s",str2);
 for(i=0;i<26;i++)
    {
        B[i]=0;
        C[i]=0;
    }
 for(i=0;i<strlen(str1);i++)
 {
   B[(int)str1[i]-97]++;
 }
 for(j=0;j<strlen(str2);j++)
 {
   C[(int)str2[j]-97]++;
 }

 for(i=0;i<26;i++)
 {
 if (B[i]!=0 && C[i]!=0)
  {
   int c=min(B[i],C[i]);
   for(j=1;j<=c;j++)
   printf("%c",A[i]);
  }
 }
 printf("\n");
 }
 return 0;
}
