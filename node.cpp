#include "node.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "core.h"
#include "uigraph.h"

Node::Node(QPointF pos, UIGraph *graph)
    : graph(graph)
{
    this->setPos(pos);
    QGraphicsItem::setFlag(ItemIsMovable);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
}

QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    auto pos = event->pos();
    pos = mapToScene(pos);
    auto optPos = getRoundedPos(pos);
    if (!optPos)
    {
        setPos(lastPos);
        return;
    }
    if (graph->getNode(*optPos))
    {
        setPos(lastPos);
        return;
    }
    setPos(*optPos);
    QGraphicsItem::mouseReleaseEvent(event);
}
