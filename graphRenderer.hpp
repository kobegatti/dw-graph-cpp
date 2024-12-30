#ifndef GRAPHRENDERER_HPP
#define GRAPHRENDERER_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>

class GraphRenderer
{
    public:
        GraphRenderer(int height, int radius, int width, sf::Color color);
        ~GraphRenderer();

        void createNodes(const std::unordered_map<int, std::vector<int>>& adjList);
        void drawGraph(sf::RenderWindow& window);
    
    private:
        int height;
        int radius;
        int width;
        int angle;
        sf::Color color;
        std::unordered_map<int, sf::CircleShape> nodes;
};

#endif