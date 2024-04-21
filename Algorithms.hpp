#include <string>
#include <vector> // Include for std::vector

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace ariel {
    namespace Algorithms {
        static bool isConnected(const Graph& g); 
        static bool isContainsCycle(const Graph& g); 
        static std::string shortestPath(const Graph& g, int src, int dest); 
        static std::string isBipartite(const Graph& g); 
        static bool negativeCycle(const Graph& g); 
        static void DFS(const Graph& g, int i); 
    }
} 

#endif // ALGORITHMS_HPP
