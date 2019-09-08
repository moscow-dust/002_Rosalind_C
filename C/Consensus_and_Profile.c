#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Description:Their profile matrix is a 4×n matrix P in which P(1,j), 
represents the number of times that 'A' occurs in the jth position of one of the strings,
P(2,j) represents the number of times that C occurs in the jth position, and so on.
A consensus string c is a string of length n formed from our collection by taking the most common symbol
at each position; the jth symbol of c therefore corresponds to the symbol
having the maximum value in the j-th column of the profile matrix.
Of course, there may be more than one most common symbol, leading to multiple possible consensus strings.

input:file "../tests/Consensus_and_Profile.txt" is consisted at most 10 DNA strings in FASTA format (of length at most 1 kbp each)
output: profile_matrix, consensus string
return values:-1 - file not exist, 0 - successfully

restrictions: FASTA format, change 'A' to 'C', 'T' or 'G' in output matrix


*/
int ** profile_matrix(char **char_matrix, int n,int n1,int  *flag)
{
	int **res,i =0;
	*flag = 0;
	int j,k=0,counter1, counter3,counter2,counter4;
	res = (int**)malloc(3000 * sizeof(int*));
                        for (int l = 0; l < 3000; l++)
                        {
                              res[l] = (int *)malloc(3000*sizeof(int));
                        }
	for(j =0; j<n1;j++)
	{
		counter1=0;
		counter2 =0;
		counter3 =0;
		counter4 =0;
		for(i=0;i<=n;i++)
		{
			if(char_matrix[i][j] == 'A')
			{
				counter1++;
			}
			if(char_matrix[i][j] == 'C')
			{
				counter2++;
			}
			if(char_matrix[i][j] == 'G')
			{
				counter3++;
			}
			if(char_matrix[i][j] == 'T')
			{
				counter4++;
			}
		}
		res[k][0]=counter1;
		res[k][1] =counter2;
		res[k][2] = counter3;
		res[k][3] = counter4;
		k++;
		(*flag)++;
		
	}
	return res;
}

void transpose(int **res, int len, int transpose_matrix[4][len])
{	
	int i,j;
	for(i = 0; i<len; i++)
	{
		for(j=0; j<4; j++)
		{
			transpose_matrix[j][i] = res[i][j];
		}
    	}
}

char * consensus_string(int **res, int flag)
{
	char *consensus;
	consensus = (char*)malloc(1000 * sizeof(char));
	int g =0, max, max_index;
	for (int a =0;a<flag; a++)
        {
                max = res[a][0];
		max_index = 0;
                for(int p =0; p<4;p++)
                {
			if (res[a][p] > max)
   			{
       				max = res[a][p];
       				max_index = p;
    			}
		}
		if(max_index == 0)
		{
			consensus[g] = 'A';
			g++;
		}
		if(max_index == 1)
		{
			consensus[g] = 'C';
			g++;
		}
		if(max_index == 2)
                {
                        consensus[g] = 'G';
			g++;
                }
		if(max_index == 3)
                {
                        consensus[g] = 'T';
			g++;
                }
	}
return consensus;
}

int main()
{	
	char void_str[3000] = {'\0'};
	char **str1, **matrix_dna;
	int d =0,j =0, flag,len =0, len1;
	FILE * f;
       	f = fopen("../tests/Consensus_and_Profile.txt", "r");
	matrix_dna = (char**)malloc(20 * sizeof(char*));
                        for (int l = 0; l < 101; l++)
                        {
                              matrix_dna[l] = (char *)malloc(3000*sizeof(char));
                        }
	if (f ==NULL)
	{
		return -1;
	}
	else
	{
		str1 = (char**)malloc(1000 * sizeof(char*));
			for (int l = 0; l < 1001; l++)
			{                                  
                              str1[l] = (char *)malloc(3000*sizeof(char));
                        }
			while(fscanf (f, "%s", str1[j]) != EOF)
				{	
					if(str1[j][0]=='>')
					{
						j++;
						if (len!=0)
						{
						strcpy(matrix_dna[d], void_str);
						d++;
						memset(void_str, 0, sizeof(void_str));
						len =0;
						}	
					}
					else
					{
						strcat(void_str,str1[j]);
						len++;
						j++;
					}
	 		       }
	}
	 strcpy(matrix_dna[d], void_str);
         d++;
	 len1 = strlen(void_str);
         memset(void_str, 0, sizeof(void_str));
         len =0;
	int ** u = profile_matrix(matrix_dna, d,len1, &flag);
	int trans[4][len1];
	char *con = consensus_string(u, flag);
	transpose(u, len1, trans);
	for(int y =0; y<4; y++)
	{
		printf("\nA:");
                for(int z =0; z<len1;z++)
		{
			 printf("%d", trans[y][z]);
			  printf(" ");
		}
	}
	printf("%s", con);
	return 0;
}
