#include <cstdio>
#include <vector>

using namespace std;

vector<int> primes;
vector<float> density;
vector<int> k;
FILE *fin,*fin2,*fin3;

void sieve(int n) {
	int eras[n+1];
	int i,j;
	for(i=1;i<=n;i++) {
		eras[i]=0;
	}
	for(i=2; i<=n; i++) {
		if(eras[i]==0) {
			primes.push_back(i);
			for(j=2;j<=n/i;j++) {
				eras[i*j]=1;
			}
		}
	}
	return;
}

int ord2(int p) {
	int c=1,r=2;
	while(r != 1) {
		r*=2;
		c++;
		r%=p;
	}
	return c;
	}
	
int main() {
	int n,i,j,a,b; 
	fin = fopen("plot-orders.txt", "w");
	fin2= fopen("pr-densities.txt", "w");
	fin3= fopen("dst-analsys.txt", "w");
	printf("Inserisci n\n");
	scanf("%d", &n);
	sieve(n);
	density.resize(primes.back() +1);
	k.resize(primes.back() +1);
	for(i=1; i<primes.size(); i++) {
		density[i] =0;	
		k[i] = 0;
	}
	for(i=1; i<primes.size(); i++) {
		a=ord2(primes[i]); b=(primes[i]-1)/a;
		fprintf(fin, "%d %d\n", primes[i],  a);
		k[b] ++; 
		for(j=1; j<=primes.size(); j++) {
			density[j] = (float) ( i*(i-1)*density[j] + k[j] ) / (float)(i*i);
		}
		printf("k=%d, d=%f\n", k[1], density[1]); getchar();
	} 
	for(i=1; i<primes.size(); i++) {
		fprintf(fin3, "%f\n", density[i] );
	}
	return 0;
}
	
	
