#include <iostream>
#include <sstream>
#include <utility>
#include "../header/basicGraph.hpp"
#include "../external/json/include/nlohmann/json.hpp"

#define INDENT_SIZE 4

// Constructor
DWGraph::DWGraph() : V_E{} {}

// Destructor
DWGraph::~DWGraph() {}

// Operators
bool DWGraph::operator==(const DWGraph& other) const
{
    const std::unordered_map<int, std::set<int>>* m1 = &V_E;
    const std::unordered_map<int, std::set<int>>* m2 = &other.V_E;

    if (m1->size() != m2->size()) { return false; }

    for (const auto& pair1 : *m1)
    {
        int v1 = pair1.first;
        const std::set<int>& set1 = pair1.second;

        if (m2->find(v1) == m2->end()) { return false; }

        const std::set<int>& set2 = m2->at(v1);

        if (set1 != set2) { return false; }
    }

    return true;
}

// Methods
const std::unordered_map<int, std::set<int>>* DWGraph::getVEs()
{
    return &V_E;
}

bool tryOpenFile(const std::string path, std::fstream& fStream, const std::ios_base::openmode mode)
{
    fStream = std::fstream(path, mode | std::ios::binary);
    if (!fStream.is_open())
    {
        std::cerr << "Error: opening file '" << path << "'\n";
        return false;
    }

    return true;
}

bool DWGraph::jsonToGraph(std::string path)
{
    std::fstream fStream;
    if (!tryOpenFile(path, fStream, std::ios::in)) { return false; }

    std::stringstream ss;
    ss << fStream.rdbuf();
    std::string raw_str = ss.str();
    fStream.close();
    
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
            std::cerr << "Error: edge list for v" << v 
                        << " is not an array.\n";
            return false;
        }

        for (auto& e : edges)
        {
            if (!e.is_number_integer())
            {
                std::cerr << "Error: edge '" << e 
                            << "' is not an int\n";
                return false;
            }
            addVertex(e);
            addEdge(v, e);
        }
    }

    return true;
}

bool DWGraph::graphToJson(std::string path)
{
    std::fstream fStream;
    if (!tryOpenFile(path, fStream, std::ios::out)) { return false; }

    nlohmann::json json;
    for (const auto& vE : V_E)
    {
        json[std::to_string(vE.first)] = vE.second;
    }

    fStream << json.dump(INDENT_SIZE);
    fStream.close();

    return true;
}

bool DWGraph::addVertex(int v)
{
    if (V_E.count(v) != 0) { return false; }

    V_E.insert({v, std::set<int>()});
    return true;
}

bool DWGraph::removeVertex(int v)
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

bool DWGraph::addEdge(int start, int end)
{
    if (V_E.count(start) == 0 || V_E.count(end) == 0)
    {
        return false;
    }

    V_E[start].insert(end);
    return true;
}

bool DWGraph::removeEdge(int start, int end)
{
    if (V_E[start].count(end) == 0)
    {
        return false;
    }

    V_E[start].erase(end);
    return true;
}

void DWGraph::printGraph()
{
    for (const auto& pair : V_E)
    {
        std::cout << "v" << pair.first << ": ";

        for (int neighbor : pair.second)
        {
            std::cout << neighbor << " ";
        }

        std::cout << std::endl;
    }
}

void DWGraph::clearGraph()
{
    V_E.clear();
}

std::unordered_map<int, int> DWGraph::BFS(int root)
{
    if (V_E.count(root) == 0) 
    {
        std::cerr << "v" << root << " not in graph\n";
        return {}; 
    }
    
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

std::unordered_map<int, std::pair<int, int>> DWGraph::DFS(int root)
{
    std::unordered_map<int, std::pair<int, int>> verts_and_visits;
    std::unordered_map<int, bool> visited;
    int current_visit_time = 1;

    for (const auto& vE : V_E)
    {
        visited[vE.first] = false;
        verts_and_visits[vE.first] = {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
    }

    current_visit_time = explore(root, current_visit_time, visited, verts_and_visits);
    for (const auto& vE : V_E)
    {
        if (visited[vE.first] == false)
        {
            current_visit_time = explore(vE.first, current_visit_time, visited, verts_and_visits);
        }
    }

    return verts_and_visits;
}

int DWGraph::explore(int vertex,
                int currentVisitTime,
                std::unordered_map<int, bool>& visited, 
                std::unordered_map<int, std::pair<int, int>>& vertsAndVisits)
{
    visited[vertex] = true;
    vertsAndVisits[vertex].first = currentVisitTime;
    currentVisitTime++;

    for (const auto& e : V_E[vertex])
    {
        if (visited[e] == false)
        {
            currentVisitTime = explore(e, currentVisitTime, visited, vertsAndVisits);
        }
    }

    vertsAndVisits[vertex].second = currentVisitTime;
    currentVisitTime++;

    return currentVisitTime;
}