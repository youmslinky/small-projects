#include<stdio.h>
#include<limits.h>
#include<float.h>

#define COL_WIDTH 25

char types[][30]  = {
	"char",
	"short int",
	"int",
	"long int",
	"long long int",
	"unsigned char",
	"unsigned short int",
	"unsigned int",
	"unsigned long int",
	"unsigned long long int",
	"float",
	"double"
};
/*
int sizes[] ={
	sizeof(char),
	sizeof(short int),
	sizeof(int),
	sizeof(long int),
	sizeof(long long int),
	sizeof(unsigned char),
	sizeof(unsigned short int),
	sizeof(unsigned int),
	sizeof(unsigned long int),
	sizeof(unsigned long long int),
	sizeof(float),
	sizeof(double)
};
*/

void repeat_print(char c, int n);
unsigned long long expon(int,int);
unsigned long long max_unsigned(int);
unsigned long long max_signed(int);
long long min_signed(int);

int main(){
	//char titleFormatString[150];
	//char signedColumnFormatString[150];
	//char floatColumnFormatString[150];
	//snprintf(titleFormatString,150,"|%%-%ds|%%-%ds|%%-%ds|%%-%ds|\n",COL_WIDTH,COL_WIDTH,COL_WIDTH,COL_WIDTH);
	//snprintf(signedColumnFormatString,150,"|%%-%ds|%%-%dd|%%-%dlld|%%-%dllu|\n",COL_WIDTH,COL_WIDTH,COL_WIDTH,COL_WIDTH);
	//snprintf(floatColumnFormatString,150,"|%%-%ds|%%-%dd|%%-%de|%%-%de|\n",COL_WIDTH,COL_WIDTH,COL_WIDTH,COL_WIDTH);
	//printf("%s\n",titleFormatString);
	//printf("%s\n",signedColumnFormatString);
	//printf("%s\n",floatColumnFormatString);

	char titleFormatString[]        = "|%-25s|%-16s|%-21s|%-21s|\n";
	char signedColumnFormatString[] = "|%-25s|%-16d|%-21lld|%-21llu|\n";
	char floatColumnFormatString[]  = "|%-25s|%-16d|%-21e|%-21e|\n";

	repeat_print('-',25+16+21+21+5);
	printf(titleFormatString,"Data Type","Size (in bytes)","Minium","Maximum");
	repeat_print('-',25+16+21+21+5);

	//for(int i=0;i<5;i++){
	//	printf(signedColumnFormatString,types[i],sizes[i],max_signed(sizes[i]),expon(2,sizes[i]*8));
	//}
	//for(int i=5;i<11;i++){
	//	printf(unsignedColumnFormatString,types[i],sizes[i],0,max_unsigned(sizes[i]));
	//}
	
	//signed values
	printf(signedColumnFormatString,types[0],sizeof(char),			(long long)SCHAR_MIN,SCHAR_MAX);
	printf(signedColumnFormatString,types[1],sizeof(short int),		(long long)SHRT_MIN, SHRT_MAX);
	printf(signedColumnFormatString,types[2],sizeof(int),			(long long)INT_MIN,	 INT_MAX);
	printf(signedColumnFormatString,types[3],sizeof(long int),		(long long)LONG_MIN, LONG_MAX);
	printf(signedColumnFormatString,types[4],sizeof(long long int),	(long long)LLONG_MIN,LLONG_MAX);

	//unsigned values
	printf(signedColumnFormatString,types[5],sizeof(unsigned char),			0,UCHAR_MAX);
	printf(signedColumnFormatString,types[6],sizeof(unsigned short int),	0,USHRT_MAX);
	printf(signedColumnFormatString,types[7],sizeof(unsigned int),			0,UINT_MAX);
	printf(signedColumnFormatString,types[8],sizeof(unsigned long int),		0,ULONG_MAX);
	printf(signedColumnFormatString,types[9],sizeof(unsigned long long int),0,ULLONG_MAX);

	//floating point formats
	printf(floatColumnFormatString,types[10],sizeof(float),	FLT_MIN,FLT_MAX);
	printf(floatColumnFormatString,types[11],sizeof(double),DBL_MIN,DBL_MAX);

	repeat_print('-',25+16+21+21+5);
	return 0;
}

void repeat_print(char c, int n){
	for(int i=0;i<n;i++){
		printf("%c",c);
	}
	printf("\n");
}

unsigned long long max_unsigned(int bytes){
	return expon(2,bytes*8);
}

unsigned long long max_signed(int bytes){
	return expon(2,bytes*8)/2-1;
}

long long min_signed(int bytes){
	return (long long)-expon(2,bytes*8)/2;
}

unsigned long long expon(int n,int e){
	if(e==0){
		return 1;
	}
	unsigned long long result = n;
	for(int i=1;i<e;i++){
		result *= n;
	}
	return result;
}
