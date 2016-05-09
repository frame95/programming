#include <stdio.h>
#include <stdlib.h>

typedef struct dllist_el {
	int in;
	struct dllist_el* next;
	struct dllist_el* prev;
	}dllist_el;

typedef struct dllist {
	dllist_el* first;
	dllist_el* last;
	int size;
	}dllist;
	
dllist  dllist_init() {
	dllist L;
	L.first = NULL;
	L.last = NULL;
	L.size = 0;
	return L;	
	}
	
void dllist_insert_start(int k, dllist* L) {
	dllist_el* q;
	q=(dllist_el*)malloc(sizeof(dllist_el));
	q->in = k;
	q->next=L->first;
	q->prev = NULL;
	if(L->size >= 1) L->first->prev = q;
	L->first=q;
	if(L->size == 0) L->last = q;
	L->size++;
	return;
}

void dllist_insert_end(int k, dllist* L) {
	dllist_el* q;
	q = (dllist_el*)malloc(sizeof(dllist_el));
	q->in = k;
	q->next = NULL;
	q->prev = L->last;
	if(L->size >= 1) L->last->next = q;
	L->last = q;
	if(L->size == 0) L->first = q;
	L->size++;
	return;
}

int dllist_remove_start(dllist* L) {
	int result=-1;
	if(L->size > 1) {
		result = L->first->in;
		dllist_el* temp = L->first->next;
		temp->prev = NULL;
		free(L->first);
		L->first = temp;
		L->size--; 
	} else if(L->size==1) {
		result = L->first->in;
		free(L->first);
		L->first = L->last = NULL;
		L->size = 0;
	} else {
		fprintf(stderr, "Impossibile rimuovere: lista vuota.\n");
	}
	return result;
}
	
int dllist_remove_end(dllist* L) {
	int result=-1;
	if(L->size >1) {
		result = L->last->in;
		dllist_el * temp = L->last->prev;
		temp->next =  NULL;
		free(L->last);
		L->last=temp;
		L->size--;	
	} else if (L->size == 1) {
		result = L->last->in;
		free(L->first);
		L->first = L->last = NULL;
		L->size = 0;
	} else {
		fprintf(stderr, "Impossibile rimuovere: lista vuota.\n");
	}
	return result;
}

void dllist_print(dllist L, FILE* out, int hr) {
	if(hr) fprintf(out, "LISTA:\n"); 
	
	dllist_el * iterator = L.first;
	while(iterator != NULL) {
		fprintf(out, "%d\n", iterator->in); 
		if(hr && (iterator->next != NULL)) fprintf(out, "|\n");
		iterator = iterator->next;
	} 
	return;
}

dllist_el* dllist_search(int k, dllist L) {
	dllist_el* iterator = L.first;
	while(iterator != NULL) {
		if(iterator -> in == k) return iterator;
		iterator = iterator ->next;	
	}
	return NULL;	
}

void dllist_insert(int k, dllist_el* pos, dllist* L) {
	if(pos == NULL) {
		dllist_insert_start(k,L);
	} else if(pos == L->last) {
		dllist_insert_end(k,L);
	} else {
		dllist_el* temp;
		temp = (dllist_el*)malloc(sizeof(dllist_el));
		temp->in=k;
		temp->prev = pos;
		temp->next = pos->next;
		pos->next->prev =temp;
		pos->next=temp;
	}
	return;
}

int dllist_remove(dllist_el * pos, dllist * L) {
	int result = pos->in;
	if(pos == L->first) {
		dllist_remove_start(L);	
	} else if(pos == L->last) {
		dllist_remove_end(L);
	} else {
		pos->prev->next=pos->next;
		pos->next->prev=pos->prev;
		free(pos);	
	}
	return result;
}
