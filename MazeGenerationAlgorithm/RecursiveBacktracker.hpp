#ifndef RECURSIVEBACKTRACKER_HPP
#define RECURSIVEBACKTRACKER_HPP
#include "UndirectedGraph.hpp"
#include <functional>
#include <string>
#include <vector>

class RecursiveBacktracker
{
public:
    int rows;
    int cols;
    double pixelSize;

    UndirectedGraph graph;
    RecursiveBacktracker(int rows, int cols, double pixelSize);
    void BackTrack(int start);
    void WriteToFile(std::string path);

private:
    void BackTrack(std::vector<bool>& marked, int current,
                   std::function<int()>& choose);
    std::vector<int> Choices(std::vector<bool>& marked, int index);
    int Value(int row, int col);
    bool IsValidated(int row, int col);
};

#endif // RECURSIVEBACKTRACKER_HPP
