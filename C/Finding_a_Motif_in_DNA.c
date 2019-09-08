#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
Description:The location of a substring s[j:k] is its beginning position j;
note that t will have multiple locations in s if it occurs more than once as a substring of s.
input: string of DNA and substring at most 40 symbols
output: array of index substring into string
return values:None

restrictions: None


*/
int * ss_positions(char *ss,char *s, int *flag)
{
	int *res,h=0, j,i=0;
	*flag =0;

	res = (int*)malloc(40 * sizeof(int));
	while(s[i]!='\0')
	{
		if(s[i] == ss[0])
		{
			j = 1;
				while(ss[j] != '\0' && s[i+j] != '\0' && ss[j] == s[i+j])
				{
					j++;
				}
				if(ss[j] == '\0')
				{
					res[h]=i;
					h++;
					(*flag)++;
				}			
		}
		i++;
	}
	return res;
}

int main(void)
{
	char *s = "ATAATAGATA";
	int *u, flag;
	char *ss = "ATA";
	u = ss_positions(ss,s, &flag);
	while(flag)
	{
		printf("%d ", *u);
		u++;
		flag--;
	}
	return 0;
}
