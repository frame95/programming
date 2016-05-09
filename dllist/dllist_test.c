#include <stdio.h>
#include "dllist.h"
#define TRUE 1
#define FALSE 0

int main() {
	dllist L = dllist_init();
	//INSERIMENTO INIZIALE: testare almeno tre volte per coprire tutti i casi.
	int control=0;
	printf("Scrivi i numeri che vuoi inserire all'inizio della lista (-1 per proseguire):\n");
	while(control != -1) {
		scanf("%d", &control);	
		if(control != -1) {
			dllist_insert_start(control, &L);
		}
	}
	
	//STAMPA
	dllist_print(L, stdout, TRUE);
	getchar();
	
	// ELIMINAZIONE INIZIALE:
	while(L.size > 0) {
		getchar();
		printf("Elimino %d.\n", dllist_remove_start(&L));
		dllist_print(L,stdout,TRUE);	
	}
	
	//INSERIMENTO FINALE: testare almeno tre volte per coprire tutti i casi.
	control=0;
	printf("Scrivi i numeri che vuoi inserire alla fine della lista (-1 per proseguire):\n");
	while(control != -1) {
		scanf("%d", &control);	
		if(control != -1) {
			dllist_insert_end(control, &L);
		}
	}
	
	dllist_print(L,stdout,TRUE);
	getchar();
	
	// RICERCA 
	control=0; dllist_el *iterator;
	while(control != -1) {
		printf("Scrivi il numero che vuoi cercare nella lista (-1 per proseguire):\n");
		scanf("%d", &control);	
		if(control != -1) {
			iterator = dllist_search(control, L);
			if(iterator == NULL) {
				printf("Elemento non trovato.\n");
				getchar();
			} else {
				printf("Elemento trovato.\n");
				getchar();
			}
		}
	}
	
	// ELIMINAZIONE FINALE:
	while(L.size > 0) {
		getchar();
		printf("Elimino %d.\n", dllist_remove_end(&L));
		dllist_print(L,stdout,TRUE);	
	}
	
	// INSERIMENTO DENTRO
	control=0; int temp;
	while(control != -1) {
		printf("Scrivi il numero che vuoi inserire (-1 per proseguire):\n");
		scanf("%d", &control);	
		if(control != -1) {
			printf("Scrivi il numero dopo cui vuoi inserirlo \n(in caso di molteplicità, dopo il primo | -2 per inserire all'inizio):\n");
			scanf("%d", &temp);
			if (temp == -2) {
				dllist_insert(control,NULL,&L);
			} else {
				iterator = dllist_search(temp, L);
				if(iterator == NULL) {
					printf("Impossibile inserire dopo %d: elemento non trovato.\n", temp);
					getchar();
				} else {
					dllist_insert(control, iterator, &L);
				}
			}
		}
		dllist_print(L,stdout, TRUE);
	}
	
	// ELIMINAZIONE DENTRO
	control=0;
	while(control != -1) {
		printf("Scrivi il numero che vuoi eliminare (-1 per proseguire):\n");
		scanf("%d", &control);	
		if(control != -1) {
			iterator = dllist_search(control, L);
			if(iterator == NULL) {
				printf("Impossibile eliminare %d: elemento non trovato.\n", control);
				getchar();
			} else {
				dllist_remove(iterator, &L);
			}
		}
		dllist_print(L,stdout, TRUE);
	}
	return 0;
}
