#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
Description:The GC-content of a DNA string is given by the percentage of symbols in the string that are 'C' or 'G'.
For example, the GC-content of "AGCTATAG" is 37.5%. 
Note that the reverse complement of any DNA string has the same GC-content.

input:file "../tests/Computing_GC_Content.txt" is consisted at most 10 DNA strings in FASTA format (of length at most 1 kbp each)
output: float percentage of 'C' and 'G', string with name of DNA with max percentage of 'C' and 'G'
return values:-1 - file not exist, 0 - successfully

restrictions: FASTA format, lenght of DNA sequences<100


*/

int search_max_index(float *arr, int n)
{
		float max = arr[0];
	int index = 0;
		for(int i = 0; i<n; i++){
		
				if (arr[i] > max)
				{
						max = arr[i];
						index = i;
				}
		}
	 return index;
}

int main(void)
{
	int j = 0, k, d = 0,  u = 0, r = 0, size =0;
	char **dna;
	float *percent, result,len = 0, counter = 0;
	dna = (char**)malloc(10 * sizeof(char*));
	for (int i = 0; i < 11; i++)
	{
		dna[i] = (char *)malloc(10 * sizeof(char));
	}
	percent = (float*)malloc(10 * sizeof(float));
	char **str1;
	FILE * f;
	   	f = fopen("../tests/Computing_GC_Content.txt", "r");
	if (f ==NULL)
	{
		return -1;
	}
	else
	{
		str1 = (char**)malloc(20 * sizeof(char*));
		for (int l = 0; l < 101; l++)
		{                                  
			  str1[l] = (char *)malloc(100*sizeof(char));
		}
		while(fscanf (f, "%s", str1[j]) != EOF)
			{	
				if(str1[j][0]=='>')
				{
					dna[d] = str1[j];
					d++;
					j++;
					if(len!=0)
					{
						result = (((counter)/(len))*100);
						percent[u] = result;
						u++;
						size++;
						len = 0;
						counter = 0;
					}
				}
				else
					{
						len  = len+strlen(str1[j]);	 
						for(int h=0;h<(strlen(str1[j])); h++)
												{
							if((str1[j][h] == 'G') ||(str1[j][h] == 'C'))
											{
								counter++;					
							}
						}
						j++;
					}
			}
			result = (((counter)/(len))*100);
 			percent[u] = result;
			size++;
			int MaxIndex = search_max_index(percent, size);
			printf("%s", dna[MaxIndex]);
			printf("\n");
			printf("%f", percent[MaxIndex]);
	}
	fclose(f);
	return 0;
	
}
