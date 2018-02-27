#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP
#include "UndirectedGraph.hpp"
#include <string>
#include <tuple>
#include <vector>
class Kruskal
{
public:
    int rows;
    int cols;
    double pixelSize;
    UndirectedGraph graph;
    Kruskal(int rows, int cols, double pixelSize);
    void Generate();
    void WriteToFile(std::string path);
    std::vector<std::tuple<int, int>> Edges();
};

#endif // KRUSKAL_HPP
