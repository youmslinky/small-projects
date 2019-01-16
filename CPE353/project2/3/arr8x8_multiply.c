#include<stdio.h>
#define S 8 //size of the arrays used (must be square NxN)

int a[S][S]={
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,5,6,7,8}
};
int b[S][S]={
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1}
};

int dot_product(int*,int*,int);
void vec_add(int*,int*,int*,int);
void print_vec(int*,int);
void transpose(int[S][S],int[S][S],int len);
void print_matrix(int m[S][S]);
void multiply_matrices(int a[S][S],int b[S][S],int c[S][S]);

int main(){
	//int len = sizeof(a)/sizeof(int);
	int c[S][S];

	printf("input matrix a:\n");
	print_matrix(a);
	printf("\n");
	printf("input matrix b:\n");
	print_matrix(b);
	printf("\n");


	printf("a*b:\n");
	multiply_matrices(a,b,c); //c = a*b
	print_matrix(c);

	return 0;
}
void multiply_matrices(int a[S][S],int b[S][S],int c[S][S]){
	int bT[S][S]; //tranpose of b
	transpose(b,bT,S); //transpose to easily iterate when multiplying
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			c[i][j] = dot_product(bT[j],a[i],S);
		}
	}
}

void transpose(int src[S][S],int dest[S][S],int len){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			dest[i][j] = src[j][i];
		}
	}
}
void print_matrix(int m[S][S]){
	for(int i=0;i<S;i++){
		print_vec(m[i],S);
		printf("\n");
	}
}

void print_vec(int *a,int len){
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
