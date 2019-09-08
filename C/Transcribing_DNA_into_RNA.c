
#include <stdio.h>
#include <stdlib.h>
/*
Description:Given a DNA string t corresponding to a coding strand,
it transcribed RNA string u is formed by replacing all occurrences of 'T' in t with 'U' in u.
input: string of DNA
output: string of transcribing RNA
return values:None

restrictions: lenght of DNA sequence at most 9


*/
char * ft_putstr(char *str)
{
        char *p_symbol;
	p_symbol = str;
	char u = 'U';
        char t = 'T';
        while(*p_symbol)
        {

                if(*p_symbol == t)
                {
                        *p_symbol = u;
                }
                p_symbol++;

        }
	return str;
}

int main(void)
{
        char *str1;

	str1 = (char*)malloc(9 * sizeof(char));
	scanf("%s", str1);
	printf("%s", ft_putstr(str1));
        return 0;
}
