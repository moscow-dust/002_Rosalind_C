#include<stdio.h>
#include<stdlib.h>
/*
Description:Our aim is to somehow modify this recurrence relation to achieve a dynamic
programming solution in the case that all rabbits die out after a fixed number of months.
for example a rabbit tree in which rabbits live for three months 
(meaning that they reproduce only twice before dying).
input: m - duration of rabbits life, n - amount of months
output: amount of rabbits after n months
return values:None

restrictions: n must be less than real value on 2, for exemple n=56, you must write 54


*/

long int ft_summary(int m, int i, long int *borned)
{
	long int sum=0;
	while(m!=1)
	{
		sum+=borned[i-m];
		m--;
	}
	return sum;
}

long int ft_insert(int m, int i, long int *borned)
{
	long int amount_of_rabbits=0;
	while(m)
	{
		amount_of_rabbits+=borned[i-m+1];
		m--;
	}
	return amount_of_rabbits;
}

int main(void)
{
	long int *borned=(long int*)malloc(100*sizeof(long int));
	borned[0]=1;
	borned[1]=0;
	int m = 17, n=85, i=2;
	long int n1=0, n2=1;
	while(n)
	{
		if(i<=m+1)
		{
			borned[i]=n1+n2;
			n2=n1;
			n1=borned[i];
			i++;
		}
		else
		{
			borned[i]=ft_summary(m, i, borned);
			i++;
		}
		n--;
	}
	printf("%ld",ft_insert(m, i, borned));
	return 0; 
}
