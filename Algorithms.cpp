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
         
         
         ### Explanation of the Logic

            1. **Initialization**: Each vertex starts as unvisited. As `detectCycleUtil` progresses, vertices are marked as visited and added to the recursion stack. The recursion stack is used to keep track of the path of the DFS traversal, which helps in identifying cycles.

            2. **Cycle Detection**:
            - **Unvisited Adjacent Vertex**: If an adjacent vertex hasn't been visited, the function recurses with this new vertex, continuing the DFS. If a cycle is found in the recursion, it bubbles up the call stack, indicating the presence of a cycle.
            - **Vertex in Recursion Stack**: If an adjacent vertex is already in the recursion stack, it indicates that we've encountered a cycle, as we've found a way back to an earlier vertex in the current DFS path. This backtracking process then allows for printing the cycle path by following parent links back to the start of the cycle.

            3. **Cycle Printing**: The printing of the cycle is done by backtracking from the current vertex to the start of the cycle using the `parent` array. This prints a sequence of vertices that forms the cycle, showcasing the loop within the graph structure.

            4. **End of Function**: After checking all adjacent vertices, the current vertex is removed from the recursion stack (indicating that all connections from this vertex have been fully explored), and the function returns `false` if no cycles involving the current vertex were found during its exploration.
         
         
         */
        static bool detectCycleUtil(const Graph& g, int v, vector<bool>& visited, vector<int>& parent, vector<bool>& recStack) {
            visited[v] = true;
            recStack[v] = true;

            for (int i = 0; i < g.getVertices(); ++i) {
                if (g.getAdjMatrix()[v][i] != 0) {
                    if (!visited[i]) {
                        parent[i] = v;  // Set the parent before diving deeper
                        if (detectCycleUtil(g, i, visited, parent, recStack))
                            return true;
                    } else if (recStack[i]) {
                        // Cycle detected, backtrack to print the cycle
                        int current = v;
                        cout << "Cycle: ";
                        while (current != i) {
                            cout << current << "<- ";
                            current = parent[current];
                        }
                        cout << " " << i << " " << v << endl;  // Completing the cycle
                        return true;
                    }
                }
            }
            recStack[v] = false;
            return false;
        }


        static bool isContainsCycle(const Graph& g){
            vector<int> parent(g.getVertecies(), NULL); 
            vector<bool> visited(g.getVertices(), false);
            vector<bool> recStack(g.getVertices(), false);
            for(int vertex : g.getVertices()){
                if(detectCycleUtil(g, vertex, visited, parent, recStack)){
                    return true;
                }
            }
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
