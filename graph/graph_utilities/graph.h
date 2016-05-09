#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX 10000

typedef struct graph {
	int n;
	int m;
	int* deg;
	int** adj;
	int** weight;
	int type; // primo bit: directed?, secondo bit: weighted?
} graph;

graph graph_init(int n, int directed, int weighted) {
	graph G; 
	int i;
	G.type=directed + 2*weighted;
	G.n = n;
	G.m=0;
	G.deg =(int*) malloc(n*sizeof(int));
	memset(G.deg, 0, n*sizeof(int) );
	G.adj =(int**)malloc(n*sizeof(int*));
	
	if(weighted) {
		G.weight =(int**)malloc(n*sizeof(int*));
	}
	
	for(i=0;i<n;i++) {
		G.adj[i] =(int*)malloc(n*sizeof(int));
		if(weighted) {
			G.weight[i]=(int*)malloc(n*sizeof(int));
		}
		memset(G.adj[i], 0, n*sizeof(int));
		if(weighted) {
			memset(G.weight[i], MAX, n*sizeof(int));
		}
	}
	return G;
}

void graph_add_edge(graph* G, int source, int target, int weight) {
	if(G->deg[source] < G->n ) {
		G->adj[source][G->deg[source]++] = target;
		if(G->type & 2) G->weight[source][target] = weight;
		G->m++;
	} else {
		fprintf(stderr, "Impossibile aggiungere arco: lista di adiacenza piena (forse ci sono dei duplicati?).\n");
	}
	
	if( (!(G->type & 1) && source != target ) ) {
		if(G->deg[target] < G->n ) {
			G->adj[target][G->deg[target]++] = source;
			if(G->type & 2) G->weight[target][source] = weight;
			G->m++;
		}
	}
	return;
}

void graph_rand_fill(graph * G, int max_weight) {
	srand(time(NULL));
	int i,j,k,r,s,l, n=G->n;
	int taken[n];
	for(i=0; i<n; i++) {
		for(k=0; k<n; k++) taken[k] = 0;		
		s=rand() % (n-i); // Grado dell' i-esimo vertice
		for(j=0; j<s; j++) {
			if(G->type & 1) {
				do { r=rand() % n; } while (taken[r] != 0);
				if(G->type & 2) l=rand()%max_weight;
				add_edge(G, i, r, l);
				taken[r]=1;	
			} else {
				do { r=rand() % (n-i); } while (taken[r] != 0);
				if(G->type & 2) l=rand()%max_weight;
				add_edge(G, i, i+r,l);
				taken[r]=1;	
			}
		}
	}
	return;
}

// FORMATO:
// 0. directed weighted
// 1. n (numero di nodi)
// 2. m (numero di archi)
// 3. source_1 target_1 (weight_1)
// ..
// m+2. source_m target_m (weight_m)

void graph_print( graph G, FILE * out, int human_readable) {
	int i,j, n=G.n;
	if(human_readable == FALSE ) {
		fprintf(out, "%d %d\n", (G.type &1), (G.type&2));
		fprintf(out, "%d\n", G.n);
		fprintf(out, "%d\n", G.m);
		for(i=0;i<n;i++) {
			for(j=0;j<G.deg[i];j++) {
				if(G.type &1 || i <= G.adj[i][j]  ) {
					fprintf(out, "%d %d ", i, G.adj[i][j]);
					if(G.type&2) fprintf(out, "%d ", G.weight[i][G.adj[i][j]]);
					fprintf(out, "\n");
				}
			}
		}
	} else {
		fprintf(out, "DIRECTED:\t");
		if(G.type &1) fprintf(out, "YES\n");
		else fprintf(out, "NO\n");
		
		fprintf(out, "WEIGHTED:\t");
		if(G.type &2) fprintf(out, "YES\n");
		else fprintf(out, "NO\n");
		
		fprintf(out, "Numero di nodi: %d\n", G.n);
		fprintf(out, "Numero di archi: %d\n", G.m);
		for(i=0;i<n;i++) {
			fprintf(out, "%d -> ", i);
			for(j=0;j<G.deg[i];j++) {
				if(G.type & 1 || i <= G.adj[i][j]  ) {
					if(G.type&2) fprintf(out, "(%d)-", G.weight[i][G.adj[i][j]]);
					fprintf(out, "%d, ", G.adj[i][j]);
				}
			}
			fprintf(out, "\n");
		}
	}
	return;
}

void graph_read( graph *G, FILE* in) {
	int i,j,k,n,m,temp,l,t,weight;
	fscanf(in, "%d %d\n", &l,&t);
	G->type = l+2*t;
	fscanf(in, "%d\n", &G->n);
	fscanf(in, "%d\n", &m);
	*G = init_graph(n, l,t);
	n=G->n;
	for(i=0;i<m;i++) {
		fscanf(in, "%d %d", &k, &temp);
		if(t) fscanf(in, "%d", &weight);
		if(l || k <= temp  ) {
			add_edge(G, k,temp, weight);
		}  
	}
	return;
}

