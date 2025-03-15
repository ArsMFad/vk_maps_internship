#include "../include/graph.h"

#include <iostream>
#include <cassert>


void run(std::ostream &out, const std::string& filename)
{
    Graph g(0);
    g.getFromFileWithStartVertex(filename);

    std::vector<int> distances = g.findShortestWays(-1);

    for (unsigned i = 0; i < distances.size(); i++)
    {
        out << distances[i] << " ";
    }
    out << "\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> " << std::endl;
        return -1;
    }
    const std::string filename = argv[1];

    run(std::cout, filename);

    return 0;
}
