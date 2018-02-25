#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VERIFY 0

void quicksort(int *A, int n);
void swp(int *A, int n, int k);
int
main(int argc, char *argv[]){
	int MAX_ELS;
	MAX_ELS = atoi(argv[argc-2]);
	int A[MAX_ELS];
	int seed;
	seed = atoi(argv[argc-1]);
	//srand(time(NULL));
	srand(seed);

	int j;
	for(j=0;j<MAX_ELS;j++){
		A[j] = rand();
	}
	
	quicksort(A,MAX_ELS);
	
	if(VERIFY){
		int i;
		for(i=0; i<MAX_ELS; i++){
			printf("A[%4d] = %d\n", i, A[i]); 
		}
	}
	return 0;
}

void
quicksort (int *A, int n) {
	int i;
	/* base case. If the list contains only 1 element then it's already 
	sorted */	
	if(n==1){
		return;
	}
	
	/* main loop -- pics the first element to be the the wall before sorting 	items to the left and right of the wall depending on their size (< left, 	> right. N.B. if an element is the same size of the wall, it will be 
	left on the right side. 
	*/
	int wall_loc;
	wall_loc = 0;
	for(i=0;i<n;i++) {
		if(A[wall_loc]>A[i]){
			swp(A,i,wall_loc+1);
			swp(A,wall_loc,wall_loc+1);
			wall_loc++;
		}
	}
	
	/* make sure the wall isn't the first element before sorting
	   the elements before the wall  
	*/	
	if(wall_loc) {	
		quicksort(A,wall_loc);
	}
	/* make sure the wall isn't the last element before sorting the
	   elements after the wall
	*/
	if(wall_loc < n-1) {
		quicksort(A+wall_loc+1,n-wall_loc-1);
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
