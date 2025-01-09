#ifndef DWGRAPH_HPP
#define DWGRAPH_HPP

#include <fstream>
#include <unordered_map>
#include <utility>
#include <set>

class DWGraph
{
    public:

        // Constructor
        DWGraph();

        // Destructor
        ~DWGraph();

        // Operators
        bool operator==(const DWGraph& other) const;

        // Methods
        const std::unordered_map<int, std::set<int>>* getVEs();
        bool jsonToGraph(std::string path);
        bool graphToJson(std::string path);
        bool addVertex(int v);
        bool removeVertex(int v);
        bool addEdge(int start, int end);
        bool removeEdge(int start, int end);
        void printGraph();
        void clearGraph();

        // Breadth First Search
        // Input: Start node 'root'
        // Output: Each vertex's distance from root
        std::unordered_map<int, int> BFS(int root); 

        // Depth First Search
        // Input: Start node 'root'
        // Output: Each vertex's pre and post-orderings from root
        std::unordered_map<int, std::pair<int, int>> DFS(int root);

    private:
        int explore(int vertex,
                int currentVisitTime,
                std::unordered_map<int, bool>& visited, 
                std::unordered_map<int, std::pair<int, int>>& vertsAndVisits);

        std::unordered_map<int, std::set<int>> V_E;
};

#endif