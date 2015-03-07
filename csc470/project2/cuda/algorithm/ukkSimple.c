//An implementation of Ukkonen's algorithm for calculating the Levenshtein
//Edit Distance between two strings, as described in his paper,
//"Algorithms for Approximate String Matching", 1985. This is Algorithm (11).

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#define DEBUG

#define MAX_SEQUENCE_LENGTH 100000
#define BIG_NEGATIVE -10
#define SENTINEL_A '#'
#define SENTINEL_B '@'

char *A, *B;			//The two strings
int *dataCurr;			//f[k][p]
int *dataOld;           //f[k][p-1]
int *f1, *f0; 			//hold the actual data, the above pointers are offset
int offset;				// Offset into data
int lenA, lenB;			//Lengths of the respective strings
int numDiags; 			//The number of diagonals needed in the matrix
//-----------------------------------------------------------------------------
#ifdef DEBUG
void printdbg(char *msg) {
	printf(msg);
	fflush(stdin);
}
#endif
//-----------------------------------------------------------------------------
void errorExit(char* errorMessage) {
  //Handles errors. This function displays an error message and then exits.
  printf("%s\n",errorMessage);
	exit(EXIT_FAILURE);
}
//-----------------------------------------------------------------------------
int max(int a, int b) {
	//Return the greater of the two arguments
	if(b > a) return b;

	return a;
}

int min(int a, int b) {
	//Return the lesser of the two arguments
	if(b > a) return a;

	return b;
}
//-----------------------------------------------------------------------------
void allocateMemory() {
	//create an array of type data[max_num_diff_costs_on_a_diagonal]
  	f1 = malloc(sizeof(int) * numDiags);
  	f0 = malloc(sizeof(int) * numDiags);
}
//-----------------------------------------------------------------------------
void initMatrix() {
	//Fill the matrix with appropriate initial values
	int i;

	for(i=0; i<numDiags; i++) {
		if(i < offset) {
			f0[i] = f1[i] = offset - i - 1;
		}
		else {
			f0[i] = f1[i] = -1;
		}
	}
}
//-----------------------------------------------------------------------------
void evaluateCell(int k) {
	//Evaluate the next cell along diagonal k. Note that we need only specify
	//the diagonal, because the cell is simply the next one along that diagonal.
	//Since we store the result in the cell being evaluated, there is no need
	//to return a value.
	//In Ukkonen's paper, this is Algorithm (8).
	int down, right, diagonal; //the row reached with each move
	int t;

	//determine how far each move can get us
	if(k - 1 + offset < 0) {
		//value is not valid
	  	down = -10;
	}
	else {
		down = dataOld[k-1];
	}
	right = dataOld[k+1] + 1;
	diagonal = dataOld[k] + 1;

#ifdef DEBUG
printf("k=%d : %d, %d, %d, ", k, down, right, diagonal); fflush(stdin);
#endif

	//Set t equal to the maximum of the three moves
	if(down > right) {
		if(down > diagonal) {
			t = down;
		}
		else {
			t = diagonal;
		}
	}
	else {
		if(right > diagonal) {
			t = right;
		}
		else {
			t = diagonal;
		}
	}

	//Advance t to reflect any matches
	while(t < lenA && A[t] == B[t+k]) {
#ifdef DEBUG
printf("\n   match, A[%d] = %c and B[%d] = %c, ",t,A[t],t+k,B[t+k]); fflush(stdin);
#endif
		t++;
	}

#ifdef DEBUG
printf("dataCurr[%d] = %d\n",k,t);fflush(stdin);
#endif

	//make sure that t won't put us past the end of the strings
	if(t > lenA) {
		//we cannot reach a row further than the total # of rows
		t = lenA;
	}
	if(t+k > lenB) {
		t = lenB - k;
	}

	dataCurr[k] = t;
}
//-----------------------------------------------------------------------------
int editCost() {
	//Calculate and return the edit distance between strings A and B. This
	//function contains the main loop, which will call the evaluateCell()
	//function for each cell within the currently tested bounds. If, at the end
	//of an iteration, we have reached the bottom right corner of the matrix,
	//then we return the score necessary to get there. Otherwise, we expand the
	//bounds and try again.
	//In Ukkonen's paper, this is Algorithm (11).
	int k;
	int p = -1;
	int r = p - lenA;
	int *temp;
	allocateMemory();

	//Now, we want to offset the data and costData pointers into the actual
	//arrays. This allows us to use negative values as indices into the
	//arrays, properly representing negative diagonals. An alternative to
	//this approach is to add the offset value to the index every time we
	//access the arrays, but this reduces readability and adds an extra
	//calculation (k+offset) to each data access.
	dataCurr = &f1[offset];
	dataOld = &f0[offset];

	initMatrix();

	//The main loop
	do {
		p++;
		r++;
#ifdef DEBUG
printf("\np = %d\n", p); fflush(stdin);
#endif
		//exchange pointers, so the last iteration's curr becomes old
		temp = dataOld;
		dataOld = dataCurr;
		dataCurr = temp;

		if(r <= 0) {
			for(k = -p; k<=p; k++) {
				evaluateCell(k);
			}
		}
		else {

			for(k = max(-lenA,-p); k <= -r; k++) {
				evaluateCell(k);
			}
			for(k = r; k <= p; k++) {
				evaluateCell(k);
			}
		}

	} while(dataCurr[lenB-lenA] != lenA);

	return p;
}
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
	while(fgets(input,256,fastaFile)!=NULL &&
		length < MAX_SEQUENCE_LENGTH)
	{
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
	//Add a terminating null character, just in case
	sequence[length] = '\0';

	fclose(fastaFile);
	return length;
}
//-----------------------------------------------------------------------------
void swapSequences() {
	//Exchange the pointers to the two sequences, so A points to what was B and
	//B to A.
	char *tempStr;
	int tempInt;

	//swap seq1 and seq2, including their lengths
	tempStr = A;
	A = B;
	B = tempStr;

	tempInt = lenA;
	lenA = lenB;
	lenB = tempInt;
}
//-----------------------------------------------------------------------------
void doInput(char* file1, char* file2) {
	//Get the strings from the files and set a few initial variables.
	lenA = importFASTA(file1,A);
	lenB = importFASTA(file2,B);

	if(lenA > lenB) {
		//i.e. B will always be longer than A
		swapSequences();
	}

	//add ending characters which do not match, to simplify match detection
	A[lenA] = SENTINEL_A;
	A[lenA+1] = '\0';
	B[lenB] = SENTINEL_B;
	B[lenB+1] = '\0';
}
//-----------------------------------------------------------------------------
void freeMemory() {
	//Simply, release all allocated memory
	free(f1);
	free(f0);
	free(A);
	free(B);
}
//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	//Get the user input, load the strings from the specified files, and
	//calculate the edit distance between them.
	int score;

	if(argc < 3) {
		printf("Usage: ukkSimple <type> <sequence1> <sequence2>\n");
		printf("<sequence1>: file containing the first sequence, FASTA format\n");
		printf("<sequence2>: file containing the second sequence, FASTA format\n");
		return EXIT_FAILURE;
	}

	if((A = malloc(MAX_SEQUENCE_LENGTH+2))==NULL) {
		errorExit("Could not allocate enough memory\n");
	}
	if((B = malloc(MAX_SEQUENCE_LENGTH+2))==NULL) {
		errorExit("Could not allocate enough memory\n");
	}

	doInput(argv[1],argv[2]);

	numDiags = lenA+lenB+3;
	offset = lenA + 1;

#ifdef DEBUG
printf("lenA = %d, lenB = %d\n",lenA,lenB); fflush(stdin);
printf("offset = %d\n", offset);
#endif

	score = editCost(A,B);
	printf("%d\n", score);

	freeMemory();
	return EXIT_SUCCESS;
}
