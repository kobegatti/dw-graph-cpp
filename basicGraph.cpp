#include <iostream>
#include <unordered_map>
#include <vector>
#include "basicGraph.hpp"

// Constructors
BasicGraph::BasicGraph() : V_E{} {}

BasicGraph::BasicGraph(std::unordered_map<int, std::vector<int>> v_e)
{
    V_E = v_e;
}

// Destructor
BasicGraph::~BasicGraph() {}

// Methods
bool BasicGraph::addVertex(int v)
{
    if (V_E.count(v) == 0)
    {
        V_E.insert({v, std::vector<int>()});
        return true;
    }

    return false;
}

bool BasicGraph::addEdge(int start, int end)
{
    if (V_E.count(start) && V_E.count(end))
    {
        V_E[start].push_back(end);
        return true;
    }

    return false;
}

void BasicGraph::printGraph()
{
    for (const auto& pair : V_E)
    {
        std::cout << "Vertex " << pair.first << ": ";

        for (int neighbor : pair.second)
        {
            std::cout << neighbor << " ";
        }

        std::cout << std::endl;
    }
}