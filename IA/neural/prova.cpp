#include <stdio.h>
#include <vector>

using namespace std;


int main() {
	vector< int> A;
	vector< int> B;
	A.push_back(1);
	A.push_back(2);
	B.push_back(3);
	printf("A: %d %d, B: %d	\n", A[0], A[1], B[0]); getchar();
	A=B; A.resize(2);
	printf("A: %d %d, B: %d	\n", A[0], A[1], B[0]); getchar();
	return 0;
}
