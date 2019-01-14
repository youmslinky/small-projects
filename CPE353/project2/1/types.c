#include<stdio.h>
#include<limits.h>

#define COL_WIDTH 20

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

int main(){
	char titleFormatString[100];
	char columnFormatString[100];
	snprintf(titleFormatString,100,"|%%-%ds|%%-%ds|%%-%ds|%%-%ds|\n",COL_WIDTH,COL_WIDTH,COL_WIDTH,COL_WIDTH);
	snprintf(columnFormatString,100,"|%%-%ds|%%-%dd|%%-%dzu|%%-%dzu|\n",COL_WIDTH,COL_WIDTH,COL_WIDTH,COL_WIDTH);

	printf(titleFormatString,"Data Type","Size (in bytes)","Minium","Maximum");
	printf(columnFormatString,types[0],sizeof(char),CHAR_MIN,CHAR_MAX);

	printf(columnFormatString,types[0],sizeof(char),CHAR_MIN,CHAR_MAX);
	printf(columnFormatString,types[1],sizeof(short int),SHRT_MIN,SHRT_MAX);
	printf(columnFormatString,types[2],sizeof(int),INT_MIN,INT_MAX);
	printf(columnFormatString,types[3],sizeof(long int),LONG_MIN,LONG_MAX);
	//printf(columnFormatString,types[4],sizeof(long long int),zz,zz);
	printf(columnFormatString,types[5],sizeof(unsigned char),0,UCHAR_MAX);
	printf(columnFormatString,types[6],sizeof(unsigned short int),0,USHRT_MAX);
	printf(columnFormatString,types[7],sizeof(unsigned int),0,UINT_MAX);
	printf(columnFormatString,types[8],sizeof(unsigned long int),0,ULONG_MAX);
	//printf(columnFormatString,types[9],sizeof(unsigned long long int),zz,zz);
	//printf(columnFormatString,types[10],sizeof(float),zz,zz);
	//printf(columnFormatString,types[11],sizeof(double),zz,zz);

	return 0;
}
