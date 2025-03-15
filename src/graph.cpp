#include "../include/graph.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <queue>


Graph::Graph() : verticles(0), start_vertex(-1), adjacenyList(0) {}


Graph::Graph(int v) : verticles(v), start_vertex(-1), adjacenyList(v) {}


Graph::~Graph() {}


void Graph::addEdge(int u, int v)
{
    adjacenyList[u].push_back(v);
    adjacenyList[v].push_back(u);
}


void Graph::getFromFile(const std::string& filename)
{
    std::ifstream input(filename);
    if (!input.is_open())
        throw std::runtime_error("Failed to open file");

    int edges;
    input >> verticles >> edges;

    adjacenyList.resize(verticles);

    while(edges--)
    {
        int u, v;
        input >> u >> v;
        addEdge(u, v);
    }

    input >> start_vertex;
}


void Graph::printGraph() const
{
    for (int i = 0; i < verticles; i++)
    {
        std::cout << "Verticle " << i << " is connected with: ";
        for (int j : adjacenyList[i])
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


std::vector<int> Graph::findShortestWays(int st) const
{
    if (st == -1) st = start_vertex;

    std::vector<int> distances(verticles, -1);
    std::queue<int> q;

    q.push(st);
    distances[st] = 0;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : adjacenyList[current])
        {
            if (distances[neighbor] == -1)
            {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}
