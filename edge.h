#ifndef EDGE_H
#define EDGE_H

#include <QObject>
#include <QGraphicsItem>


class Node;

class Edge : public QGraphicsItem
{
public:
    Edge();

    Node* from()
    {
        return m_From;
    }

    Node* to()
    {
        return m_To;
    }
private:
    Node* m_From,* m_To;
};

#endif // EDGE_H
