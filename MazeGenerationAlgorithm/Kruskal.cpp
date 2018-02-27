#include "Kruskal.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
Kruskal::Kruskal(int rows, int cols, double pixelSize)
    : rows{rows}
    , cols{cols}
    , pixelSize{pixelSize}
    , graph(rows * cols)
{
}

void Kruskal::Generate()
{
    std::vector<std::tuple<int, int>> edges = Edges();
    std::vector<int> values(static_cast<size_t>(rows * cols));
    for (int i = 0; i < static_cast<int>(values.size()); i++)
    {
        values.at(static_cast<size_t>(i)) = i;
    }
    std::shuffle(edges.begin(), edges.end(), std::default_random_engine());
    for (std::tuple<int, int>& edge : edges)
    {
        int from, to;
        std::tie(from, to) = edge;
        int v1 = values.at(static_cast<size_t>(from));
        int v2 = values.at(static_cast<size_t>(to));

        if (v1 != v2)
        {
            for (size_t i = 0; i < values.size(); i++)
            {
                if (values.at(i) == v2)
                {
                    values.at(i) = v1;
                }
            }
            graph.AddEdge(from, to);
        }
    }
}

void Kruskal::WriteToFile(std::string path)
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

std::vector<std::tuple<int, int>> Kruskal::Edges()
{
    std::vector<std::tuple<int, int>> edges;
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            edges.push_back(std::make_tuple(i * cols + j, (i + 1) * cols + j));
        }
    }
    for (int j = 0; j < cols - 1; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            edges.push_back(std::make_tuple(i * cols + j, i * cols + j + 1));
        }
    }
    return edges;
}
