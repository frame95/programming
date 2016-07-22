#ifndef __DYNAMIC_GRAPH_LIB__
#define __DYNAMIC_GRAPH_LIB__ 1

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class graph {

	public:
		vector< vector< int> > adj;
		int edges;
		graph() {
			edges=0;
		}
		
		void add_node() {
			adj.resize( adj.size() +1);
			return;	
		}

		void add_edge(int i, int j) {
			adj[i].push_back(j);
			adj[j].push_back(i);
			edges++;
			return;
		}

		void read( FILE * input) {
			int i,n,m,a,b;
			fscanf(input, "%d %d", &n, &m);
			adj.resize(n);
			for(i=0;i<m;i++) {
				fscanf(input, "%d %d", &a, &b);
				add_edge(a,b);
			}
			return;
		}

		void write( FILE * output) {
			int i,j;
			fprintf(output, "%d %d\n", adj.size(), edges);

			for(i=0;i<adj.size();i++) {
				for(j=0;j<adj[i].size();j++) {
					if(i <=adj[i][j] ) {
						fprintf(output, "%d %d\n", i, adj[i][j]);
					}
				}
			}

			return;	
		} 

	};

#endif
