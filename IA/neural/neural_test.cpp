#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "neural.h"

using namespace std;


int main() {

	printf("Welcome to neural test. \n"); getchar();
	
	printf("INITIALIZATION - 1* phase.\n"); getchar();
	neural * N = new neural(2,2,1,1);
	
	
	printf("SET INPUT - 2* phase.\n"); getchar();
	FILE * input;
	input = fopen("neural_input.txt", "r");
	N->set_input(input);
	fclose(input);
	
	
	printf("SET EXPECTED OUTPUT - 3* phase.\n"); getchar();
	FILE * expected;
	expected = fopen("neural_expected.txt", "r");
	N->set_expected_output(expected);
	fclose(expected);
	
	
	printf("COMPUTE - 4* phase.\n"); getchar();
	N->compute();
	
	
	printf("PRINTING - 5* phase.\n"); getchar();
	printf("DATA\n");
	N->print_result(stdout);
	printf("CORE\n");
	N->print_core(stdout);
	
	
	printf("CORRECTION - 6* phase.\n"); getchar();
	N->correct();
	printf("ACTUAL CORE:\n");
	N->print_core(stdout);
	
	printf("SAVING - 7* phase. \n"); getchar();
	FILE * memo;
	memo = fopen("neural_memory.txt", "w");
	N->save(memo);
	fclose(memo);
	
	printf("LOADING - 8*phase, \n"); getchar();
	memo=fopen("neural_memory.txt", "r");
	N->load(memo);
	fclose(memo);
	N->print_core(stdout);
	
	printf("*** FIRST ROUND: FINISHED!! YEAH FUCKING MIND ARTIFICIAL MOTHAFUCKA ***\n");
	return 0;
}
