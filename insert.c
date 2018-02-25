#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERIFY 0

void insert(int A[], int n);
void swap(int A[], int i, int j);
int main(int argc, char *argv[]){
	int MAX_ELS;
	MAX_ELS = atoi(argv[argc-1]);
	int i;
	int A[MAX_ELS];
	srand(time(NULL));
	
	int j;
	for(j=0;j<MAX_ELS;j++){
		A[j] = rand();	
	}
	
	insert(A, MAX_ELS);

	if(VERIFY){
		for (i=0;i<MAX_ELS;i++){
			printf("A[%5d] = %d\n", i, A[i]);
		}
	}
	return 0;
}
void insert(int A[], int n) {
	int i,j;
	for (i=1;i<n;i++){
		j=i;
		while(j>0 && (A[j]<A[j-1])){
			swap(A,j-1,j);
			j--;
		}
	}
}
void swap(int A[], int i, int j){
	int tmp;
	tmp = A[i];
	A[i]=A[j];
	A[j]=tmp;
	return;
}
