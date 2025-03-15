/*!
* @file
* @brief Graph class functions
*/


#include "../include/graph.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <queue>
#include <vector>


/**
 * @brief Constructor by default
 *
 *
 */
Graph::Graph() : verticles( 0 ), start_vertex( -1 ), adjacenyList( 0 ) {}


/**
 * @brief Constructor with verticles argument
 *
 * @param v verticles
 *
 */
Graph::Graph( int v ) : verticles( v ), start_vertex( -1 ), adjacenyList( v ) {}


/**
 * @brief Destructor
 *
 */
Graph::~Graph() {}


/**
 * @brief Adding edge function
 *
 * Function add edge to undirected graph.
 *
 * @param u vertex
 * @param v vertex
 *
 */
void Graph::addEdge( int u, int v )
{
    if(( u < 0 ) || ( u >= verticles ))
        throw std::out_of_range("U vertex is out of range");
    
    if(( v < 0 ) || ( v >= verticles ))
        throw std::out_of_range("V vertex is out of range");

    adjacenyList[u].push_back( v );
    adjacenyList[v].push_back( u );
}


/**
 * @brief Get from file with start vertex
 *
 * Reading graph from file as descripted in task.
 * Also getting start vertex from the end of the txt file
 *
 * @param filename filename for graph input
 *
 */
void Graph::getFromFileWithStartVertex( const std::string& filename )
{
    std::ifstream input( filename );
    if( !input.is_open() )
        throw std::runtime_error("Failed to open file");

    int edges;
    input >> verticles >> edges;

    adjacenyList.resize(verticles);

    while( edges-- )
    {
        int u, v;
        input >> u >> v;
        addEdge( u, v );
    }

    input >> start_vertex;
}


/**
 * @brief Get Neighbors
 *
 * Returning adjacency list row of neighbors
 *
 * @param v vertex
 * @return adjacency list row
 *
 */
std::vector< int > Graph::getNeighbors( int v ) const
{
    return adjacenyList[v];
}


/**
 * @brief Get start vertex
 *
 * Returning start vertex of graph
 *
 * @return vertex
 *
 */
int Graph::getStartVertex() const
{
    return start_vertex;
}


/**
 * @brief Print graph
 *
 * Output of graph
 *
 */
void Graph::printGraph() const
{
    for( int i = 0; i < verticles; i++ )
    {
        std::cout << "Verticle " << i << " is connected with: ";
        for( int j : adjacenyList[i] )
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


/**
 * @brief Find Shortest Ways
 *
 * Running bfs and search shortest ways to all other verticles
 *
 * @param st start vertex. If st equals -1, then st will be start_vertex of Graph
 * @return vector of distances
 *
 */
std::vector< int > Graph::findShortestWays( int st ) const
{
    if( st == -1 ) st = start_vertex;

    if(( st < 0 ) || ( st >= verticles ))
        throw std::out_of_range("Start vertex is out of range");

    std::vector< int > distances( verticles, -1 );
    std::queue< int > q;

    q.push( st );
    distances[ st ] = 0;

    while( !q.empty() )
    {
        int current = q.front();
        q.pop();

        for( int neighbor : adjacenyList[ current ] )
        {
            if( distances[ neighbor ] == -1 )
            {
                distances[ neighbor ] = distances[ current ] + 1;
                q.push( neighbor );
            }
        }
    }

    return distances;
}
