#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

#include "uigraph.h"

class GraphView : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene *scene;

public:
    GraphView(QWidget *parent);

    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override
    {
        QGraphicsView::mouseMoveEvent(event);
        QGraphicsView::resetCachedContent();
    }

private:
    UIGraph graph;
};

#endif // GRAPHVIEW_H
