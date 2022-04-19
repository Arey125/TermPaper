#ifndef UIGRAPH_H
#define UIGRAPH_H

#include <vector>
#include <memory>
#include <optional>

#include "node.h"

class UIGraph
{
public:
    UIGraph();

    std::optional<Node*> addNode(int x, int y);
    std::optional<Node*> getNode(QPointF pos);

private:
    std::vector<Node*> nodes;

};

#endif // UIGRAPH_H
