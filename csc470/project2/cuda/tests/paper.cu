tid= threadIdx.x+ blockIdx.x*blockDim.x;
While ( tid<N)
Get neculidiede from S and T where 
i=tid % n; // i=1… n. 
j=tid/ n; // j=1… m.
updiag= tid - (n+1);
downdiag= tid + n +1;
if(devMatrix [tid]==0)ResultMatrix[tid]=0;
else if (devMatrix [tid]!=0)
	if(((i==0) AND (j==m-1))OR((i==n-1) AND 
(j==0))) //top left & bottom right
		ResultMatrix [tid] = 2;
else if((i==0)OR(j==0)) // up & left
	if(devMatrix[downdiag]==0)
		ResultMatrix [tid]=2;
	else
		ResultMatrix [tid]=4;
	end if
else if((i==n-1)OR (j==m-1))//down&right
	if(devMatrix[updiag]==0)
		ResultMatrix [tid]=2;
	else
		ResultMatrix [tid]=4;
	end if
	else
		if((devMatrix[updiag]==0)AND 
			(devMatrix[downdiag]==0))
			ResultMatrix [tid]=2;
		else if((devMatrix[updiag]!=0 AND
			devMatrix [downdiag]==0)
			OR(devMatrix [updiag]==0 AND
				devMatrix [downdiag]!=0))
			ResultMatrix [tid]=4;
		else if((devMatrix [updiag]!=0 AND
			devMatrix [downdiag]!=0))
			ResultMatrix [tid]=6;
		end if
		end if
		end if
		tid+=blockDim.x*gridDim.x;
		end While
