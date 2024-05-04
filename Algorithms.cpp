#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <sstream>
#include "Algorithms.hpp"

using namespace std;
// using namespace ariel;

namespace ariel {
    void Algorithms::dfs(const Graph g, int v, vector<bool>& visited) {
        visited[v] = true;
        for (unsigned int i = 0; i < g.getVertices(); ++i) {
            if (g.getAdjMatrix()[v][i] != 0 && !visited[i]) {
                dfs(g, i, visited);
            }
        }
    }

    bool Algorithms::isConnected(const Graph& g) {
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
     
        
        * Explanation of the Logic:

        1. **Initialization**: Each vertex starts as unvisited. As `detectCycleUtil` progresses, vertices are marked as visited and added to the recursion stack. The recursion stack is used to keep track of the path of the DFS traversal, which helps in identifying cycles.

        2. **Cycle Detection**:
        - **Unvisited Adjacent Vertex**: If an adjacent vertex hasn't been visited, the function recurses with this new vertex, continuing the DFS. If a cycle is found in the recursion, it bubbles up the call stack, indicating the presence of a cycle.
        - **Vertex in Recursion Stack**: If an adjacent vertex is already in the recursion stack, it indicates that we've encountered a cycle, as we've found a way back to an earlier vertex in the current DFS path. This backtracking process then allows for printing the cycle path by following parent links back to the start of the cycle.

        3. **Cycle Printing**: The printing of the cycle is done by backtracking from the current vertex to the start of the cycle using the `parent` array. This prints a sequence of vertices that forms the cycle, showcasing the loop within the graph structure.

        4. **End of Function**: After checking all adjacent vertices, the current vertex is removed from the recursion stack (indicating that all connections from this vertex have been fully explored), and the function returns `false` if no cycles involving the current vertex were found during its exploration.
        
    */
    bool Algorithms::detectCycleUtil(const Graph& g, unsigned int v, vector<bool>& visited, vector<int>& parent, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (unsigned int i = 0; i < g.getVertices(); ++i) {
            if (g.getAdjMatrix()[v][i] != 0) {
                if (!visited[i]) {
                    parent[i] = v;  // Set the parent before diving deeper
                    if (detectCycleUtil(g, i, visited, parent, recStack))
                        return true;
                } else if (recStack[i]) {
                    // Cycle detected, backtrack to print the cycle
                    unsigned int current = v;
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


    bool Algorithms::isContainsCycle(const Graph& g){
        vector<int> parent(g.getVertices(), 0); 
        vector<bool> visited(g.getVertices(), false);
        vector<bool> recStack(g.getVertices(), false);
        
        for (unsigned int vertex=0; vertex < g.getVertices(); vertex++){ 
           if (detectCycleUtil(g, vertex, visited, parent, recStack)){
               return true;
           }
        }        
        return false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    }

    vector<int> Algorithms::bellmanFord(const Graph& g, int src, int end) {
        int vertices = g.getVertices();
        vector<int> dist(vertices, INT_MAX);
        vector<int> parent(vertices, -1);

        dist[src] = 0; // Start with the source vertex

        // Relax all edges |V| - 1 times
        for (int i = 0; i < vertices - 1; ++i) {
            for (int u = 0; u < vertices; ++u) {
                for (int v = 0; v < vertices; ++v) {
                    if (g.getAdjMatrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getAdjMatrix()[u][v] < dist[v]) {
                        dist[v] = dist[u] + g.getAdjMatrix()[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (int u = 0; u < vertices; ++u) {
            for (int v = 0; v < vertices; ++v) {
                if (g.getAdjMatrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.getAdjMatrix()[u][v] < dist[v]) {
                    throw runtime_error("Graph contains a negative weight cycle");
                }
            }
        }

        // Construct the path from src to end
        vector<int> path(vertices, 0);
        for (int at = end; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        // If the path starts with the src, return it
        if (path.size() == 1 && path[0] != src) {
            path.clear();  // Clear the path if no path found
        }

        return path;
    }

    std::string Algorithms::shortestPath(const Graph& g, int src, int dest) {
        try {
            vector<int> path = bellmanFord(g, src, dest);
            if (path.empty()) {
                return "No path from source to destination.";
            }

            stringstream ss;
            ss << "Path from " << src << " to " << dest << ": ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) ss << " -> ";
                ss << path[i];
            }
            return ss.str();
        } catch (const runtime_error& e) {
            return e.what();  // Return the error message if a negative cycle is detected
        }
    }
    /*
    Using BFS: Start from any unvisited vertex and assign it a color (say, red). 
    All its neighbors are given the opposite color (say, blue). 
    Continue the process for all neighbors and their respective neighbors.
    If at any point a neighbor has the same color as the current vertex, then the graph is not bipartite.
    */
    bool Algorithms::isBipartite(const Graph& graph) {
        vector<int> color(graph.getVertices(), -1);  // Color array to store colors assigned to vertices
        queue<int> q;  // Queue for BFS

        // Check all vertices since graph might be disconnected
        for (unsigned int src = 0; src < graph.getVertices(); ++src) {
            if (color[src] == -1) {  // If not colored
                color[src] = 0;  // Start coloring with 0
                q.push(src);

                while (!q.empty()) {
                    unsigned int u = q.front();
                    q.pop();

                    // Check self loop
                    if (graph.getAdjMatrix()[u][u] != 0){
                        return false;
                    }
                    for (unsigned v = 0; v < graph.getVertices(); ++v) {
                        if (graph.getAdjMatrix()[u][v] && v != u) {
                            if (color[v] == -1) {  // If v is not colored
                                color[v] = 1 - color[u];  // Assign alternate color
                                q.push(v);
                            }
                            else if (color[v] == color[u]) {  // If adjacent vertices have the same color
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;  // If no conflicts, graph is bipartite
    }

    bool Algorithms::negativeCycle(const Graph& g){
        //TODO: if there is a negative cycle in the graph, print a string
        // a negative cycle was found with the cycle itself.
        // otherwise: 'no negative cycle detected'.
        if(!isContainsCycle(g)){
            return false;
        }
        return true;
    }      
}
