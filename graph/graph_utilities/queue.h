#include <stdio.h>
#include "dllist.h"

typedef dllist queue;

queue init_queue() {
	return init_dllist();
	}

void insert(int k, queue * Q) {
	insert_end(k,Q);
	return;
}

int dequeue(queue *Q) {	
	return remove_start(Q);
	}
	
void write_queue(queue Q, FILE* out, int hr) {
	write_dllist(Q, out, hr);
	return;
}

int is_empty_queue(queue Q) {
	return is_empty_dllist(Q);
	}
