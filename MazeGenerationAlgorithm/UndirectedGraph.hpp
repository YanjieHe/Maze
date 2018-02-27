#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
class UndirectedGraph
{
public:
    int V;
    std::vector<std::vector<int>> adj;
    UndirectedGraph(int V);
    void AddEdge(int from, int to);
    const std::vector<int>& Adjacency(int v);
};

#endif // GRAPH_HPP
