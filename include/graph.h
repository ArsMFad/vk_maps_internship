#ifndef Graph_H
#define Graph_H

#include <vector>
#include <string>


class Graph {
private:
    int verticles;
    std::vector<std::vector<int>> adjacenyList;

    void addEdge(int u, int v);
public:
    Graph();
    Graph(int v);
    ~Graph();
    
    void getFromFile(const std::string & filename);
    void printGraph() const;

    std::vector<int> bfs(int st) const;
};


#endif // GRAPH_H
