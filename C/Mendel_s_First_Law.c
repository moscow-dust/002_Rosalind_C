#include <stdio.h>
#include <stdlib.h>
/*
Description:None
input: Three positive integers k, m, and n, representing a population containing k+m+n organisms:
k individuals are homozygous dominant for a factor, m are heterozygous, and n are homozygous recessive.
output: The probability that two randomly selected mating organisms
will produce an individual possessing a dominant allele (and thus displaying the dominant phenotype). 
Assume that any two organisms can mate
return values:None

restrictions: None


*/
float probability_of_dominant_phenotype(float *dom,float *het, float *rec)
{
	float all = *dom + *rec + *het;
	float AAaa = *dom/(all)*(*rec)/(all-1);
	float AAAa= *dom/(all)*(*het)/(all-1);
	float AAAA =*dom/(all)*(*dom-1)/(all-1);
	float aaAa = *rec/(all)*(*het)/(all-1)*0.5;
	float aaAA = *rec/(all)*(*dom)/(all-1);
	float Aaaa = *het/(all)*(*rec)/(all-1)*0.5;
	float AaAA = *het/(all)*(*dom)/(all-1);
	float AaAa = *het/(all)*(*het-1)/(all-1)*0.75;
	float prob = AAaa+AAAa+AAAA+aaAa+aaAA+Aaaa+AaAA+AaAa;
	return prob;
}

int main()
{
	float dom = 20;
	float het = 28;
	float rec = 17;
	float result = probability_of_dominant_phenotype(&dom,&het, &rec);
	printf("%.5f", result);
}
