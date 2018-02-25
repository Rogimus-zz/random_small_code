#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quicksort(int *A, int n);
void quicksortrand(int *A, int n);
void swp(int *A, int n, int k);
int
main(int argc, char *argv[]){
	clock_t start_time, end_time;
	double total_time1, total_time2;
	total_time1=total_time2=0;

	int sims = atoi(argv[argc-1]);
	int i;
	int MAX_ELS;
	MAX_ELS = atoi(argv[argc-2]);
	int A[MAX_ELS];
	srand(time(NULL));

	int j;
	for(j=0;j<MAX_ELS;j++){
		A[j] = rand();
	}
	srand(time(NULL));
	
	for(i=0; i<sims; i++){

	start_time=clock();
	quicksort(A,MAX_ELS);
	end_time=clock();
	total_time1 += (double)(end_time-start_time);

	start_time=clock();
	quicksortrand(A,MAX_ELS);
	end_time=clock();
	total_time2 += (double)(end_time-start_time);
	}
	printf("average RT of 1EQS: %.2f\n", total_time1/CLOCKS_PER_SEC/sims);
	printf("average RT of RQS: %.2f\n", total_time2/CLOCKS_PER_SEC/sims);
	printf("CLOCKS_PER_SEC = %d\n", CLOCKS_PER_SEC);
	
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
quicksortrand(int *A, int n) {
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
	wall_loc = rand()%(n-1);
	for(i=0;i<n;i++) {
		if(wall_loc<i){
			if(A[wall_loc]>A[i]){
				swp(A,i,wall_loc+1);
				swp(A,wall_loc,wall_loc+1);
				wall_loc++;
			}
		} else {
			if(A[wall_loc]<A[i]){
				swp(A,i,wall_loc);
				wall_loc=i;
			}
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
}
