#include "basicGraph.hpp"

BasicGraph::BasicGraph() {}

BasicGraph::BasicGraph(std::unordered_map<int, std::vector<int>> v_e)
{
    V_E = v_e;
}

BasicGraph::~BasicGraph() {}

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
    if (V_E.count(start))
    {
        V_E[start].push_back(end);
        return true;
    }

    return false;
}