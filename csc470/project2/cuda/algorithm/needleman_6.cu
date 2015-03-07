/********************************
Based on code by:
Lorenzo Seidenari (sixmoney@virgilio.it)
*********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 100000

int  n; 
int  m;
int levenshtein_distance(char *s,char*t);
int minimum(int a,int b,int c);

//-----------------------------------------------------------------------------
void cleanString(char string[]) {
  //Removes all spaces from string pointed to by "string", converts characters
  //to uppercase, and deletes a terminating newline character.
  int i, current;
  int length = strlen(string);

  current = 0;
  for(i=0;i<length;i++) {
    if(string[i]=='\n') {
      string[current++] = '\0';
      break;
    }
    else if(string[i]!=' ') {
      string[current++] = toupper(string[i]);
    }
  }
}
//-----------------------------------------------------------------------------
int importFASTA(char *filename, char *sequence) {
  //Reads a file, located at path specified by "filename", containing a FASTA
  //sequence. It finds the first full, complete sequence in the file, stores
  //it in "sequence", and returns the length of the sequence, or -1 on failure.
  FILE *fastaFile;
  char input[256];
  int readFlag; //set to 1 once a sequence has been read in
  int length;

  //open the file
  if((fastaFile = fopen(filename, "r")) == NULL) {
    return -1;
  }

  sequence[0] = '\0';

  //read the full first sequence, discarding unnecessary headers
  readFlag=0;
  length = 0;
  while(fgets(input,256,fastaFile)!=NULL) {
    //is it a header or a comment?
    if(input[0]=='>' || input[0]==';') {
      if(readFlag) break;
      else continue;
    }
    else readFlag = 1;

    cleanString(input);
    length += strlen(input);

    strncat(sequence,input,MAX_SEQUENCE_LENGTH-length - 1);
  }
  //Add a terminatng null character, just in case
  sequence[length] = '\0';

  fclose(fastaFile);
  return length;
}


/****************************************/
/*Implementation of Levenshtein distance*/
/****************************************/

__device__ int levenshtein_distance(char *s,char*t, int one, int two, int *d)
/*Compute levenshtein distance between s and t*/
{
  //Step 1
  int i,j,cost,distance;
  if(one!=0&&two!=0)
  {
  	printf ("%d\n", 1);
    two++;
    one++;
    //Step 3 and 4	
    for(i=1;i<one;i++)
      for(j=1;j<two;j++)
	{
        //Step 5
        if(s[i-1]==t[j-1])
          cost=0;
        else
          cost=1;
        //Step 6	
        int min = d[(j-1)*one+i]+1;
        if (d[j*one+i-1]+1 < min)
        	min = d[j*one+i-1]+1;
        if (d[(j-1)*one+i-1]+cost < min)
        	min = d[(j-1)*one+i-1]+cost;
        d[j*one+i] = min;
        //d[j*one+i]=minimum(d[(j-1)*one+i]+1,d[j*one+i-1]+1,d[(j-1)*one+i-1]+cost);
    }
    distance=d[one*two-1];
    printf ("%d\n", distance);
    free(d);
    return distance;
  }
  else 
    return -1; //a negative return value means that one or both strings are empty.
}

__global__ void kernel (int *score, char *s, char*t, int one, int two, int n, int *d)
{
	int i = (blockIdx.x * blockDim.x) + threadIdx.x;
	if (i < n-1){
		printf ("%d executed %d\n", i, n);
		score[i]=levenshtein_distance(s,t,one,two,d);
	}
	else
		return;
}

int main(int argc, char *argv[]) {
  int *score = 0, *d_s = 0, *d = 0, *d_D = 0, k = 0;
  char *d_A, *d_B;
  char A[MAX_SEQUENCE_LENGTH+1];
  char B[MAX_SEQUENCE_LENGTH+1];

  if(argc < 3) {
    printf("Usage: new_edit_distance <sequence1> <sequence2>\n");
    printf("<sequence1>: file containing the first sequence, FASTA format\n");
    printf("<sequence2>: file containing the second sequence, FASTA format\n");
    return EXIT_FAILURE;
  }

	int a = 2;
  	n = importFASTA(argv[1],A);
  	m = importFASTA(argv[2],B);

  	cudaMalloc(&d_D, (sizeof(int))*(m+1)*(n+1));

	d = (int *)malloc(sizeof(int)*(m+1)*(n+1));

	n++;
	m++;

	for(k=0;k<n;k++){
		d[k]=k;
	}
	for(k=0;k<m-1;k++){
		d[k*n]=k;
	}

	n--;
	m--;

	cudaMemcpy( d_D, d, sizeof(int)*(m+1)*(n+1), cudaMemcpyHostToDevice );

  	dim3 threadsPerBlock(1, 1);
	dim3 numBlocks(a/threadsPerBlock.x, a/threadsPerBlock.y);
	
  	cudaMalloc(&d_A, MAX_SEQUENCE_LENGTH+1);
	cudaMalloc(&d_B, MAX_SEQUENCE_LENGTH+1);

	cudaMemcpy( d_s, score, sizeof(int)*a, cudaMemcpyHostToDevice );
	score = (int *)malloc(sizeof(int)*a);

	kernel<<<numBlocks, threadsPerBlock>>>(d_s, d_A, d_B, n, m, a, d_D);
	printf ("%s\n", cudaGetErrorString(cudaGetLastError()));
	cudaDeviceSynchronize();

	cudaMemcpy( score, d_s, sizeof(int)*a, cudaMemcpyDeviceToHost );

	printf("%d\n", score[0]);

	cudaFree(d_s);
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_D);
	free(d);
	free(score);

  return EXIT_SUCCESS;
}
