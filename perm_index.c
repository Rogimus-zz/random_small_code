#include <stdlib.h>
#include <stdio.h>

#define DIAG 0

double pal(int A[], int n);
int
main( int argc, char *argv[]) {
	int A[]={1,2,1,1,2,2,4,4,2,2,1,5,4,4,3};
	int j;
	j=pal(A,14);	
	printf("the permutation_index of A = %d\n", j);
}

double pal(int A[], int n) {
	int i,j;
	int counter=0, max=0;

	if(n==2 && A[0]==A[1]) {
		return 2;
	} else if (n==2) {
		return 0;
	}

	for (i=1;i<n;i++){
		for (j=i;j<n;j++){
			counter = pal(A+i,n-j-1);
			if (counter > max) {
				max=counter;
				if (max == n-2) {
					break;
				}
			}
		}
	}	

/* diagnostics */
	if (DIAG) {
		for(i=0;i<n;i++) {
			printf("A[%d]=%d, ",i,A[i]);
		}
		printf(" max = %d\n", max);	
	}
/* if all the elements between the first and last element are palindromic
	the check if the first and last element are the same */
	if (max==n-2 && A[0]==A[n-1]){
		/* if they are */
		return max+2;
	}
	/* if they aren't */
	return max;
}
