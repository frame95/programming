#include "graph.h"


int main() {
	// ****** UNWEIGHTED, UNDIRECTED ******
	printf("****** UNWEIGHTED & UNDIRECTED - part 1 ****** \n\n"); getchar(); fflush(stdin);
	
	// INIZIALIZZAZIONE
	printf("-- INITIALIZATION TEST -- \n"); getchar(); fflush(stdin);
	
	int n; printf("Inserisci il numero di nodi del grafo casuale:\n");
	scanf("%d", &n);
	graph G = graph_init(n, 0, 0);
	
	// RANDOM FILLING
	printf(" -- RANDOM FILLING TEST -- \n"); getchar(); fflush(stdin);
	graph_rand_fill(&G,  10);
	
	// PRINTING on stdout
	printf(" -- PRINTING on stdout TEST -- \n"); getchar(); fflush(stdin);
	graph_print(G, stdout, TRUE); getchar(); fflush(stdin);
	
	// READING from stdin
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	graph H;
	graph_read(&H, stdin, TRUE);
	printf("RISULTATO:\n");
	graph_print(H, stdout, TRUE);
	
	// READING FROM FILE
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	FILE * fin;
	fin=fopen("unw_und_reading_from_file.txt", "r");
	graph H2;
	graph_read(&H2, fin, FALSE);
	
	// PRINTING ON FILE
	printf(" -- PRINTING ON FILE TEST -- \n"); getchar(); fflush(stdin);
	FILE * fout;
	fout=fopen("unw_und_printing_on_file.txt", "w");
	graph_print(H2, fout, FALSE);
	
	// ****** WEIGHTED, UNDIRECTED ******
	printf("****** WEIGHTED & UNDIRECTED - part 2 ****** \n\n"); getchar(); fflush(stdin);
	
	// INIZIALIZZAZIONE
	printf("-- INITIALIZATION TEST -- \n"); getchar(); fflush(stdin);
	
	printf("Inserisci il numero di nodi del grafo casuale:\n");
	scanf("%d", &n);
	G = graph_init(n, 0, 1);
	
	// RANDOM FILLING
	printf(" -- RANDOM FILLING TEST -- \n"); getchar(); fflush(stdin);
	printf("Inserisci il max_weight con cui vuoi riempire il grafo:\n");
	int max_w;
	scanf("%d", &max_w);
	graph_rand_fill(&G,  max_w);
	
	// PRINTING on stdout
	printf(" -- PRINTING on stdout TEST -- \n"); getchar(); fflush(stdin);
	graph_print(G, stdout, TRUE); getchar(); fflush(stdin);
	
	// READING from stdin
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	graph_read(&H, stdin, TRUE);
	printf("RISULTATO:\n");
	graph_print(H, stdout, TRUE);
	
	// READING FROM FILE
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	fin=fopen("w_und_reading_from_file.txt", "r");
	graph_read(&H2, fin, FALSE);
	
	// PRINTING ON FILE
	printf(" -- PRINTING ON FILE TEST -- \n"); getchar(); fflush(stdin);
	fout=fopen("w_und_printing_on_file.txt", "w");
	graph_print(H2, fout, FALSE);
	
	// ****** UNWEIGHTED, DIRECTED ******
	printf("****** UNWEIGHTED & DIRECTED - part 3 ****** \n\n"); getchar(); fflush(stdin);
	
	// INIZIALIZZAZIONE
	printf("-- INITIALIZATION TEST -- \n"); getchar(); fflush(stdin);
	
	printf("Inserisci il numero di nodi del grafo casuale:\n");
	scanf("%d", &n);
	G = graph_init(n, 1, 0);
	
	// RANDOM FILLING
	printf(" -- RANDOM FILLING TEST -- \n"); getchar(); fflush(stdin);
	graph_rand_fill(&G,  10);
	
	// PRINTING on stdout
	printf(" -- PRINTING on stdout TEST -- \n"); getchar(); fflush(stdin);
	graph_print(G, stdout, TRUE); getchar(); fflush(stdin);
	
	// READING from stdin
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	graph_read(&H, stdin, TRUE);
	printf("RISULTATO:\n");
	graph_print(H, stdout, TRUE);
	
	// READING FROM FILE
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	fin=fopen("unw_d_reading_from_file.txt", "r");
	graph_read(&H2, fin, FALSE);
	
	// PRINTING ON FILE
	printf(" -- PRINTING ON FILE TEST -- \n"); getchar(); fflush(stdin);
	fout=fopen("unw_d_printing_on_file.txt", "w");
	graph_print(H2, fout, FALSE);
	
	// ****** WEIGHTED, DIRECTED ******
	printf("****** WEIGHTED & DIRECTED - part 4 ****** \n\n"); getchar(); fflush(stdin);
	
	// INIZIALIZZAZIONE
	printf("-- INITIALIZATION TEST -- \n"); getchar(); fflush(stdin);
	
	printf("Inserisci il numero di nodi del grafo casuale:\n");
	scanf("%d", &n);
	G = graph_init(n, 1, 1);
	
	// RANDOM FILLING
	printf(" -- RANDOM FILLING TEST -- \n"); getchar(); fflush(stdin);
	printf("Inserisci il max_weight con cui vuoi riempire il grafo:\n");
	scanf("%d", &max_w);
	graph_rand_fill(&G,  max_w);
	
	// PRINTING on stdout
	printf(" -- PRINTING on stdout TEST -- \n"); getchar(); fflush(stdin);
	graph_print(G, stdout, TRUE); getchar(); fflush(stdin);
	
	// READING from stdin
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	graph_read(&H, stdin, TRUE);
	printf("RISULTATO:\n");
	graph_print(H, stdout, TRUE);
	
	// READING FROM FILE
	printf(" -- READING from stdin TEST -- \n"); getchar(); fflush(stdin);
	fin=fopen("w_d_reading_from_file.txt", "r");
	graph_read(&H2, fin, FALSE);
	
	// PRINTING ON FILE
	printf(" -- PRINTING ON FILE TEST -- \n"); getchar(); fflush(stdin);
	fout=fopen("w_d_printing_on_file.txt", "w");
	graph_print(H2, fout, FALSE);
	
	return 0;
}
