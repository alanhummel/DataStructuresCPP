
#include <stdio.h>
#include "Queue.h"

int main() {
	Queue<int> *q = new Queue<int>;

	int numero = 0;
	q->put(numero);

	numero = 1;
	q->put(numero);

	numero = 2;
	q->put(numero);

	while(!q->isEmpty()) {
		printf("\n%d\n",q->accessFirst());
		q->remove();
	}

	delete q;
	return 0;
}


