#include "basicGraph.hpp"

// Constructor
BasicGraph::BasicGraph() : V_E{} {}

// Destructor
BasicGraph::~BasicGraph() {}

// Methods
bool BasicGraph::addVertex(int v)
{
    if (V_E.count(v) == 0)
    {
        V_E.insert({v, std::set<int>()});
        return true;
    }

    return false;
}

bool BasicGraph::addEdge(int start, int end)
{
    if (V_E.count(start) && V_E.count(end) && V_E[start].count(end) == 0)
    {
        V_E[start].insert(end);
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

std::unordered_map<int, unsigned int> BasicGraph::BFS(int root)
{
    if (V_E.count(root) == 0) { return {}; }
    
    std::unordered_map<int, unsigned int> vertices_and_dists = {{root, 0}};

    return vertices_and_dists;
}