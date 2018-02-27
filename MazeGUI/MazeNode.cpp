#include "MazeNode.hpp"
#include <QGraphicsLineItem>
#include <QPen>

MazeNode::MazeNode(int id, qreal x, qreal y, qreal pixelSize,
                   QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, pixelSize, pixelSize, parent)
    , id{id}
{
    setPen(Qt::NoPen);
}

QGraphicsLineItem* MazeNode::setLeftBorder()
{
    QRectF rect = this->rect();
    QGraphicsLineItem* line = new QGraphicsLineItem(
        rect.x(), rect.y(), rect.x(), rect.y() + rect.height());
    return line;
}

QGraphicsLineItem* MazeNode::setRightBorder()
{
    QRectF rect = this->rect();
    QGraphicsLineItem* line = new QGraphicsLineItem(
        rect.x() + rect.width(), rect.y(), rect.x() + rect.width(),
        rect.y() + rect.height());
    return line;
}

QGraphicsLineItem* MazeNode::setUpBorder()
{
    QRectF rect = this->rect();
    QGraphicsLineItem* line = new QGraphicsLineItem(
        rect.x(), rect.y(), rect.x() + rect.width(), rect.y());
    return line;
}

QGraphicsLineItem* MazeNode::setDownBorder()
{
    QRectF rect = this->rect();
    QGraphicsLineItem* line = new QGraphicsLineItem(
        rect.x(), rect.y() + rect.height(), rect.x() + rect.width(),
        rect.y() + rect.height());
    return line;
}

void MazeNode::setColor(QColor color)
{
    setBrush(QBrush(color));
}
