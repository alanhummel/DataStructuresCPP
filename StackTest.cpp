
#include <stdio.h>
#include "Stack.h"

int main() {
	Stack<int> *stack = new Stack<int>;
	
	int numero = 1;

	stack->put(numero);

	numero = 2;
	stack->put(numero);

	numero = 3;
	stack->put(numero);

	printf("Stacked, 1, 2 and 3, now removing...\n");
	while (!stack->isEmpty()) {
		printf("\n%d\n",stack->accessTop());
		stack->remove();
	}
	delete stack;
	return 0;
}

