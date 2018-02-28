#ifndef PRIM_HPP
#define PRIM_HPP
#include "UndirectedGraph.hpp"
#include <functional>
#include <set>
class Prim
{
public:
    int rows;
    int cols;
    double pixelSize;
    UndirectedGraph graph;
    Prim(int rows, int cols, double pixelSize);
    void Generate();
    void Generate(std::set<int>& frontier, std::vector<bool>& marked,
                  int current, std::function<int()>& choose);
    std::vector<int> Choices(std::vector<bool>& marked, int index);
    int InnerIndex(int indexOfFrontier, std::vector<bool>& marked,
                   std::function<int()>& choose);
    int Value(int row, int col);
    bool IsValidated(int row, int col);
    void WriteToFile(std::string path);
};

#endif // PRIM_HPP
