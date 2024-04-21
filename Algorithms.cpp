#include <vector>
#include <string>
#include <iostream>
#include "Algorithms.hpp"

using namespace std;
namespace ariel{
    namespace Algorithms{
         void dfs(const Graph& g, int v, vector<bool>& visited) {
            visited[v] = true;
            for (int i = 0; i < g.getVertices(); ++i) {
                if (g.getAdjMatrix()[v][i] != 0 && !visited[i]) {
                    dfs(g, i, visited);
                }
            }
        }

        bool isConnected(const Graph& g) {
            if(g == NULL){
                
            }
            if (g.getVertices() == 0) return true; // An empty graph is trivially connected

            vector<bool> visited(g.getVertices(), false);
            dfs(g, 0, visited); // Start DFS from vertex 0

            for (bool visit : visited) {
                if (!visit) return false; // If any vertex is not visited, the graph is not connected
            }
            return true;
        }

        
        /**
         * helper function for isContainsCycle
         * Utility function to perform DFS and detect cycles in a graph.
         * 
         * @param g The graph on which the DFS and cycle detection are performed. It is passed by reference to avoid copying.
         * @param v The current vertex being visited in the DFS traversal.
         * @param visited A reference to a vector of boolean values indicating whether each vertex has been visited.
         * @param parent A reference to a vector of integers representing the parent vertices in the DFS tree. This helps in backtracking to print the cycle.
         * @param recStack A reference to a vector of boolean values that keeps track of vertices currently in the recursion stack. This helps identify back edges, which indicate cycles.
         * 
         * @return true if a cycle is detected involving the current vertex, otherwise false.
         * also , this function should print one cycle (in the case of more then 1 cycle), or "no cycle detected" if there's no cycle.
         */
        bool detectCycleUtil(const Graph& g, int v, vector<bool>& visited,
            vector<int>& parent, vector<bool>& recStack) {

            visited[v] = true;
            recStack[v] = true;
        }
        static bool isContainsCycle(const Graph& g){
            return false;
        }
        static std::string shortestPath(const Graph& g, int src, int dest){
            return "just a string";
        }
        static std::string isBipartite(const Graph& g){
            return "just a string"
        }
        static bool negativeCycle(const Graph& g){
            return true;
        }
        

    }
}
