#ifndef __NEURAL_LIB__
#define __NEURAL_LIB__

#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
 
double elab(double x) {
	return 1/(1+exp(-x));
	}

class layer {
	
	public:
		int size;
		vector< double> state;	

		layer() {}
		void resize(int n) {
			size=n;
			state.resize(n);
		}
	};
	
class neural {
	
	public:
		int is_input_set;
		int is_processed;
		int is_output_set;
		double gamma; //learning factor
		layer in;
		layer mid;
		layer out;
		layer exp;
		vector< vector< double > > firstflow;
		vector< vector< double > > secondflow;
		
		neural(int in_dim, int mid_dim, int out_dim, double learning_factor) {
			//init flags
			is_input_set=0;
			is_output_set=0;
			is_processed=0;
			gamma=learning_factor;
			
			//init layers
			in.resize(in_dim+1);
			mid.resize(mid_dim+1);
			out.resize(out_dim);
			exp.resize(out_dim);
			
			// adding bias
			in.state.back() = 1.0;
			mid.state.back() =1.0;
			
			//init flow matrices
			firstflow.resize(mid_dim);
			secondflow.resize(out_dim);
			
			int i;
			for(i=0;i<mid_dim;i++) {
				firstflow.at(i).resize(in_dim+1);
				fill(firstflow.at(i).begin(), firstflow.at(i).end(), 1);
			}
			for(i=0;i<out_dim;i++) {
				secondflow.at(i).resize(mid_dim+1);
				fill(secondflow.at(i).begin(), secondflow.at(i).end(), 1);
			}
		}
		
		void set_input( FILE *input) {
			int i;
			for(i=0;i<in.size-1;i++) {
				fscanf(input, "%lf", &in.state.at(i));
			}
			
			is_input_set = 1;
			return;
		}
		
		void set_expected_output( FILE *input) {
			int i;
			for(i=0;i<exp.size;i++) {
				fscanf(input, "%lf", &exp.state.at(i));
			}
			is_output_set = 1;
			return;
		}
		
		void compute() {
			if( is_input_set == 0 ) {
				fprintf(stderr, "Input not set: impossible to continue.\n");
			} else {
				int i,k; double result;
				for(i=0;i<mid.size-1;i++) {
					result=0;
					for(k=0;k<in.size;k++) {
						result+=firstflow[i][k] * in.state[k];
					}
					mid.state.at(i)= elab(result);
				}
				for(i=0;i<out.size;i++) {
					result=0;
					for(k=0;k<mid.size;k++) {
						result+=secondflow[i][k] * mid.state[k];
					}
					out.state.at(i)= elab(result);
				}
				is_processed=1;
			}
			
		}
		
		void print_result(FILE *output) {
			if(is_input_set == 0) {
				fprintf(stderr, "Input not set: nothing to print.\n");
			} else if ( is_processed == 0) {
				fprintf(stderr, "Not processed yet: nothing to print.\n");
			} else {
				int i;
				fprintf(output, "The input: \n");
				for(i=0;i<in.size-1;i++) {
					fprintf(output, "%lf \n", in.state.at(i) );
				}
				fprintf(output, "Yielded the output: \n");
				for(i=0;i<out.size;i++) {
					fprintf(output, "%lf \n", out.state.at(i) );
				}
			}
			return;
		}
		
		void print_core(FILE *output) {
			int j,k;
			fprintf(output, "F1-matrix:\n");
			for(j=0;j<mid.size-1;j++) {
					for(k=0;k<in.size;k++) {
						fprintf(output, "%lf ", firstflow[j][k]);
					}
					fprintf(output, "\n");
			}
			fprintf(output, "F2-matrix:\n");
			for(j=0;j<out.size;j++) {
					for(k=0;k<mid.size;k++) {
						fprintf(output, "%lf ", secondflow[j][k]);
					}
					fprintf(output, "\n");
			}
			return;
		
		}
		void clean() {
			fill(in.state.begin(), in.state.end(), 0);
			fill(mid.state.begin(), mid.state.end(), 0);
			fill(out.state.begin(), out.state.end(), 0);
			fill(exp.state.begin(), exp.state.end(), 0);
			is_input_set=0;
			is_output_set=0;
			is_processed=0;
			return;
		}

		void correct() {
			if( is_input_set == 0 || is_output_set == 0 || is_processed == 0) {
				fprintf(stderr, "Process not completed: impossible to continue.\n");
			} else {
				// References: https://page.mi.fu-berlin.de/rojas/neural/chapter/K7.pdf, pg 165 (15 of pdf).
				// Computing d_j:
				int j,k;
				vector< double> d_out; d_out.resize(out.size);
				for(j=0;j<d_out.size();j++) {
					d_out[j] = out.state[j]*(1-out.state[j])*(out.state[j]-exp.state[j]);
				}
				vector< double> d_mid; d_mid.resize(mid.size-1); double temp;
				for(j=0;j<d_mid.size();j++) {
					temp=0;
					for(k=0;k<out.size;k++) {
						temp+=secondflow[k][j]*d_out[k]; // The transpose of flow matrix!
					}
					d_mid[j] = mid.state[j]*(1-mid.state[j])*temp;
				}
				// Refreshing weights:
				for(j=0;j<in.size-1;j++) {
					for(k=0;k<mid.size-1;k++) {
						firstflow[j][k] += -gamma*in.state[j]*d_mid[k];	
					}
				}
				for(j=0;j<mid.size-1;j++) {
					for(k=0;k<out.size;k++) {
						secondflow[k][j] += -gamma*mid.state[j]*d_out[k];	
					}
				}
			}
			return;
		}
		
		void train(FILE * testcase) {
			int testnumber,i;
			fscanf(testcase, "%d", &testnumber);
			for(i=0;i<testnumber;i++) {
				set_input(testcase);
				set_expected_output(testcase);
				compute();
				correct();
				clean();
			}
			return;
		}
		// STANDARD FORMAT FOR NEURAL
		/*
		1: gamma
		2: in.size mid.size out.size - without bias
		following (in.size+1)*mid.size: w_ij(1) - row by row
		following (mid.size+1)*out.size: w_ij(2) - row by row
		*/
		void load(FILE* input) {
			int i,j;
			fscanf(input, "%lf", &gamma);
			int a,b,c;
			fscanf(input, "%d %d %d", &a,&b,&c);
			in.resize(a+1);
			mid.resize(b+1);
			out.resize(c);
			exp.resize(c);
			
			firstflow.resize(b);
			secondflow.resize(c);
			
			for(i=0;i<b;i++) {
				firstflow.at(i).resize(a+1);
			}
			for(i=0;i<c;i++) {
				secondflow.at(i).resize(b+1);
			}
			
			
			for(i=0;i<mid.size-1;i++) {
				for(j=0;j<in.size;j++) {
					fscanf(input, "%lf", &firstflow[i][j]);	
				}
			}
			for(i=0;i<out.size;i++) {
				for(j=0;j<mid.size;j++) {
					fprintf(input, "%lf", &secondflow[i][j]);	
				}
			}
			return;
		}
		
		void save(FILE* output) {
			printf("Saving gamma.\n"); getchar();
			fprintf(output, "%lf\n", gamma);
			printf("Saving dimensions.\n"); getchar();
			fprintf(output, "%d %d %d\n", in.size-1, mid.size-1, out.size);
			int i,j;
			for(i=0;i<mid.size-1;i++) {
				for(j=0;j<in.size;j++) {
					fprintf(output, "%lf\n", firstflow[i][j]);	
				}
			}
			for(i=0;i<out.size;i++) {
				for(j=0;j<mid.size;j++) {
					fprintf(output, "%lf\n", secondflow[i][j]);	
				}
			}
			return;
		}

		
	};
	
#endif
