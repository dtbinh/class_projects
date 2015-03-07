/********************************
Based on code by:
Lorenzo Seidenari (sixmoney@virgilio.it)
*********************************/

#include <stdlib.h>
//#include <malloc.h>
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

int levenshtein_distance(char *s,char*t)
/*Compute levenshtein distance between s and t*/
{
  //Step 1
	int k,i,j,cost,*d,distance;
	int *d_d;
	if(n!=0&&m!=0)
	{
		d=malloc((sizeof(int))*(m+1)*(n+1));
		m++;
		n++;
    //Step 2
		for(k=0;k<n;k++)
			d[k]=k;
		for(k=0;k<m;k++){
			d[k*n]=k;
		}

    //Step 3 and 4
		for(i=1;i<n;i++)
			for(j=1;j<m;j++)
			{
        //Step 5
				if(s[i-1]==t[j-1])
					cost=0;
				else
					cost=1;
        //Step 6
				d[j*n+i]=minimum(d[(j-1)*n+i]+1,d[j*n+i-1]+1,d[(j-1)*n+i-1]+cost);
			}
			distance=d[n*m-1];
			free(d);
			return distance;

		}
		else 
    return -1; //a negative return value means that one or both strings are empty.
}

int minimum(int a,int b,int c)
/*Gets the minimum of three values*/
{
	int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;
}

int main(int argc, char *argv[]) {
	int score;
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

	score = levenshtein_distance(A,B);
	printf("%d\n", score);

	return EXIT_SUCCESS;
}
