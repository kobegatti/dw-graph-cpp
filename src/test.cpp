#include "../header/basicGraph.hpp"
#include <assert.h>
#include <fstream>
#include <iostream>

#define PATH4 "data/graph4.json"
#define PATH5 "data/graph5.json"

// File Read
void testFileRead(BasicGraph* g, std::string path, BasicGraph* expected)
{
    g->jsonToMap(path);
    assert(*g==*expected);
}

// Vertex
void testAddRemove1(BasicGraph* g, BasicGraph* expected)
{
    g->clearGraph();
    expected->clearGraph();
    assert(*g==*expected);

    g->addVertex(1);
    assert(!(*g==*expected));

    g->removeVertex(1);
    assert(*g==*expected);
}

void testAddRemove2(BasicGraph* g, BasicGraph* expected)
{
    g->clearGraph();
    expected->clearGraph();
    assert(*g==*expected);

    expected->addVertex(1);

    g->addEdge(1, 2);
    g->addVertex(2);
    assert(!(*g==*expected));

    g->removeVertex(2);
    assert(*g==*expected);
}

void testAddRemove3(BasicGraph* g, BasicGraph* expected)
{
    g->clearGraph();
    expected->clearGraph();
    assert(*g==*expected);

    expected->addVertex(3);
    expected->addVertex(5);

    g->addEdge(3, 1);
    g->addVertex(5);
    assert(!(*g==*expected));

    g->removeVertex(1);
    assert(*g==*expected);
}

void testAddRemove4(BasicGraph* g, BasicGraph* expected)
{
    g->clearGraph();
    expected->clearGraph();
    assert(*g==*expected);

    expected->addEdge(1, 2);
    expected->addVertex(3);;
    expected->addVertex(5);

    g->addEdge(1, 2);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    assert(!(*g==*expected));

    g->removeEdge(3, 5);
    g->removeVertex(4);
    assert(*g==*expected);
}

void testAddRemove5(BasicGraph* g, BasicGraph* expected)
{
    g->clearGraph();
    expected->clearGraph();
    assert(*g==*expected);

    expected->addEdge(1, 2);
    expected->addEdge(1, 3);
    expected->addEdge(2, 3);
    expected->addEdge(3, 2);
    expected->addVertex(4);
    expected->addEdge(4, 2);
    expected->addEdge(4, 3);

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
}


// Edges

int main()
{
    BasicGraph graph, expected;

    std::cout << "\nTest File Read\n";
    expected.addEdge(1, 2);
    expected.addEdge(2, 3);
    expected.addEdge(3, 1);
    testFileRead(&graph, PATH4, &expected);
    graph.clearGraph();
    expected.clearGraph();

    expected.addVertex(1);
    testFileRead(&graph, PATH5, &expected);
    graph.clearGraph();
    expected.clearGraph();

    std::cout << "\nTest Add/Remove\n";
    testAddRemove1(&graph, &expected);
    testAddRemove2(&graph, &expected);
    testAddRemove3(&graph, &expected);
    testAddRemove4(&graph, &expected);
    testAddRemove5(&graph, &expected);

    std::cout << "Test BFS\n";

    return 0;
}