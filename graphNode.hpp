#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

class GraphNode
{
    // Constructors
    GraphNode(int val);

    private:
        bool explored;
        int value;
        GraphNode* parent;
};

#endif