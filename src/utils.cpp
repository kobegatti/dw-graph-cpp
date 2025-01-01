#include "../header/utils.hpp"

bool getIntFromString(int* i)
{
	char line[MAXLINE];
	char* end;
	errno = 0;

	getLine(line, MAXLINE);
	*i = strtol(line, &end, 10);

	if (errno == ERANGE || end == line)
	{
		fprintf(stderr,
			"Errno %d: No valid int conversion from '%s'\n", 
			errno, line);
		return false;
	}

	return true;
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

void printMenu()
{
	std::cout << FILE_READ << ". File Read\n";
    std::cout << ADD_VERTEX << ". Add vertex\n";
	std::cout << REMOVE_VERTEX << ". Remove Vertex\n";
    std::cout << ADD_EDGE << ". Add edge\n";
	std::cout << REMOVE_EDGE << ". Remove edge\n";
    std::cout << PRINT << ". Print graph\n";
    std::cout << BREADTH_FIRST_SEARCH << ". Breadth First Search\n";
    std::cout << EXIT << ". Exit\n";
}