#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
	int id, n;

	n = -1;
	if (argc == 2) n = atoi(argv[1]); printf("n = %d\n", n);
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("P%d = %d\n", omp_get_thread_num(), n);
	}

	#pragma omp barrier

	n = -1;
	printf("n = "); fflush(stdout); scanf("%d", &n);
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("P%d = %d\n", omp_get_thread_num(), n);
	}
	
	return 0;
}
