#ifndef UTILS_HPP
#define UTILS_HPP

#define FILE_READ 0
#define ADD_VERTEX 1
#define REMOVE_VERTEX 2
#define ADD_EDGE 3
#define REMOVE_EDGE 4
#define PRINT 5
#define BREADTH_FIRST_SEARCH 6
#define EXIT 9
#define MAXLINE 31
#define MAX_FILE_PATH 255

#include <iostream>

bool getIntFromString(int* i);

/* K&R C Programming Language 2nd Edition Page 30 */
int getLine(char s[], int lim); /* read a line into s, return length */

void printMenu();

#endif