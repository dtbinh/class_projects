#include <stdio.h>

__device__ int addition (int a, int b)
{
  int r;
  r=a+b;
  return r;
}

__global__ void device_greetings(void)
{
  printf("Hello, world from the device!\n");
  char n[] = "big!\n";
  printf(n);

  int z;
  z = addition(5,3);
  printf("The result is %d\n", z);
}

int main(void)
{
  // greet from the host
  printf("Hello, world from the host!\n");

  // launch a kernel with a single thread to greet from the device
  device_greetings<<<1,1>>>();
  cudaDeviceSynchronize();


  return 0;
}