#include <unordered_map>
#include <vector>

class Graph
{
    public:

        Graph() : V_E{} {}

        Graph(std::unordered_map<int, std::vector<int>> v_e)
        {
            V_E = v_e;
        }

        ~Graph() {}

        bool addVertex(int v);
        bool addEdge(int start, int end);

    private:
        std::unordered_map< int, std::vector<int> > V_E;
};

bool Graph::addVertex(int v)
{
    if (V_E.count(v) == 0)
    {
        V_E.insert({v, std::vector<int>()});
        return true;
    }

    return false;
}

bool Graph::addEdge(int start, int end)
{
    if (V_E.count(start))
    {
        V_E[start].push_back(end);
        return true;
    }

    return false;
}