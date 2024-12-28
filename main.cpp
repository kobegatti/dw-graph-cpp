#include <iostream>
#include "utils.hpp"

#define EXIT 7

void printMenu();

int main()
{
    int n = -1;

    while (n != EXIT)
    {
        std::cout << "Basic-Graph:\n";
        printMenu();

        std::cout << "Select an option: ";
        n = getIntFromString();

        switch(n)
        {
            case 1:
                break;
            case EXIT:
                std::cout << "Exiting program...\n";
                break;
        }
    }

    return 0;
}

void printMenu()
{
    std::cout << "7. Exit\n";
}