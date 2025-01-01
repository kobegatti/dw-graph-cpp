#include <iostream>
#include <sstream>
#include "../header/basicGraph.hpp"
#include "../external/json/include/nlohmann/json.hpp"

// Constructor
BasicGraph::BasicGraph() : V_E{} {}

// Destructor
BasicGraph::~BasicGraph() {}

// Methods
bool BasicGraph::jsonToMap(std::string path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error: opening file '" << path << "'\n";
        return false;
    }

    std::stringstream ss;
    ss << file.rdbuf();
    std::string raw_str = ss.str();
    
    nlohmann::json json;
    try
    {
        json = nlohmann::json::parse(raw_str);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    for (const auto& [vertex, edges] : json.items())
    {
        int v;
        try
        {
            v = std::stoi(vertex);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        addVertex(v);

        if (!edges.is_array())
        {
            std::cerr << "Error: edge list for v" << v << " is not an array.\n";
            return false;
        }

        for (auto& e : edges)
        {
            if (!e.is_number_integer())
            {
                std::cerr << "Error: edge '" << e << "' is not an int\n";
                return false;
            }

            addEdge(v, e);
        }
    }

    return true;
}

bool BasicGraph::addVertex(int v)
{
    if (V_E.count(v) == 0)
    {   
        V_E.insert({v, std::set<int>()});
        return true;
    }

    return false;
}

bool BasicGraph::removeVertex(int v)
{
    if (V_E.count(v) == 0)
    {
        return false;
    }

    for (auto& vE : V_E)
    {
        vE.second.erase(v);
    }
    V_E.erase(v);

    return true;
}

void BasicGraph::addEdge(int start, int end)
{
    addVertex(start);
    addVertex(end);

    V_E[start].insert(end);
}

bool BasicGraph::removeEdge(int start, int end)
{
    if (V_E[start].count(end) == 0)
    {
        return false;
    }

    V_E[start].erase(end);
    return true;
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

std::unordered_map<int, int> BasicGraph::BFS(int root)
{
    if (V_E.count(root) == 0) { return {}; }
    
    std::unordered_map<int, int> verts_and_dists;
    std::queue<int> q;

    for (const auto& v : V_E)
    {
        verts_and_dists[v.first] = std::numeric_limits<int>::max();
    }
    verts_and_dists[root] = 0;

    q.push(root);
    while (!q.empty())
    {
        int currV = q.front();
        q.pop();

        for (const auto& neightbor : V_E[currV])
        {
            if (verts_and_dists[neightbor] == std::numeric_limits<int>::max())
            {
                q.push(neightbor);
                verts_and_dists[neightbor] = verts_and_dists[currV] + 1;
            }
        }
    }

    return verts_and_dists;
}