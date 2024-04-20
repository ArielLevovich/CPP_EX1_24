#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"

namespace ariel {
    namespace Algorithms {
        static bool isConnected(Graph g);
        static bool isContainsCycle(Graph g); 
        static std::string shortestPath(Graph g, int des, int src);
        static std::string isBipartite(Graph g);
        static bool negativeCycle(Graph g); 
        void DFS(Graph g,int i,std::vector<std::vector<bool>> vec1);
    };
}

#endif 