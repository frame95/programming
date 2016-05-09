#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int next(int* v, int focus, int dim) { 
	if(v[focus] == 0) {
		v[focus] = 1;
		return 0;
	} else {
		if(focus == dim-1) {
			return 1;
		} else {
			v[focus] =0;
			return next(v, focus+1,dim);
		}
	}
} 

int converti( int* v, int dim) {
	int i=0; int s=0;
	for(i=1; i<=dim; i++) s=2*s+v[dim-i];
	return s;
	}
	
int* omega(int* v, int prec, int dim) {
	int i; int n=converti(v,dim);
	int* res = (int *)malloc(sizeof(int)*prec );
	for(i=0;i<prec;i++) {
		if(n%2 == 0) {
			res[i]=0;
			n=n/2;
		} else {
			res[i]=1;
			n=(3*n+1)/2;
		}
	}
	return res;		
}

int is_swapper(int* v, int dim) {
	int* omg = (int*)malloc( sizeof(int)*(dim+1));
	omg = omega(v,dim+1,dim);
	return omg[dim];
	}

void stampa(int* v, int dim) {
	int i=0;
	for(i=0;i<dim;i++) printf("%d", v[dim-1-i]);
	return;
}


int main() {
	FILE * fout;
	fout=fopen("swap_val.txt", "w"); 
	int N,M,j,temp,c=0;
	printf("Inserisci un M\n");
	scanf("%d", &M);
	for(N=1;N<=M;N++) {
		int v[N]; int stop=0;
		for(j=0;j<N;j++) v[j]=0;
		do {
			//stampa(v,N);
			temp=is_swapper(v,N);
			c+=temp;
			//printf("\t->\t%d\n", temp );		
			stop=next(v,0,N);
		} while (stop == 0);
		printf("\n Totale %d-swap: %d\n", N,c);	
		fprintf(fout, "%d\n", c);
	}
	getchar();
	fclose(fout);
	return 0;
}
