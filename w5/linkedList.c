#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/ADT/SLL.h"



int main() {

	SLL *list = newSLL(sizeof(int));
	int payloads[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int nmemb = sizeof(payloads) /sizeof(payloads[0]);
	for (int i = 0; i < nmemb; i++) {
		insertAtTail(list, payloads + i);
	}

	
	return 0;
}
