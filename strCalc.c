#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "strCalc.h"


#define MAX_DELIM_CHARS 100
#define INITIAL_DELIMS " ,\n"
#define NEW_DELIM_SYNTAX "//"
static char delims[MAX_DELIM_CHARS] = {0};

//fwd decs
bool tokenIsNewDelim(char* token);


int Add(char *str)
{
	int sum = 0;
	char *token = NULL;
	
	// init delims
	strncpy(delims,INITIAL_DELIMS,MAX_DELIM_CHARS-1);

	// tokenize string
	token = strtok(str,delims);

	while (token != NULL)
	{
		// if it's a new token, add it to the list of tokens
		if (tokenIsNewDelim(token))
		{
			//todo buffer overrun with many new delims.
			strncat(delims,token,10);
		} 
		// else read it to see if it's a number
		else
		{
			int numRead = 0;
			// if the token was a number, accumulate it
			if (1 == sscanf(token,"%d",&numRead))
			{
				sum +=numRead;
			}
		}
	
		// get the next token
		token = strtok(NULL,delims);
	}

	//return sum
	return sum;
}


// token = word to analyze
bool tokenIsNewDelim(char *token)
{
	if (0 == strncmp(token,NEW_DELIM_SYNTAX,2))
	{
		// strip the "//"
		token = &(token[2]);
		return true;
	}
	return false;
}

