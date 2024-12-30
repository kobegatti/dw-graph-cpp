#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

#include <vector>
#include <unordered_map>

class BasicGraph
{
    public:

        // Constructors
        BasicGraph();
        BasicGraph(std::unordered_map<int, std::vector<int>> v_e);

        // Destructor
        ~BasicGraph();

        // Methods
        bool addVertex(int v);
        bool addEdge(int start, int end);
        void printGraph();

    private:
        std::unordered_map< int, std::vector<int> > V_E;
};

#endif