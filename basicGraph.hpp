#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

#include <iostream>
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
        bool addVertex(int v);
        bool addEdge(int start, int end);
        void printGraph();
        std::unordered_map<int, unsigned int> BFS(int root);

    private:
        std::unordered_map<int, std::set<int>> V_E;
};

#endif