#include "MazeView.hpp"
#include <QFile>
#include <QGraphicsLineItem>
MazeView::MazeView(int rows, int cols, qreal pixelSize)
    : QGraphicsView()
    , rows{rows}
    , cols{cols}
    , scene{new QGraphicsScene(this)}
    , nodes(rows * cols)
{
    this->setScene(scene);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int id = i * cols + j;
            qreal x = j * pixelSize;
            qreal y = i * pixelSize;
            MazeNode* node = new MazeNode(id, x, y, pixelSize);
            scene->addItem(node);
            nodes[id] = node;
        }
    }
}

MazeView::~MazeView()
{
    delete scene;
}

void MazeView::loadEdge(int from, int to)
{
    int row_a = from / cols;
    int col_a = from % cols;
    int row_b = to / cols;
    int col_b = to % cols;
    if (row_a == row_b)
    {
        if (col_a == col_b - 1)
        {
            nodes[from]->hasRightBorder = false;
            nodes[to]->hasLeftBorder = false;
        }
        else if (col_a == col_b + 1)
        {
            nodes[from]->hasLeftBorder = false;
            nodes[to]->hasRightBorder = false;
        }
        else
        {
            throw QString("Argument range error");
        }
    }
    else if (col_a == col_b)
    {
        if (row_a == row_b - 1)
        {
            nodes[from]->hasDownBorder = false;
            nodes[to]->hasUpBorder = false;
        }
        else if (row_a == row_b + 1)
        {
            nodes[from]->hasUpBorder = false;
            nodes[to]->hasDownBorder = false;
        }
        else
        {
            throw QString("Argument range error");
        }
    }
    else
    {
        throw QString("Argument range error");
    }
}

void MazeView::addLines()
{
    for (int i = 0; i < rows * cols; i++)
    {
        if (nodes[i]->hasLeftBorder)
        {
            QGraphicsLineItem* line = nodes[i]->setLeftBorder();
            walls.push_back(line);
        }
        if (nodes[i]->hasRightBorder)
        {
            QGraphicsLineItem* line = nodes[i]->setRightBorder();
            walls.push_back(line);
        }
        if (nodes[i]->hasUpBorder)
        {
            QGraphicsLineItem* line = nodes[i]->setUpBorder();
            walls.push_back(line);
        }
        if (nodes[i]->hasDownBorder)
        {
            QGraphicsLineItem* line = nodes[i]->setDownBorder();
            walls.push_back(line);
        }
    }
    for (QGraphicsLineItem* line : walls)
    {
        scene->addItem(line);
    }
}
