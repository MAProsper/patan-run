#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MPI_TAG 0

int main(int argc, char* argv[]) {
	int nodes, id, n, i;
	MPI_Status s;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &nodes);

	n = -1;
	if (id == 0) {
		if (argc == 2) n = atoi(argv[1]); printf("n = %d\n", n);
		for (i = 1; i < nodes; i++) MPI_Send(&n, 1, MPI_INT, i, MPI_TAG, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&n, 1, MPI_INT, 0, MPI_TAG, MPI_COMM_WORLD, &s);
	}
	printf("P%d = %d\n", id, n);

	MPI_Barrier(MPI_COMM_WORLD);

	n = -1;
	if (id == 0) {
		printf("n = "); fflush(stdout); scanf("%d", &n);
		for (i = 1; i < nodes; i++) MPI_Send(&n, 1, MPI_INT, i, MPI_TAG, MPI_COMM_WORLD);
	} else {
		MPI_Recv(&n, 1, MPI_INT, 0, MPI_TAG, MPI_COMM_WORLD, &s);
	}
	printf("P%d = %d\n", id, n);
	
	MPI_Finalize();
	return 0;
}
