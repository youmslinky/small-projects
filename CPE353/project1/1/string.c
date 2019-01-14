#include<stdio.h>
#include<stdbool.h>

bool isLower(char c){ return c>='a' && c<='z'; }
bool isUpper(char c){ return c>='A' && c<='Z'; }
bool isNumeral(char c){ return c>='0' && c<='9'; }

char msg[]="Welcome to CPE 325 in Spring 2019!";

int main(){
	char *ptr = msg;
	int lower=0,upper=0,numeral=0,special=0;
	while(*ptr != 0){
		if(isLower(*ptr)){ 
			printf("%c is lower\n",*ptr);
			lower++;
		}
		else if(isUpper(*ptr)){
			printf("%c is upper\n",*ptr);
			upper++;
		}
		else if(isNumeral(*ptr)){
			printf("%c is numeral\n",*ptr); 
			numeral++;
		}
		else {
			printf("%c is a special char\n",*ptr); 
			special++;
		}
		*ptr++;
	}
	printf("String: %s\n",msg);
	printf("Contains: %d digits, %d special characters, %d upper case letters, and %d lower case letters\n",numeral,special,upper,lower);
	return 0;
}

