#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERIFY 0

void selection(int A[], int n);
void swap(int A[], int i, int j);
int main(int argc, char *argv[]){
	int i;
	int MAX_ELS;
	MAX_ELS = atoi(argv[argc-1]);
	int A[MAX_ELS];
	srand(time(NULL));
	
	int j;
	for(j=0;j<MAX_ELS;j++){
		A[j] = rand();	
	}
	
	selection(A, MAX_ELS);

	if(VERIFY){
		for (i=0;i<MAX_ELS;i++){
			printf("A[%5d] = %d\n", i, A[i]);
		}
	}
	return 0;
}
void swap(int A[], int i, int j){
	int tmp;
	tmp = A[i];
	A[i]=A[j];
	A[j]=tmp;
	return;
}

void selection(int A[], int n) {
	int i,j, min;
	for (i=0; i<n; i++) {
		min=i;
		for (j=i+1; j<n; j++){
			if(A[j]<A[min]){
				min=j;
			}		
			swap(A,i,min);
		}
	}
}
