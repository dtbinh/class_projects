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

__global__ void levenshtein_distance(char *s,char*t, int one, int two, int *d)
/*Compute levenshtein distance between s and t*/
{
  	//Step 1
	int cost;
	//int distance;
	int i = (blockIdx.x * blockDim.x) + threadIdx.x;
	int j = (blockIdx.y * blockDim.y) + threadIdx.y;
	if (i>=one || j>=two)
        return;
	if(one!=0&&two!=0){
		
		two++;
		one++;

		if(s[i-1]==t[j-1]){
			cost=0;
		}
		else{
			cost=1;
		}

		int min = d[(j-1)*one+i]+1;
		if (d[j*one+i-1]+1 < min){
			min = d[j*one+i-1]+1;
		}
		if (d[(j-1)*one+i-1]+cost < min){
			min = d[(j-1)*one+i-1]+cost;
		}
		d[j*one+i] = min;
		
	}
	else
		printf ("-1");
}

int main(int argc, char *argv[]) {
	char A[MAX_SEQUENCE_LENGTH+1];
	char B[MAX_SEQUENCE_LENGTH+1];
	if(argc < 3) {
		printf("Usage: new_edit_distance <sequence1> <sequence2>\n");
		printf("<sequence1>: file containing the first sequence, FASTA format\n");
		printf("<sequence2>: file containing the second sequence, FASTA format\n");
		return EXIT_FAILURE;
	}

	n = importFASTA(argv[1],A);
	m = importFASTA(argv[2],B);
	//int k;

	int k, *d, *d_D;
	char *d_A, *d_B;                
	cudaMalloc(&d_A, MAX_SEQUENCE_LENGTH+1);
	cudaMalloc(&d_B, MAX_SEQUENCE_LENGTH+1);
	cudaMalloc(&d_D, (sizeof(int))*(m+1)*(n+1));

	d = (int *)malloc(sizeof(int)*(m+1)*(n+1));

	for(k=0;k<n;k++){
		d[k]=k;
	}
	for(k=0;k<m-1;k++){
		d[k*n]=k;
	}

	cudaMemcpy( d_D, d, sizeof(int)*(m+1)*(n+1), cudaMemcpyHostToDevice );

	dim3 threadsPerBlock(32, 32);
	dim3 numBlocks(n/threadsPerBlock.x, m/threadsPerBlock.y);

	levenshtein_distance<<<numBlocks, threadsPerBlock>>>(d_A,d_B, n, m, d_D);
	cudaDeviceSynchronize();
	//printf ("%s\n", cudaGetErrorString(cudaGetLastError()));

	cudaMemcpy( d, d_D, sizeof(int)*(m+1)*(n+1), cudaMemcpyDeviceToHost );

	printf("%d\n", d[n*m-1]);

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_D);
	free(d);

	return EXIT_SUCCESS;
}
