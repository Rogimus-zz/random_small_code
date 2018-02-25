#include <stdlib.h>
#include <stdio.h>

double sum_sequence(int n);
int main(int argc, char *argv[]) {
	printf("%lf\n", sum_sequence(3));
}

double sum_sequence(int n){
	int i, denom=-1;
	double sum=0;
	for(i=1;i<=2*n;i++){
		denom*=-1;
		sum+=denom*1.0/(i*i);
	}
	return sum;
}
