### README.md - Algorithms and Graph Classes - Ariel Leibovich - 326535242

---

#### Overview

This README provides an exhaustive explanation of the functionalities and implementation details of the `Algorithms` and `Graph` classes written in C++. These classes demonstrate various graph-related algorithms such as depth-first search (DFS), cycle detection, shortest path calculations (using Bellman-Ford), and checks for bipartiteness, among others.

#### File Structure

- **Algorithms.cpp**: Contains implementations of various graph algorithms.
- **Graph.cpp**: Defines the structure of the graph and its properties like adjacency matrix, whether it is directed, and if it has negative weights.

#### Graph.cpp

**Class `Graph`**:
- **Attributes**:
  - `vertices`: Number of vertices in the graph.
  - `adjMatrix`: Adjacency matrix representing the graph.
  - `isDirectedGraph`: Boolean indicating if the graph is directed.
  - `isNegativeWeight`: Boolean indicating if the graph contains any negative weights.

**Key Methods**:
- `isSymmetric()`: Checks if the adjacency matrix is symmetric, implying an undirected graph.
- `hasGraphNegativeWeight()`: Verifies if any edge in the graph has negative weight.
- `loadGraph()`: Initializes the graph properties based on the input matrix.
- `printGraph()`: Outputs the number of vertices and edges.
- `setVertices()`, `getVertices()`: Set or get the number of vertices.
- `setAdjMatrix()`, `getAdjMatrix()`: Set or get the adjacency matrix.
- `isDirected()`, `hasNegativeWeight()`: Return the respective boolean properties.

### Detailed Implementation of Key Functions in Algorithms.cpp

---

#### isConnected()

The `isConnected()` function determines if the graph is connected. This function primarily uses Depth-First Search (DFS) to explore the graph. Here's how it works:

- **Initial Check**: If the graph has no vertices, it returns `true` as an empty graph is trivially connected.
- **DFS Initialization**: A boolean vector `visited` keeps track of visited vertices. DFS begins from vertex 0.
- **DFS Execution**: The `dfs()` function is called with the starting vertex 0. It recursively visits all vertices that are directly or indirectly connected to vertex 0 by following edges that have non-zero weights in the adjacency matrix.
- **Connectivity Check**: After the DFS completes, the function checks if all vertices were visited. If any vertex was not visited, the function returns `false`, indicating that the graph is not connected. Otherwise, it returns `true`.

This method effectively checks connectivity for both directed and undirected graphs, though for directed graphs, it specifically checks for reachability from the first vertex.

---

#### shortestPath()

The `shortestPath()` function utilizes the Bellman-Ford algorithm to find the shortest path between two specified vertices and also checks for the presence of any negative-weight cycles that would affect the shortest path calculation. Here's how the implementation unfolds:

- **Bellman-Ford Algorithm**: Implemented in `bellmanFord()`, this function initializes distances from the source to all vertices as infinity, except the source vertex which is set to zero. It then iteratively relaxes all the edges up to `V-1` times (where `V` is the number of vertices).
- **Path Reconstruction**: If the destination is reachable, the function constructs the path from source to destination using the `parent` array filled during edge relaxation.
- **Negative Cycle Detection**: After relaxing edges, it checks if any further relaxation would decrease the distance, indicating a negative-weight cycle.
- **Output**: The `shortestPath()` function captures the output from `bellmanFord()` and formats it into a readable string describing the path, or returns an error message if a negative cycle is present.

This function is particularly useful for graphs with potentially negative weights and can indicate the unsuitability of the graph for certain applications due to negative cycles.

---

#### isContainsCycle()

The `isContainsCycle()` function checks if the graph contains any cycles. It distinguishes between directed and undirected graphs and uses appropriate helper functions for each:

- **Directed Graphs**: Utilizes `isCyclicDirected()`, which performs a DFS. It tracks visited nodes and nodes currently in the recursion stack. If it revisits a node already in the recursion stack, a cycle is detected.
- **Undirected Graphs**: Uses `isCyclicUndirected()`, which also relies on DFS. It checks if an already visited node is revisited through a different parent, indicating a cycle.
- **Cycle Reporting**: If a cycle is detected, the specific cycle is printed using `printCycle()`, which traces back the path constituting the cycle.

This function is essential for detecting feedback loops in directed graphs or loops in undirected graphs, which can be critical for applications requiring acyclic graph structures.

---

#### isBipartite()

The `isBipartite()` function determines if the graph can be colored with two colors such that no two adjacent vertices have the same color, using a Breadth-First Search (BFS):

- **Color Initialization**: Vertices are initially uncolored (`-1`).
- **BFS Process**: Starting from any uncolored vertex, it is colored with one color, and all its neighbors are colored with the alternate color. This process continues for all neighbors.
- **Conflict Check**: If a vertex is required to be colored with a color different from a previously assigned color, the graph is declared not bipartite.
- **Result Composition**: If the graph is bipartite, the function categorizes vertices into two groups based on their colors and formats this information into a readable string.

This function is useful for problems where dual categorization is required and for checking if a graph's structure supports such separation.

---

#### hasNegativeCycle()

The `hasNegativeCycle()` function checks if the graph contains any negative-weight cycles using the Bellman-Ford algorithm:

- **Cycle Detection and Exception Handling**: It attempts to find shortest paths using `bellmanFord()`. If a negative cycle is detected during this process, a `NegativeCycleException` is thrown, which is caught to confirm the presence of a negative cycle.
- **Comprehensive Check**: The function examines potential cycles involving all vertices to ensure complete detection.
- **Output**: It prints a message indicating the presence or absence of a negative cycle.

This function is crucial for validating graphs before applying algorithms that assume non-negative edge weights, such as Dijkstra's algorithm.

- **Utility Functions**:
  - `printCycle()`: Prints a cycle found in the graph.
  - `removeAllTheVerticesFromPathTillI()`: Utility function used in cycle detection to modify the path to illustrate the cycle properly.

---

#### Compilation and Execution

To compile and run these implementations, make sure to link both `.cpp` files with their respective headers and ensure all dependencies are met. Use the following commands:

```bash
g++ -o graph_program Algorithms.cpp Graph.cpp -I.
./graph_program
```
