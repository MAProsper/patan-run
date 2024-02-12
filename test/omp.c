#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
	int id, n;

	#pragma omp barrier

	n = -1;
	if (argc == 2) n = atoi(argv[1]); printf("n = %d\n", n);
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("T%d = %d\n", id, n);
	}

	#pragma omp barrier

	n = -1;
	printf("n = "); fflush(stdout); scanf("%d", &n);
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		printf("T%d = %d\n", id, n);
	}

	#pragma omp barrier
	
	return 0;
}
