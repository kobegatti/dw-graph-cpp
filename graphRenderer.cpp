#include "graphRenderer.hpp"

GraphRenderer::GraphRenderer(int h, int r, int w, sf::Color c)
{
    height = h;
    radius = r;
    width = w;
    color = c;
    angle = 0;
}

GraphRenderer::~GraphRenderer() {}

void GraphRenderer::createNodes(const std::unordered_map<int, std::vector<int>>& adjList)
{
    size_t adjListSize = adjList.size();

    if (adjListSize == 0) { return; }

    int angleBetweenNodes = 360 / adjListSize;
    float angle = 0;

    for (const auto& node : adjList)
    {
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setOrigin(sf::Vector2f(radius, radius));

        // Position nodes in a circular layout
        float x = width / 2 + (width / 3) * cos(angle * M_PI / 180); // Position X
        float y = height / 2 + (height / 3) * sin(angle * M_PI / 180); // Position Y

        circle.setPosition(sf::Vector2f(x, y));
        nodes[node.first] = circle;
        angle += angleBetweenNodes;
    }
}

void GraphRenderer::drawGraph(sf::RenderWindow& window)
{
    for (const auto& node : nodes)
    {
        window.draw(node.second);
    }
}