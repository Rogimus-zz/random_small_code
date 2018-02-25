#include <stdio.h>
#include <stdlib.h>

void pointerchange(int *m);

int
main(int argc, char *argv[]) {
	int x=2;
	pointerchange(&x);
	printf("%d\n",x);
}

void pointerchange(int *m){
	*m=4;
}

