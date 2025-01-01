#ifndef UTILS_HPP
#define UTILS_HPP

#define FILE_READ 0
#define ADD_VERTEX 1
#define ADD_EDGE 2
#define PRINT 3
#define BREADTH_FIRST_SEARCH 4
#define EXIT 7
#define MAXLINE 31
#define MAX_FILE_PATH 255

#include <iostream>

bool getIntFromString(int* i);

/* K&R C Programming Language 2nd Edition Page 30 */
int getLine(char s[], int lim); /* read a line into s, return length */

void printMenu();

#endif