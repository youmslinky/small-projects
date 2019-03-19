#include <stdio.h>
#include <string.h>

//int split(char inString[],char **splitStrings);
int split(char inString[],char first[], char second[],char *strings[]);

int main(){
	char *sourceString = "cat file.txt";
	char destString[100];
	strcpy(destString,sourceString);
	printf("copied string: %s\n",destString);

	char strings[10][40];
	char f[40];
	char s[40];
	split(destString,f,s,strings);
	printf("first string: %s\n",f);
	printf("first string passed as array: %s\n",strings[0]);
	printf("second string: %s\n",s);
	printf("\n");
	return 0;
}

int split(char inString[],char first[], char second[],char *strings[]){
	char *strStart = inString;
	char *in = inString;
	int strNum = 0;
	while(*in != 0){
		printf("%c",*in);
		if(*in == ' '){
			*in = 0;
			strcpy(first,strStart);
			strcpy(strings[0],strStart);
			strcpy(second,in+1);
			strStart = in+1;
		}
		in++;
	}
	return strNum+1;
}
