#include <stdio.h>

#define SIZE	2048

__global__ void VectorAdd (int *a, int *b, int *c, int n)
{
	int i = (blockIdx.x * blockDim.x) + threadIdx.x;

	if (i < n)
		c[i] = a[i] + b[i];
}

int main()
{
	int *a, *b, *c;
	int *d_a, *d_b, *d_c;

	a = (int *)malloc(SIZE*sizeof(int));
	b = (int *)malloc(SIZE*sizeof(int));
	c = (int *)malloc(SIZE*sizeof(int));

	cudaMalloc( &d_a, SIZE*sizeof(int));
	cudaMalloc( &d_b, SIZE*sizeof(int));
	cudaMalloc( &d_c, SIZE*sizeof(int));

	for( int i = 0; i < SIZE; ++i )
	{
		a[i] = i;
		b[i] = i;
		c[i] = 0;
	}

	cudaMemcpy( d_a, a, SIZE*sizeof(int), cudaMemcpyHostToDevice );
	cudaMemcpy( d_b, b, SIZE*sizeof(int), cudaMemcpyHostToDevice );
	cudaMemcpy( d_c, c, SIZE*sizeof(int), cudaMemcpyHostToDevice );

	dim3 threadsPerBlock(32, 32);
	dim3 numBlocks(2048/threadsPerBlock.x);

	VectorAdd<<< numBlocks, threadsPerBlock >>>(d_a, d_b, d_c, SIZE);

	cudaMemcpy( a, d_a, SIZE*sizeof(int), cudaMemcpyDeviceToHost );
	cudaMemcpy( b, d_b, SIZE*sizeof(int), cudaMemcpyDeviceToHost );
	cudaMemcpy( c, d_c, SIZE*sizeof(int), cudaMemcpyDeviceToHost );

	for( int i = 0; i < SIZE; ++i){
		printf("a[%d] = %d\n", i, a[i]);
		printf("b[%d] = %d\n", i, b[i]);
		printf("c[%d] = %d\n", i, c[i]);
	}

	free(a);
	free(b);
	free(c);

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);

	return 0;
}