#include "LinkedList.h"
#include <stdio.h>
//#include "ListaDupLig.h"

int main() {
	LinkedList<int> *list = new LinkedList<int>;
	int numero = 0;
	list->addAtTail(numero);
	numero = 2;
	list->addAtTail(numero);
	numero = 4;
	list->addAtTail(numero);

	list->moveToHead();
	while(list->isValid()) {
		printf("\n%d\n",list->getItem());
		list->moveForward();
	}
	delete list;
	return 0;
}

