#ifndef MAZENODE_HPP
#define MAZENODE_HPP

#include <QGraphicsRectItem>

class MazeNode : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    int id;
    explicit MazeNode(int id, qreal x, qreal y, qreal pixelSize,
                      QGraphicsItem* parent = Q_NULLPTR);
    QGraphicsLineItem* setLeftBorder();
    QGraphicsLineItem* setRightBorder();
    QGraphicsLineItem* setUpBorder();
    QGraphicsLineItem* setDownBorder();
    bool hasLeftBorder = true;
    bool hasRightBorder = true;
    bool hasUpBorder = true;
    bool hasDownBorder = true;
    void setColor(QColor color);
};

#endif // MAZENODE_HPP
