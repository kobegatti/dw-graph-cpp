#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

#include <fstream>
#include <unordered_map>
#include <set>

class BasicGraph
{
    public:

        // Constructor
        BasicGraph();

        // Destructor
        ~BasicGraph();

        // Methods
        bool jsonToMap(std::string path);
        bool addVertex(int v);
        bool addEdge(int start, int end);
        void printGraph();

        // Breadth First Search
        // Input: Start node 'root'
        // Output: Each vertex's distance from root
        std::unordered_map<int, int> BFS(int root); 

    private:
        std::unordered_map<int, std::set<int>> V_E;
};

#endif