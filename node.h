#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <vector>

#include "edge.h"

class UIGraph;

class Node : public QGraphicsItem
{
public:
    Node(QPointF pos, UIGraph *graph);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        lastPos = pos();
        QGraphicsItem::mousePressEvent(event);
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    std::vector<Edge *> incomingEdges, outcomingEdges;
    QPointF lastPos;
    UIGraph *graph;
};

#endif // NODE_H
