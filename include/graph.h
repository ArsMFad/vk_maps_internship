/*!
* @file
* @brief Header file with Graph class description
*
*/

#ifndef Graph_H
#define Graph_H

#include <vector>
#include <string>


/*!
 * @brief Graph class
 *
 * Graph data structure. Using adjaceny list;
 *
 *
 */
class Graph {
private:
    int verticles;
    int start_vertex;
    std::vector<std::vector<int>> adjacenyList;
public:
    Graph();
    Graph(int v);
    ~Graph();

    void addEdge(int u, int v);
    void getFromFileWithStartVertex(const std::string & filename);

    std::vector<int> getNeighbors(int v) const;
    int getStartVertex() const;
    void printGraph() const;

    std::vector<int> findShortestWays(int st) const;
};


#endif // GRAPH_H
