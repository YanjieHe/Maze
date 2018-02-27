#include "UndirectedGraph.hpp"
using std::vector;

UndirectedGraph::UndirectedGraph(int V)
    : V{V}
    , adj(static_cast<size_t>(V))
{
}

void UndirectedGraph::AddEdge(int from, int to)
{
    adj.at(static_cast<size_t>(from)).push_back(to);
    adj.at(static_cast<size_t>(to)).push_back(from);
}

const vector<int>& UndirectedGraph::Adjacency(int v)
{
    return adj.at(static_cast<size_t>(v));
}
