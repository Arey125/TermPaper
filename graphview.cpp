#include "graphview.h"
#include "node.h"
#include "core.h"

#include <QMouseEvent>
#include <cmath>

GraphView::GraphView(QWidget *parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this))
{
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0,0,400,400);
    setTransformationAnchor(AnchorUnderMouse);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setCacheMode(QGraphicsView::CacheBackground);
    setScene(scene);
}

void GraphView::drawBackground(QPainter *painter, const QRectF &rect)
{
    auto pos = QCursor::pos();
    pos = mapFromGlobal(pos);

    auto cursorPos = mapToScene(pos);

    auto optPos = getRoundedPos(cursorPos);
    if (!optPos)
        return;

    painter->setPen(QPen(Qt::cyan, 0));
    painter->drawEllipse(optPos.value(), 10, 10);
}

void GraphView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if (event->button() != Qt::MouseButton::RightButton)
        return;
    auto pos = QGraphicsView::mapToScene(event->pos());
    auto optPos = getRoundedPos(pos);
    if (!optPos)
        return;
    auto node = graph.addNode(optPos->x(), optPos->y());
    if (!node)
        return;
    scene->addItem(node.value());
}
