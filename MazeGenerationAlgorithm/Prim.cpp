#include "Prim.hpp"
#include <fstream>
#include <random>
#include <vector>
Prim::Prim(int rows, int cols, double pixelSize)
    : rows{rows}
    , cols{cols}
    , pixelSize{pixelSize}
    , graph(rows * cols)
{
}

void Prim::Generate()
{
    std::random_device device;
    std::minstd_rand generator(device());
    std::uniform_int_distribution<> distribution;
    std::set<int> frontier;
    std::function<int()> choose = [&generator, &distribution]() {
        return distribution(generator);
    };
    std::vector<bool> marked(static_cast<size_t>(rows * cols));
    for (size_t i = 0; i < marked.size(); i++)
    {
        marked.at(i) = false;
    }
    Generate(frontier, marked, choose() % rows * cols, choose);
}

void Prim::Generate(std::set<int>& frontier, std::vector<bool>& marked,
                    int current, std::function<int()>& choose)
{
    marked.at(static_cast<size_t>(current)) = true;
    std::vector<int> choices = Choices(marked, current);
    for (int choice : choices)
    {
        if (frontier.find(choice) == frontier.end())
        {
            frontier.insert(choice);
        }
    }
    if (frontier.size() == 0)
    {
        return;
    }
    else
    {
        int randomIndex = choose() % static_cast<int>(frontier.size());
        int i = 0;
        for (int item : frontier)
        {
            if (i == randomIndex)
            {
                int index = InnerIndex(item, marked, choose);
                if (index == -1)
                {
                    return;
                }
                else
                {
                    graph.AddEdge(index, item);
                    frontier.erase(item);
                    Generate(frontier, marked, item, choose);
                    return;
                }
            }
            i++;
        }
    }
}

std::vector<int> Prim::Choices(std::vector<bool>& marked, int index)
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

int Prim::InnerIndex(int indexOfFrontier, std::vector<bool>& marked,
                     std::function<int()>& choose)
{
    std::vector<int> choices;
    int row = indexOfFrontier / cols;
    int col = indexOfFrontier % cols;
    if (IsValidated(row - 1, col))
    {
        int value = Value(row - 1, col);
        if (marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row + 1, col))
    {
        int value = Value(row + 1, col);
        if (marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row, col - 1))
    {
        int value = Value(row, col - 1);
        if (marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (IsValidated(row, col + 1))
    {
        int value = Value(row, col + 1);
        if (marked.at(static_cast<size_t>(value)))
        {
            choices.push_back(value);
        }
    }
    if (choices.size() == 0)
    {
        return -1;
    }
    else
    {
        int index = choose() % static_cast<int>(choices.size());
        return choices.at(static_cast<size_t>(index));
    }
}

int Prim::Value(int row, int col)
{
    return row * cols + col;
}

bool Prim::IsValidated(int row, int col)
{
    return row >= 0 && row < rows && col >= 0 && col < cols;
}
void Prim::WriteToFile(std::string path)
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
