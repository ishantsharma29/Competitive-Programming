#include<bits/stdc++.h>

using namespace std;
#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl


	void computeLPSArray(char *pat, int M, int *lps)
	{
	    int len = 0;  // lenght of the previous longest prefix suffix
	    int i;
	 
	    lps[0] = 0; // lps[0] is always 0
	    i = 1;
	 
	    // the loop calculates lps[i] for i = 1 to M-1
	    while (i < M)
	    {
	       if (pat[i] == pat[len])
	       {
		 len++;
		 lps[i] = len;
		 i++;
	       }
	       else // (pat[i] != pat[len])
	       {
		 if (len != 0)
		 {
		   // This is tricky. Consider the example AAACAAAA and i = 7.
		   len = lps[len-1];
	 
		   // Also, note that we do not increment i here
		 }
		 else // if (len == 0)
		 {
		   lps[i] = 0;
		   i++;
		 }
	       }
 	   }
	}

	void createpalin(char *str,char *str1 , int l)
	{
		int *lps = (int *)malloc(l*sizeof(int) );
		 computeLPSArray(str1, l, lps);
		 int i=0,j=l-1,len=0,pos=0;
		 while(i<j)
		 {
		 	if(str[i]==str[j] )
		 	{
		 		i++;j--;
		 		len++;
		//		chk3(i,j,len);		 		
		 	}
		 	else
		 	{
		 		if(len!=0)
		 		{
		 			len=lps[len-1];
		 			j=l-len-1;
		 			pos=i-len;
		// 			chk4(i,len,j,pos);
		 		}	
		 		else
		 		{
		 			i++;
		 			pos=i;
		 //			chk2(i,pos);
		 		}
		 		
		 	}
		 }
		 printf("%s",str);
		 for(int i=pos-1;i>=0;i--)
		 printf("%c",str[i]);	
	}	 

int main()
{

	char str[100005],str1[100005];
	while( (scanf("%s",str ))!=EOF ) 
	{
		
		int i=0,l=0,len;
		for(l=0;str[l]!='\0';l++);
		len=l;
		l--;		
		for(i=0;l>=0;i++,l--)
		str1[i]=str[l];
		
		createpalin( str,str1,len);
		printf("\n");
		
	}
	return 0;
}			
	
	
