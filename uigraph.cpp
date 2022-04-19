#include "uigraph.h"

UIGraph::UIGraph()
{

}

std::optional<Node *> UIGraph::addNode(int x, int y)
{
    if (getNode(QPointF(x,y)))
        return {};
    nodes.emplace_back(new Node(QPointF(x, y), this));
    return nodes.back();
}

std::optional<Node *> UIGraph::getNode(QPointF pos)
{
    for (auto node_ptr : nodes)
    {
        auto &node = *node_ptr;
        if ((node.pos() - pos).manhattanLength() < 1)
            return node_ptr;
    }
    return {};
}
