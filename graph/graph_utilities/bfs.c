#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

void visit(int k, graph G, queue* Q, int* visited, FILE* out) {
	fprintf(out, "%d\n", k);
	int i,temp;
	for(i=0; i<G.deg[k]; i++) {
		if(!visited[G.adj[k][i] ]) {
			visited[G.adj[k][i]] =TRUE;
			insert(Q,G.adj[k][i]);
		}
	}
	if(!is_empty(*Q)) visit(dequeue(Q), G, Q, visited, out);
	return;
	}

void bfs(graph G, FILE* out) {
	queue Q = init_queue();
	int visited[G.n]; int i;
	memset(visited, 0, G.n * sizeof(int) );
	for(i=0;i<G.n;i++) {
		if(!visited[i]) {
			visited[i] = TRUE;
			visit(i, G, &Q, visited, out);
		} 
	}
	return;
}

int main() {
	graph G = init_graph(10, TRUE, FALSE);
	rand_fill(&G, 0);
	write_graph(G, stdout, TRUE);
	getchar();
	printf("BFS DEL GRAFO:\n");
	bfs(G, stdout);
	getchar();
	return 0;
}
