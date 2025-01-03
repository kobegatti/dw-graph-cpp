#ifndef UTILS_HPP
#define UTILS_HPP

#define FILE_READ 0
#define FILE_WRITE 1
#define ADD_VERTEX 2
#define REMOVE_VERTEX 3
#define ADD_EDGE 4
#define REMOVE_EDGE 5
#define PRINT 6
#define CLEAR_GRAPH 7
#define BREADTH_FIRST_SEARCH 8
#define DEPTH_FIRST_SEARCH 9
#define EXIT 10
#define MAXLINE 31
#define MAX_FILE_PATH 255

#include <iostream>

bool getIntFromString(int* i);

/* K&R C Programming Language 2nd Edition Page 30 */
int getLine(char s[], int lim); /* read a line into s, return length */

void printMenu();

#endif