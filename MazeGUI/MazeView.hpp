#ifndef MAZEVIEW_HPP
#define MAZEVIEW_HPP

#include "MazeNode.hpp"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QVector>
class MazeView : public QGraphicsView
{
public:
    MazeView(int rows, int cols, qreal pixelSize);
    MazeView(const MazeView&) = delete;
    MazeView& operator=(const MazeView&) = delete;
    ~MazeView();

    int rows;
    int cols;
    QGraphicsScene* scene;
    QVector<MazeNode*> nodes;
    QVector<QGraphicsLineItem*> walls;
    void loadEdge(int from, int to);
    void addLines();
};

#endif // MAZEVIEW_HPP
