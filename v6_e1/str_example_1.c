#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

void stringTrim(char str[])
{
	int_least32_t i = 0;
	int_least32_t j ;
	int_least32_t n = stringLength(str);

	while(str[i] == ' ')
	{
		i++;
	}
	for(j = 0; j<n-1;j++){
		str[j] = str[j+i];
	}

	while(str[j] == ' '){
		j--;
	}
	str[j+1]='\0';
}


int_least32_t stringLength(const char str[])
{
	int_least32_t i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}

int_least8_t extractSubstring(const char inStr[], char outStr[], int_least32_t beginning, int_least32_t end)
{
	int_least32_t i;
	int_least32_t n = stringLength(inStr);
	if(n > (end - beginning))
	{
		for(i = 0; i<(end - beginning);i++)
		{
			outStr[i] = inStr[beginning+i];
		}
		return 1;

	} else return 0;
}

int8_t concatenateStrings(char str1[], const char str2[]){
	int_least32_t n = stringLength(str1);
	int_least32_t k = stringLength(str2);
	int_least32_t i;

	for(i = 0; i<k; i++)
	{
		str1[n+i] = str2[i];
	}
	return 1;
}
void main(){
	int_least32_t len;
	char string[] = " Kojic Telep ";
	char string1[20];
	char string2[] = " !!!";

	len = stringLength(string);
	printf("String length is %"PRIdLEAST32"\n", len);

	stringTrim(string);
	printf("Withoud spaces at beg and end:  %s \n" ,string);

	extractSubstring(string, string1, 3, 7);
	printf("Substring: %s \n" ,string1);

	concatenateStrings(string, string2);
	printf("Concatenated string: %s \n" ,string);

}
