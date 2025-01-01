#include "../header/basicGraph.hpp"
#include "../header/utils.hpp"

int main()
{
    BasicGraph bG;
    int choice = -1;

    while (choice != EXIT)
    {
        std::cout << "\nBasic-Graph:\n";
        printMenu();

        std::cout << "Select an option: ";
        while (!getIntFromString(&choice))
        {
            std::cout << "Select an option: ";
        };

        switch(choice)
        {
            case FILE_READ:
            {
                char buf[MAX_FILE_PATH] = "";
                std::cout << "FilePath: ";
                getLine(buf, MAX_FILE_PATH);

                bG.jsonToMap(buf);
                break;
            }
            case ADD_VERTEX:
            {
                int v;
                std::cout << "Enter vertex number (int): ";
                while (!getIntFromString(&v))
                {
                    std::cout << "Enter vertex number (int): ";
                };

                if (bG.addVertex(v))
                {
                    std::cout << "v" << v << " added\n";
                }
                else
                {
                    std::cerr << "Error: v" << v << " already in graph\n";
                }
                break;
            }
            case ADD_EDGE:
            {
                int s, e;
                std::cout << "Enter starting node (int): ";
                while (!getIntFromString(&s))
                {
                    std::cout << "Enter starting node (int): ";
                };

                std::cout << "Enter ending node (int): ";
                while (!getIntFromString(&e))
                {
                    std::cout << "Enter ending node (int): ";
                };

                bG.addEdge(s, e);
                std::cout << "Edge (" << s << ")"<< "->" << "(" << e << ") added\n";
                break;
            }
            case PRINT:
            {
                bG.printGraph();
                break;
            }
            case BREADTH_FIRST_SEARCH:
            {
                int root;
                std::cout << "Enter root node (int): ";
                while (!getIntFromString(&root))
                {
                    std::cout << "Enter root node (int): ";
                };

                std::unordered_map<int, int> verts_and_dists = bG.BFS(root);

                for (auto const& vD : verts_and_dists)
                {
                    std::cout << "v" << vD.first << ": " << "dist=" << vD.second << std::endl;
                }
                break;
            }
            case EXIT:
            {
                std::cout << "Exiting program...\n";
                break;
            }
            default:
            {
                std::cerr << "Error: '" << choice << "' is an invalid choice\n";
                break;
            }
        }
    }

    return 0;
}