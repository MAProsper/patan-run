#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MPI_TAG 0

int main(int argc, char* argv[]) {
	int numProcs, miId, n, i;
	MPI_Status s;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &miId);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);

	n = -1;
	if (miId == 0) {
		if (argc == 2) n = atoi(argv[1]); printf("n = %d\n", n);
		for (i = 1; i < numProcs; i++) MPI_Send(&n, 1, MPI_INT, i, MPI_TAG, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&n, 1, MPI_INT, 0, MPI_TAG, MPI_COMM_WORLD, &s);
	}
	printf("P%d = %d\n", miId, n);

	MPI_Barrier(MPI_COMM_WORLD);

	n = -1;
	if (miId == 0) {
		printf("n = "); fflush(stdout); scanf("%d", &n);
		for (i = 1; i < numProcs; i++) MPI_Send(&n, 1, MPI_INT, i, MPI_TAG, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&n, 1, MPI_INT, 0, MPI_TAG, MPI_COMM_WORLD, &s);
	}
	printf("P%d = %d\n", miId, n);
	
	MPI_Finalize();
	return 0;
}
