#ifndef BASICGRAPH_HPP
#define BASICGRAPH_HPP

#include <fstream>
#include <unordered_map>
#include <set>

class BasicGraph
{
    public:

        // Constructor
        BasicGraph();

        // Destructor
        ~BasicGraph();

        // Operators
        bool operator==(const BasicGraph& other) const;

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



    private:
        std::unordered_map<int, std::set<int>> V_E;
};

#endif