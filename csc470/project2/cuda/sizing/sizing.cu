#include <stdio.h>

__global__ void multi_thread(void)
{
  printf("Hello, world from the device!\n");
}

int main(void)
{
  // greet from the host
  printf("Hello, world from the host!\n");

  // launch a kernel with a single thread to greet from the device
  multi_thread<<<1,1>>>();
  cudaDeviceSynchronize();

  return 0;
}