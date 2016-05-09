#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

typedef struct pair{
	int length;
	int prev;
	}pair;
	
pair ** shortest(graph G) {
	int i,j,h;
	pair **sp;
	pair **temp;
	sp = (pair**)malloc(G.n*sizeof(pair*));
	temp =(pair**)malloc(G.n*sizeof(pair*));
	for(i=0;i<G.n;i++) {
		sp[i] = (pair*)malloc(G.n*sizeof(pair));
		temp[i]=(pair*)malloc(G.n*sizeof(pair));
	}	
	
	for(i=0;i<G.n;i++) {
		for(j=0;j<G.n;j++) {
			temp[i][j].length = sp[i][j].length = G.weight[i][j];
			temp[i][j].prev = sp[i][j].prev =i;
		}
	}
	
	
	for(h=0; h<G.n;h++) {
		for(i=0;i<G.n;i++) {
			for(j=0;j<G.n;j++) {
				if(sp[i][h].length + sp[h][j].length < sp[i][j].length ) {
					temp[i][j].prev = h;
					temp[i][j].length = sp[i][h].length + sp[h][j].length;
				} 
			}
		}
		for(i=0;i<G.n;i++) {
			for(j=0;j<G.n;j++) {
				sp[i][j].prev = temp[i][j].prev;
				sp[i][j].length = temp[i][j].length;
			}
		}
	}
	return sp;
}



int main() {
	int i,j,c;
	FILE *fin;
	fin = fopen("input.txt", "r");
	graph G;
	getchar();
	//rand_fill(&G, 10);
	read_graph(&G, fin);
	getchar();
	write_graph(G,stdout, TRUE);
	getchar();
	pair **result = shortest(G);
	dllist Q=init_dllist();
	while(1) {
		printf("Inserisci i j, i nodi di cui vuoi conoscere il min path:\n");
		scanf("%d %d", &i, &j);
		if(result[i][j].length == 269488144) {
			printf("I nodi non sono collegati.\n");
			getchar();
		} else {
			printf("Lunghezza minima: %d\n", result[i][j].length);
			getchar();
			c=j;
			while( c!=i) {
				insert_end(c, &Q);
				c=result[i][c].prev;
			}
			insert(i,&Q);
			while( !(is_empty_queue(Q)) ) {
				getchar();
				printf("%d\n", remove_end(&Q));
			}
			getchar();
		}
		
	}
	return 0;
}
