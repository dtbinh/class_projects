while(tid<M)
i=tid/ ind_size; //the k index
j=tid % ind_size; //the size index
Sequence seq1 =Index_Table[i];
Sequence seq2= Index_Table[j];
if(i!=j)
	Sequence seq3;
m_g = max(((seq2.lead.i)-(seq.trail.i)),((seq2.lead.j)-(seq.trail.j)));
if Rule (1) Applied
	1- Fill sequence 3 so that its (i,j) lead is equal to Sequence1 and its (i,j)trail is 
equal to Sequence2.
2- seq3.score = seq.score + seq2.score - m_g - 2;
3- seq3.m_g = seq.m_g + seq2.m_g + m_g;
4- Mod_Ind_table[tid]=seq3;
else if Rule (2) Applied
	1- Fill sequence 3 so that its (i,j)lead is equal to Sequence1 and its (i,j)trail is equal 
to Sequence2.
2- seq3.score =seq.score + seq2.score - (m_g - 1);
3- seq3.m_g = seq.m_g + seq2.m_g + m_g - 1;
4- Mod_Ind_table[tid]=seq3;
end if
end if