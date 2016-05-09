#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

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
	
dllist init_dllist() {
	dllist L;
	L.first = NULL;
	L.last = NULL;
	L.size = 0;
	return L;	
	}

int is_empty_dllist(dllist L) {
	return (L.first == NULL)?TRUE:FALSE;
}

void insert_start(int k, dllist* L) {
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

void insert_end(int k, dllist* L) {
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

int remove_start(dllist* L) {
	int r;
	if(L->size > 1) {
		dllist_el* temp = L->first->next;
		temp->prev = NULL;
		r=L->first->in;
		free(L->first);
		L->first = temp;
		L->size--; 
	} else if(L->size==1) {
		r=L->first->in;
		free(L->first);
		L->first = L->last = NULL;
		L->size = 0;
	} else {
		fprintf(stderr, "Impossibile rimuovere: lista vuota.\n");
	}
	return r;
}
	
int remove_end(dllist* L) {
	int r=-1;
	if(L->size >1) {
		dllist_el * temp = L->last->prev;
		temp->next =  NULL;
		r=L->last->in;
		free(L->last);
		L->last=temp;
		L->size--;	
	} else if (L->size == 1) {
		r=L->last->in;
		free(L->first);
		L->first = L->last = NULL;
		L->size = 0;
	} else {
		fprintf(stderr, "Impossibile rimuovere: lista vuota.\n");
	}
	return r;
}

void write_dllist(dllist L, FILE* out, int hr) {
	if(hr) fprintf(out, "LISTA:\n"); 
	
	dllist_el * iterator = L.first;
	while(iterator != NULL) {
		fprintf(out, "%d\n", iterator->in); 
		if(hr && (iterator->next != NULL)) fprintf(out, "|\n");
		iterator = iterator->next;
	} 
	return;
}

dllist_el* search_dllist(int k, dllist L) {
	dllist_el* iterator = L.first;
	while(iterator != NULL) {
		if(iterator -> in == k) return iterator;
		iterator = iterator ->next;	
	}
	return NULL;	
}
