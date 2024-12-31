#include "graphNode.hpp"

GraphNode::GraphNode(int val)
{
    explored = false;
    value = val;
    parent = nullptr;
}