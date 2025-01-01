#include "../header/basicGraph.hpp"
#include <iostream>
// #include <sstream>
// #include <string>

// #define DELIMITER ':'
// #define INT_DIGITS "0123456789"
// #define LEFT_BRACKET '['
// #define RIGHT_BRACKET ']'

// Constructor
BasicGraph::BasicGraph() : V_E{} {}

// Destructor
BasicGraph::~BasicGraph() {}

// Methods
bool BasicGraph::jsonToMap(std::string path)
{
    // std::ifstream file(path);

    // if (!file.is_open()) 
    // {
    //     std::cerr << "Error: opening file path '" << path << "'\n";
    //     return false; 
    // }

    // std::string content((std::istreambuf_iterator<char>(file)), 
    //                         std::istreambuf_iterator<char>());
    // //std::string raw_string = "R(" + content + ")";

    // V_E.clear();

    // std::string line;
    // // std::istringstream ss(raw_string);
    // std::istringstream ss(content);

    // while (std::getline(ss, line))
    // {
    //     size_t pos = line.find(DELIMITER);
    //     if (pos != std::string::npos)
    //     {
    //         int v;
    //         std::string v_str = line.substr(0, pos);

    //         v_str.erase(0, v_str.find_first_of(INT_DIGITS));
    //         v_str.erase(v_str.find_last_not_of(INT_DIGITS) + 1);

    //         try
    //         {
    //             v = std::stoi(v_str);
    //         }
    //         catch (const std::exception e)
    //         {
    //             std::cerr << e.what() << std::endl;
    //             return false;
    //         }

    //         size_t start_pos = line.find(LEFT_BRACKET);
    //         size_t end_pos = line.find(RIGHT_BRACKET);

    //         if (start_pos != std::string::npos && end_pos != std::string::npos)
    //         {
    //             std::string edges = line.substr(start_pos + 1, end_pos - start_pos - 1);

    //             std::istringstream e_ss(edges);
    //             std::string e_str;
    //             while (std::getline(e_ss, e_str))
    //             {
    //                 try
    //                 {
    //                     int e = std::stoi(e_str);
    //                     V_E[v].insert(e);
    //                 }
    //                 catch(const std::exception& e)
    //                 {
    //                     std::cerr << e.what() << '\n';
    //                     return false;
    //                 }
                    
    //             }
    //         }
    //     }
    // }

    // return false;
    return false;
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

std::unordered_map<int, int> BasicGraph::BFS(int root)
{
    if (V_E.count(root) == 0) { return {}; }
    
    std::unordered_map<int, int> verts_and_dists;
    std::queue<int> q;

    for (const auto& v : V_E)
    {
        verts_and_dists[v.first] = INT_MAX;
    }
    verts_and_dists[root] = 0;

    q.push(root);
    while (!q.empty())
    {
        int currV = q.front();
        q.pop();

        for (const auto& neightbor : V_E[currV])
        {
            if (verts_and_dists[neightbor] == INT_MAX)
            {
                q.push(neightbor);
                verts_and_dists[neightbor] = verts_and_dists[currV] + 1;
            }
        }
    }

    return verts_and_dists;
}