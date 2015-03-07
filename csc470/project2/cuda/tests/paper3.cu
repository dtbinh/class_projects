tid= threadIdx.x+ blockIdx.x*blockDim.x;
While ( tid<N)
Get neculidiede from S and T where 
i=tid % n; // i=1… n. 
j=tid/ n; // j=1… m.
if(S[i]==T[j])
	devMatrix[tid]=2;
else
	devMatrix [tid]=0;
end if
tid+=blockDim.x*gridDim.x;
end while