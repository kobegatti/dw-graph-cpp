#include <iostream>
#include "utils.hpp"

#define MAXLINE 31

int getIntFromString(void)
{
	char line[MAXLINE];
	char* end;
	errno = 0;
	int i;

	getLine(line, MAXLINE);
	i = strtol(line, &end, 10);

	if (errno == ERANGE || end == line)
	{
		fprintf(stderr,
			"Errno %d: No valid int conversion from '%s'\n", 
			errno, line);
		return -1;
	}

	return i;
}

/* K&R C Programming Language 2nd Edition Page 30 */
int getLine(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=std::getchar())!=EOF && c!='\n'; ++i)
	{
		s[i] = c;
	}

	s[i] = '\0';

	/* If input was too long, flush the remainder of the input buffer */
	if (c != '\n')
	{
		while ((c = std::getchar()) != EOF && c != '\n');
	}

	return i;
}