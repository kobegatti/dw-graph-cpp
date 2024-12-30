#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

#include <vector>
#include <unordered_map>

class BasicGraph
{
    public:

        BasicGraph();

        BasicGraph(std::unordered_map<int, std::vector<int>> v_e);

        ~BasicGraph();

        const std::unordered_map<int, std::vector<int>>& getAdjList()
        {
            return V_E;
        }

        bool addVertex(int v);
        bool addEdge(int start, int end);

    private:
        std::unordered_map<int, std::vector<int>> V_E;
};

#endif