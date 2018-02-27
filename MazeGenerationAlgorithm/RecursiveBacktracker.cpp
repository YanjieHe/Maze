#include "RecursiveBacktracker.hpp"
#include <fstream>
#include <iostream>
#include <random>
RecursiveBacktracker::RecursiveBacktracker(int rows, int cols, double pixelSize)
    : rows{rows}
    , cols{cols}
    , pixelSize{pixelSize}
    , graph(rows * cols)
{
}

void RecursiveBacktracker::BackTrack(int start)
{
    std::random_device device;
    std::minstd_rand generator(device());
    std::uniform_int_distribution<> distribution;
    std::function<int()> choose = [&generator, &distribution]() {
        return distribution(generator);
    };
    std::vector<bool> marked(static_cast<size_t>(rows * cols));
    for (size_t i = 0; i < marked.size(); i++)
    {
        marked.at(i) = false;
    }
    BackTrack(marked, start, choose);
}

void RecursiveBacktracker::WriteToFile(std::string path)
{
    std::ofstream file(path);
    file << rows << ' ' << cols;
    file << ' ' << pixelSize << std::endl;
    for (int i = 0; i < rows * cols; i++)
    {
        const std::vector<int>& vec = graph.Adjacency(i);
        for (int k : vec)
        {
            file << i;
            file << ' ';
            file << k;
            file << std::endl;
        }
    }
    file.close();
}

void RecursiveBacktracker::BackTrack(std::vector<bool>& marked, int current,
                                     std::function<int()>& choose)
{
    marked.at(static_cast<size_t>(current)) = true;
    bool done = false;
    while (!done)
    {
        std::vector<int> choices = Choices(marked, current);
        if (choices.size() == 0)
        {

            done = true;
        }
        else
        {
            int index = choose() % static_cast<int>(choices.size());
            int next = choices.at(static_cast<size_t>(index));
            graph.AddEdge(current, next);
            BackTrack(marked, next, choose);
        }
    }
}

std::vector<int> RecursiveBacktracker::Choices(std::vector<bool>& marked,
                                               int index)
{
    std::vector<int> choices;
    int row = index / cols;
    int col = index % cols;
    if (IsValidated(row - 1, col))
    {
        int value = Value(row - 1, col);
        if (!marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row + 1, col))
    {
        int value = Value(row + 1, col);
        if (!marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row, col - 1))
    {
        int value = Value(row, col - 1);
        if (!marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row, col + 1))
    {
        int value = Value(row, col + 1);
        if (!marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    return choices;
}

int RecursiveBacktracker::Value(int row, int col)
{
    return row * cols + col;
}

bool RecursiveBacktracker::IsValidated(int row, int col)
{
    return row >= 0 && row < rows && col >= 0 && col < cols;
}
