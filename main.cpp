#include <iostream>
#include "utils.hpp"
#include "basicGraph.hpp"
#include "graphRenderer.hpp"
#include <SFML/Graphics.hpp>

#define EXIT 7
#define HEIGHT 600
#define RADIUS 30
#define WIDTH 800

void printMenu();

int main()
{
    BasicGraph g;
    GraphRenderer renderer(HEIGHT, RADIUS, WIDTH, sf::Color::Magenta);
    g.addVertex(1);
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Basic Graph Visualization");
    int n = -1;

    while (n != EXIT)
    {
        std::cout << "Basic-Graph:\n";
        printMenu();

        std::cout << "Select an option: ";
        n = getIntFromString();

        renderer.createNodes(g.getAdjList());

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear(sf::Color::White);

            renderer.drawGraph(window);

            window.display();

            switch(n)
            {
                case 1:
                    int v = getIntFromString();

                    g.addVertex(v);
                    renderer.createNodes(g.getAdjList()); 
                    break;
                case EXIT:
                    std::cout << "Exiting program...\n";
                    break;
                default:
                    break;
            }

        }

    }

    return 0;
}

void printMenu()
{
    std::cout << "7. Exit\n";
}