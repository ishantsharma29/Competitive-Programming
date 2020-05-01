
#include<stdio.h>

unsigned int rev_endianness(int num) {
printf("%x\n",num);
int byte0, byte1, byte2, byte3;
byte0 = (num & 0x000000FF) >> 0 ;
printf("%x\n",byte0);
byte1 = (num & 0x0000FF00) >> 8 ;
printf("%x\n",byte1);
byte2 = (num & 0x00FF0000) >> 16 ;
printf("%x\n",byte2);
byte3 = (num & 0xFF000000) >> 24 ;
printf("%x\n",byte3);
return((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

int main()
{
	printf("Big Endian %x \n" , rev_endianness(160) );
	return 0;
}	
