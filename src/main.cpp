#include <iostream>
#include "../include/graph.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> " << std::endl;
        return -1;
    }

    const std::string filename = argv[1];

    std::cout << argv[1] << std::endl;
    Graph g(0);
    g.getFromFile(filename);
    g.printGraph();
    
    return 0;
}
