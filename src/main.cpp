#include <iostream>
#include "../include/graph.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> " << std::endl;
        return -1;
    }

    const std::string filename = argv[1];

    Graph g(0);
    g.getFromFile(filename);

    std::vector<int> d = g.findShortestWays(-1);

    for (int i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";
    

    return 0;
}
