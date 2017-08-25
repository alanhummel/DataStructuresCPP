
#include "DoubleLinkedList.h"
#include <stdio.h>

int main() {
	DoubleLinkedList<int>* dlist = new DoubleLinkedList<int>;
	int numero = 0;
	dlist->addAtTail (numero);
	numero = 1;
	dlist->addAtTail (numero);
	numero = 2;
	dlist->addAtTail (numero);

	dlist->moveToHead();
	while(dlist->isValid()) {
		printf("\n%d\n",dlist->getItem());
		dlist->moveForward();
	}
	
	delete dlist;

return 0;
}

