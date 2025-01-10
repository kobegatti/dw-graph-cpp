#include "../header/basicGraph.hpp"
#include <assert.h>
#include <iostream>

#define PATH1 "data/graph1.json"
#define PATH2 "data/graph2.json"
#define PATH4 "data/graph4.json"
#define PATH5 "data/graph5.json"
#define PATH5_COPY "data/graph5-copy.json"
#define PATH6 "data/graph6.json"

// File Read
void testFileRead(DWGraph* g, std::string path, DWGraph* expected)
{
    g->jsonToGraph(path);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

// File Write
void testFileWrite(DWGraph* g, std::string path, DWGraph* expected)
{
    g->graphToJson(path);
    expected->jsonToGraph(path);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

// Add/Remove Vertices and Edges
void testAddRemove1(DWGraph* g, DWGraph* expected)
{
    assert(*g==*expected);

    g->addVertex(1);
    assert(!(*g==*expected));

    g->removeVertex(1);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

void testAddRemove2(DWGraph* g, DWGraph* expected)
{
    assert(*g==*expected);

    expected->addVertex(1);

    g->addVertex(1);
    g->addVertex(2);
    g->addEdge(1, 2);
    assert(!(*g==*expected));

    g->removeVertex(2);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

void testAddRemove3(DWGraph* g, DWGraph* expected)
{
    assert(*g==*expected);

    expected->addVertex(3);
    expected->addVertex(5);

    g->addVertex(3);
    g->addVertex(5);
    g->addVertex(1);
    g->addEdge(3, 1);
    assert(!(*g==*expected));

    g->removeVertex(1);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

void testAddRemove4(DWGraph* g, DWGraph* expected)
{
    assert(*g==*expected);

    expected->addVertex(1);
    expected->addVertex(2);
    expected->addVertex(3);;
    expected->addVertex(5);
    expected->addEdge(1, 2);

    g->addVertex(1);
    g->addVertex(2);
    g->addVertex(3);
    g->addVertex(4);
    g->addVertex(5);
    g->addEdge(1, 2);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    assert(!(*g==*expected));

    g->removeEdge(3, 5);
    g->removeVertex(4);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

void testAddRemove5(DWGraph* g, DWGraph* expected)
{
    assert(*g==*expected);

    expected->addVertex(1);
    expected->addVertex(2);
    expected->addVertex(3);
    expected->addEdge(1, 2);
    expected->addEdge(1, 3);
    expected->addEdge(2, 3);
    expected->addEdge(3, 2);
    expected->addVertex(4);
    expected->addEdge(4, 2);
    expected->addEdge(4, 3);

    g->addVertex(1);
    g->addVertex(2);
    g->addVertex(3);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 3);
    g->addEdge(3, 2);
    g->addVertex(4);
    g->addEdge(4, 2);
    g->addEdge(4, 3);
    g->addEdge(1, 4);
    assert(!(*g==*expected));

    g->removeEdge(1, 4);
    assert(*g==*expected);

    g->clearGraph();
    expected->clearGraph();
}

// BFS
template<typename ValueType>
bool compareMaps(const std::unordered_map<int, ValueType>& m1, 
                    const std::unordered_map<int, ValueType>& m2)
{
    if (m1.size() != m2.size()) { return false; }

    for (const auto& pair : m1)
    {
        if (m2.find(pair.first) == m2.end() || m2.at(pair.first) != pair.second)
        {
            return false;
        }
    }

    return true;
}
void testBFS(DWGraph* graph, int root, std::unordered_map<int, int>& expected)
{
    std::unordered_map<int, int> actual = graph->BFS(root);

    assert(compareMaps(actual, expected));
    graph->clearGraph();
}

// DFS
void testDFS(DWGraph* graph, int root, std::unordered_map<int, std::pair<int, int>>& expected)
{
    std::unordered_map<int, std::pair<int, int>> actual = graph->DFS(root);

    assert(compareMaps(actual, expected));
    graph->clearGraph();
}

int main()
{
    DWGraph graph, expected;

    std::cout << "Test File Read\n";
    expected.addVertex(1);
    expected.addVertex(2);
    expected.addVertex(3);
    expected.addEdge(1, 2);
    expected.addEdge(2, 3);
    expected.addEdge(3, 1);
    testFileRead(&graph, PATH4, &expected);

    expected.addVertex(1);
    testFileRead(&graph, PATH5, &expected);

    std::cout << "Test File Write\n";
    graph.addVertex(1);
    testFileWrite(&graph, PATH5_COPY, &expected);

    std::cout << "Test Add/Remove\n";
    testAddRemove1(&graph, &expected);
    testAddRemove2(&graph, &expected);
    testAddRemove3(&graph, &expected);
    testAddRemove4(&graph, &expected);
    testAddRemove5(&graph, &expected);

    std::cout << "Test BFS\n";
    graph.jsonToGraph(PATH4);
    std::unordered_map<int, int> expectedBFS1 = {{1, 0}, {2, 1}, {3, 2}};
    testBFS(&graph, 1, expectedBFS1);

    graph.jsonToGraph(PATH6);
    std::unordered_map<int, int> expectedBFS2 = {{1, 0}, {2, 1}, {3, 1}};
    testBFS(&graph, 1, expectedBFS2);

    graph.jsonToGraph(PATH2);
    std::unordered_map<int, int> expectedBFS3 = {{8, 0},
                                                {0, INT_MAX},
                                                {1, INT_MAX},
                                                {2, INT_MAX},
                                                {3, INT_MAX},
                                                {4, INT_MAX},
                                                {5, INT_MAX},
                                                {6, INT_MAX},
                                                {7, INT_MAX}};
    testBFS(&graph, 8, expectedBFS3);

    graph.jsonToGraph(PATH2);
    std::unordered_map<int, int> expectedBFS4 = {{8, INT_MAX},
                                                {0, 2},
                                                {1, 1},
                                                {2, 1},
                                                {3, 0},
                                                {4, 1},
                                                {5, 1},
                                                {6, 2},
                                                {7, 2}};
    testBFS(&graph, 3, expectedBFS4);

    std::cout << "Test DFS\n";
    graph.jsonToGraph(PATH4);
    std::unordered_map<int, std::pair<int, int>> expectedDFS1 = {{1, {1, 6}}, 
                                                                {2, {2, 5}},
                                                                {3, {3, 4}}};
    testDFS(&graph, 1, expectedDFS1);

    graph.jsonToGraph(PATH4);
    std::unordered_map<int, std::pair<int, int>> expectedDFS2 = {{2, {1, 6}},
                                                                {3, {2, 5}},
                                                                {1, {3, 4}}};
    testDFS(&graph, 2, expectedDFS2);

    graph.jsonToGraph(PATH1);
    std::unordered_map<int, std::pair<int, int>> expectedDFS3 = {{1, {1, 16}},
                                                                {0, {2, 3}},
                                                                {3, {4, 15}},
                                                                {2, {5, 6}},
                                                                {4, {7, 8}},
                                                                {5, {9, 14}},
                                                                {6, {10, 11}},
                                                                {7, {12, 13}}};
    testDFS(&graph, 1, expectedDFS3);

    graph.jsonToGraph(PATH5);
    std::unordered_map<int, std::pair<int, int>> expectedDFS4 = {{1, {1, 2}}};
    testDFS(&graph, 1, expectedDFS4);

    graph.jsonToGraph(PATH2);
    std::unordered_map<int, std::pair<int, int>> expectedDFS5 = {{4, {1, 16}},
                                                                {3, {2, 15}},
                                                                {1, {3, 12}},
                                                                {0, {4, 5}},
                                                                {5, {6, 11}},
                                                                {6, {7, 8}},
                                                                {7, {9, 10}},
                                                                {2, {13, 14}},
                                                                {8, {17, 18}}};
    testDFS(&graph, 4, expectedDFS5);

    return 0;
}