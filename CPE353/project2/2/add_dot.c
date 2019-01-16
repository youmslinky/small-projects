#include<stdio.h>

int a[]={5,5,-4};
int b[]={1,2,3};

int dot_product(int*,int*,int);
void vec_add(int*,int*,int*,int);
void print_array(int*,int);

int main(){
	int len = sizeof(a)/sizeof(int);
	int c[len];
	printf("Input Array A: ");
	print_array(a,len);
	printf("\n");

	printf("Input Array B: ");
	print_array(b,len);
	printf("\n");

	vec_add(a,b,c,len);
	printf("Sum of the arrays: ");
	print_array(c,len);
	printf("\n");

	printf("Dot Product of the arrays: %d\n",dot_product(a,b,len));

	//printf("length of array is: %d\n",sizeof(b)/sizeof(int));
	//printf("arrays added together: %d",vec_add(a,b,c,len));

	return 0;
}
void print_array(int *a,int len){
	printf("[");
	for(int i=0;i<len-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d]",a[len-1]);
}

int dot_product(int *a,int *b,int len){
	int result = 0;
	for(int i=0;i<len;i++){
		result += a[i]*b[i];
	}
	return result;
}

void vec_add(int *a,int *b,int *c,int len){
	for(int i=0;i<len;i++){
		c[i] = a[i]+b[i];
	}
}
