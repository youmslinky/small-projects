#include <stdio.h>

int main(){
	int retValue;
	int pid;
	if(fork()==0){
		sleep(2);
		printf("Hi from child\n");
		return 2;
	}
	else{
		printf("Hi from parent\n");
		pid = wait(&retValue); //wait for child process
		return retValue;
	}
}
