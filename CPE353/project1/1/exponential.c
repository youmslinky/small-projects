#include<stdio.h>
long expon(long,long);

int main(){
	long e=3;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%ld raised to the power %ld is %ld\n",i,j,expon(i,j));
		}
	}
	return 0;
}

long expon(long n,long e){
	if(e==0){
		return 1;
	}
	long result = n;
	for(int i=1;i<e;i++){
		result *= n;
	}
	return result;
}
