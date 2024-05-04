#include <string>
#include <vector> // Include for std::vector
#include "Graph.hpp"

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

// using namespace ariel;
namespace ariel {
    class Algorithms {
        public:
            static void dfs(const Graph g, int v, vector<bool>& visited);
            static bool isConnected(const Graph& g); 
            static bool isContainsCycle(const Graph& g); 
            static std::string shortestPath(const Graph& g, int src, int dest); 
            static bool isBipartite(const Graph& g); 
            static bool negativeCycle(const Graph& g); 
        private:
            static bool detectCycleUtil(const Graph& g, unsigned int v, vector<bool>& visited, vector<int>& parent, vector<bool>& recStack); 
            static vector<int> bellmanFord(const Graph& g, int src, int end);
    };  
} 

#endif // ALGORITHMS_HPP
