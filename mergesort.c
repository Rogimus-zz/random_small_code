#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VERIFY 0

void mergesort(int *A, int n);
void swp(int *A, int n, int k);
int
main(int argc, char *argv[]){
	int MAX_ELS;
	MAX_ELS = atoi(argv[argc-1]);
	int A[MAX_ELS];
	srand(time(NULL));

	int j;
	for(j=0;j<MAX_ELS;j++){
		A[j] = rand();
	}
	
	mergesort(A,MAX_ELS);
	
	if(VERIFY){
		int i;
		for(i=0; i<MAX_ELS; i++){
			printf("A[%4d] = %d\n", i, A[i]); 
		}
	}
	return 0;
}

void
mergesort(int *A, int n){
	int i;
	for(i=1;i<=n;i++){
		
	}
}

void 
swp(int *A, int n, int k) {
	int tmp;
	tmp = A[n];
	A[n] = A[k];
	A[k] = tmp;
	return;
}
