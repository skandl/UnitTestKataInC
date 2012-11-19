#include <stdio.h>
#include <string.h>
#include "strCalc.h"

#define MAX_NUMS 3
const char DELIMS[] = " ,";

int Add(char *str)
{
	int numWordsFound = 0;
	int sum = 0;

	// handl null input
	if (str == NULL) return 0;

	//printf("string %s\n",str);

	char *token = NULL;
	token = strtok(str,DELIMS);	
	while (numWordsFound < MAX_NUMS) { 
	
		// if it's a word, check if it's a number
		if (token != NULL) { 
			int n = 0;
			if (1 == sscanf(token,"%d",&n)) { // it's a number
				sum += n;
			}
			token = strtok(NULL,DELIMS);	
		} else {     		// reached end of string
			break;
		}	
	}	

	//printf("sum: %d\n",sum);

	return sum;
}



