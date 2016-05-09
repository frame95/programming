#include <stdio.h>
#include "dllist.h"
#define TRUE 1
#define FALSE 0

typedef dllist queue;

queue queue_init() {
	return dllist_init();
	}

void queue_insert(int k, queue * Q) {
	dllist_insert_end(k,Q);
	return;
}

int queue_remove(queue *Q) {	
	return dllist_remove_start(Q);
	}
	
void queue_print(queue Q, FILE* out, int hr) {
	dllist_print(Q, out, hr);
	return;
}

int queue_is_empty(queue Q) {
	return (Q.size==0)?TRUE:FALSE;
	}
