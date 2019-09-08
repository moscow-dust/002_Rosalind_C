#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Description:Given two strings s and t of equal length, the Hamming distance between s and t,
is the number of corresponding symbols that differ in s and t. 
input: file "../tests/Consensus_and_Profile.txt" with two equal string of DNA
output: Hamming distance
return values:None

restrictions: lenght of DNA sequence at most 1000


*/

int comparison(char *str1, char *str2, int n){
	int counter = 0;
	for(int i =0; i<n; i++){
		for( int j = 0; j<n; j++){
			if((str1[i] == str2[j])&& (i == j)){
				counter++;
			}
		}
	}
	return counter;
}
int main(void)
{
	char *str1, *str2;
	FILE * f;
       	f = fopen("../tests/Counting_Point_Mutations.txt", "r");
	if (f ==NULL)
	{
		return -1;
	}
	else
	{
	str1 = (char*)malloc(1000 * sizeof(char));
	str2 = (char*)malloc(1000 * sizeof(char));
	fscanf(f, "%s", str1);
	fscanf(f, "%s", str2);
	int d = strlen(str1);
	int result = d-comparison(str1, str2, d);
	printf("%d", result);

			}
        return 0;
}
