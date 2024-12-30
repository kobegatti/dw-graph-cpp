#include <iostream>
#include "utils.hpp"
#include "basicGraph.hpp"

#define ADD_VERTEX 1
#define ADD_EDGE 2
#define PRINT 3
#define EXIT 7

void printMenu();

int main()
{
    BasicGraph bG;
    int n = -1;

    while (n != EXIT)
    {
        std::cout << "Basic-Graph:\n";
        printMenu();

        std::cout << "Select an option: ";
        n = getIntFromString();

        switch(n)
        {
            case ADD_VERTEX:
            {
                std::cout << "Enter vertex number (int): ";
                int v = getIntFromString();

                if (bG.addVertex(v))
                {
                    std::cout << "Successfully added " << v << std::endl;
                }
                else
                {
                    std::cerr << v << " already in graph" << std::endl;
                }
                break;
            }
            case ADD_EDGE:
            {
                std::cout << "Enter starting node (int): ";
                int s = getIntFromString();

                std::cout << "Enter ending node (int): ";
                int e = getIntFromString();

                if (bG.addEdge(s, e))
                {
                    std::cout << "Successfully added " << s << "->" << e << std::endl;
                }
                else
                {
                    std::cerr << s << " or " << e << " are not in graph" << std::endl;
                }
                break;
            }
            case PRINT:
            {
                bG.printGraph();
                break;
            }
            case EXIT:
            {
                std::cout << "Exiting program...\n";
                break;
            }
        }
    }

    return 0;
}

void printMenu()
{
    std::cout << "1. Add vertex\n";
    std::cout << "2. Add edge\n";
    std::cout << "3. Print graph\n";
    std::cout << "7. Exit\n";
}