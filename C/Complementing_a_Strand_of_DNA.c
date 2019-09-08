#include <stdio.h>
#include <stdlib.h>
/*
Description:The reverse complement of a DNA string s is the string sc formed by reversing the symbols of s, 
then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC")
input: string of DNA
output: string of replication DNA
return values:None

restrictions: lenght of DNA sequence at most 11


*/
char * ft_reverse(char *str)
{
	char *tmp, ex;
	tmp = str;
	int lenght = 0;
	while(*tmp){
		lenght++;
		tmp++;
	}
	char *start = str;
        char *end = str+lenght-1;
	while(start<end){
		ex = *start;
        	*start = *(end);
		*end = ex;
		start++;
		end--;


       }
	return str;
}
char * ft_putstr(char *str)
{
        char *p_symbol;
	p_symbol = str;
	char a = 'A';
        char t = 'T';
	char g = 'G';
	char c = 'C';
        while(*p_symbol)
        {

                if(*p_symbol == t)
                {
                        *p_symbol = a;
		}
		else	if(*p_symbol == a)
                {
                        *p_symbol = t;
                }
		else	if(*p_symbol == g)
                {
                        *p_symbol = c;
		}
		else if(*p_symbol == c)
                {
                	*p_symbol = g;
		}
		p_symbol++;
        }
	return str;
}
int main(void)
{
        char *str1;

	str1 = (char*)malloc(11 * sizeof(char));
	scanf("%s", str1);
	printf("%s",ft_putstr(ft_reverse(str1)));
        return 0;
}
