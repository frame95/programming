#include <stdio.h>
#include "queue.h"

//MANCA IL TEST PER LA STAMPA SU FILE

int main() {
	//INIZIALIZZAZIONE
	queue Q=queue_init();
	int control;
	
	//INSERIMENTO && STAMPA
	control=0;
	printf("Scrivi i numeri che vuoi inserire (-1 per proseguire):\n");
	while(control!=-1) {
		scanf("%d", &control);
		if(control!=-1) {
			queue_insert(control, &Q);
			queue_print(Q,stdout,TRUE);
		}
	}
	
	// STAMPA SU FILE
	printf("Salvataggio su file..\n");
	getchar();
	FILE * fout;
	fout = fopen("queue_output.txt", "w");
	queue_print(Q,fout,FALSE);
	
	//ELIMINAZIONE && IS_EMPTY
	while(!queue_is_empty(Q)) {
		getchar();
		printf("Elimino %d.\n", queue_remove(&Q));
		getchar();
		queue_print(Q,stdout,TRUE);	
	}
	printf("Test eseguito con successo!\n");
	getchar();
	return 0;
}
