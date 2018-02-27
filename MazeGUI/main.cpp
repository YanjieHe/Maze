#include "MazeView.hpp"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
MazeView* loadMap(std::string path)
{
    std::ifstream file(path);
    int rows;
    int cols;
    double pixelSize;
    file >> rows >> cols >> pixelSize;
    int from;
    int to;
    MazeView* maze = new MazeView(rows, cols, pixelSize);
    while (file.peek() != EOF)
    {
        file >> from;
        file >> to;
        maze->loadEdge(from, to);
    }
    return maze;
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    if (argc == 2)
    {
        std::string path = argv[1];
        MazeView* view = loadMap(path);
        view->addLines();
        view->show();
    }
    else
    {
        std::cout << "usage: map_file" << std::endl;
        return 1;
    }

    return a.exec();
}
