#include <stdio.h>

int main(void) {
	int x = 5;
	funcao(&x);	
	printf("\nDepois da funcao: %d", x);
}

void funcao(int *x) {
	(*x)--;
	printf("Dentro da funcao = %d", *x);
}

