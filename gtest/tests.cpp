/*!
* @file
* @brief Tests for graph
*/

#include <gtest/gtest.h>
#include "../include/graph.h"

/**
 * @brief Test how graph works
 *
 */
TEST(GraphTest, AddEdgeTest)
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    std::vector<int> expectedN0 = {1, 4};
    std::vector<int> expectedN1 = {0, 2, 3};
    std::vector<int> expectedN4 = {0};

    EXPECT_EQ(g.getNeighbors(0), expectedN0);
    EXPECT_EQ(g.getNeighbors(1), expectedN1);
    EXPECT_EQ(g.getNeighbors(4), expectedN4);
}


/**
 * @brief Test how graph get data from file
 *
 */
TEST(GraphTest, getFromFileTest)
{
    Graph g(0);
    g.getFromFileWithStartVertex("graph.txt");

    std::vector<int> expectedN0 = {1, 4};
    std::vector<int> expectedN1 = {0, 2, 3};
    std::vector<int> expectedN4 = {0};
    int expectedS = 4;

    EXPECT_EQ(g.getNeighbors(0), expectedN0);
    EXPECT_EQ(g.getNeighbors(1), expectedN1);
    EXPECT_EQ(g.getNeighbors(4), expectedN4);
    EXPECT_EQ(g.getStartVertex(), expectedS);
}


/**
 * @brief Test how bfs algorithm in findShortestWays work
 *
 */
TEST(GraphTest, BFSTest)
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    std::vector<int> distances = g.findShortestWays(0);

    std::vector<int> expectedD = {0, 1, 2, 2, 1};

    EXPECT_EQ(distances, expectedD);
}
