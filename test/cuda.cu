#include <stdio.h>
#include <stdlib.h>

__global__ void loop(int n) {
	printf("T%d/B%d = %d\n", threadIdx.x, blockIdx.x, n);
}

int main(int argc, char* argv[]) {
	int n;

	cudaDeviceSynchronize();

	n = -1;
	if (argc == 2) n = atoi(argv[1]); printf("n = %d\n", n);
	loop<<<2, 2>>>(n);

	cudaDeviceSynchronize();

	n = -1;
	printf("n = "); fflush(stdout); scanf("%d", &n);
	loop<<<2, 2>>>(n);

	cudaDeviceSynchronize();

	return 0;
}
