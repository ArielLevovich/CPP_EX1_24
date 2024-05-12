### README.md - Algorithms and Graph Classes - Ariel Leibovich - 326535242

---

#### Overview

This README provides an exhaustive explanation of the functionalities and implementation details of the `Algorithms` and `Graph` classes written in C++. These classes demonstrate various graph-related algorithms such as depth-first search (DFS), cycle detection, shortest path calculations (using Bellman-Ford), and checks for bipartiteness, among others.

#### File Structure

- **Algorithms.cpp**: Contains implementations of various graph algorithms.
- **Graph.cpp**: Defines the structure of the graph and its properties like adjacency matrix, whether it is directed, and if it has negative weights.

#### Graph.cpp
The `Graph.cpp` file defines the structure and behavior of a graph in your C++ program through the `Graph` class. This class is designed to manage the graph's essential properties, such as its vertices, adjacency matrix, directed status, and presence of negative weights. Here’s how you chose to implement the management and functionality of any graph using this class:

### Key Components of Graph Implementation

#### 1. **Adjacency Matrix**:
The `adjMatrix` is a two-dimensional vector (`vector<vector<int>>`) that represents the edges between the vertices in the graph. Each cell in the matrix, `adjMatrix[i][j]`, holds a value indicating the weight or presence of an edge between vertex `i` and vertex `j`. If there is no edge, it typically holds a value of zero.

#### 2. **Vertices**:
The `vertices` attribute stores the number of vertices in the graph. This is crucial for iterating over the graph and for resizing the adjacency matrix when the number of vertices changes.

#### 3. **Directed or Undirected Graph**:
The boolean `isDirectedGraph` indicates whether the graph is directed. This affects several functionalities, such as how edges are added to the adjacency matrix and how certain algorithms, like checking if the graph is bipartite or symmetric, are executed.

#### 4. **Negative Weight Detection**:
The `isNegativeWeight` flag is set based on the presence of any negative weights in the graph. This is critical for algorithms that are sensitive to negative weights, like the shortest path finding, where the presence of negative cycles could invalidate certain algorithms like Dijkstra’s.

### Key Methods and Their Functionalities

#### **loadGraph(const vector<vector<int>>& mtr)**:
This method initializes the graph with a given adjacency matrix. It sets the number of vertices based on the size of the matrix and determines whether the graph is directed by checking if the matrix is symmetric. It also checks for negative weights to set the `isNegativeWeight` flag appropriately.

#### **isSymmetric(const vector<vector<int>>& mtr)**:
Checks if the given matrix is symmetric. This is used to determine if the graph should be treated as undirected. In an undirected graph, for any two vertices `i` and `j`, the edge weight from `i` to `j` should be equal to that from `j` to `i` (`mtr[i][j] == mtr[j][i]`).

#### **hasGraphNegativeWeight(const vector<vector<int>>& mtr)**:
Evaluates whether the adjacency matrix contains any negative weights. This information is vital for algorithms that need to know whether the graph has any negative weight edges.

#### **printGraph()**:
Outputs a simple description of the graph, listing the number of vertices and edges. The method counts edges differently based on whether the graph is directed or undirected.

#### **Setter and Getter Methods**:
- `setVertices(unsigned int v)`, `getVertices()`: Manage the number of vertices and resize the adjacency matrix accordingly.
- `setAdjMatrix(const vector<vector<int>> graph, bool isDirectedGraph)`, `getAdjMatrix()`: Set or retrieve the adjacency matrix, ensuring that any set operation maintains the matrix's integrity as a square matrix.

By using these components and methods, your `Graph` class provides a flexible and robust system for managing graphs in your C++ programs, whether they are simple or complex, weighted, directed, or undirected. This setup allows you to manipulate and analyze graph properties effectively, which is essential for the algorithms implemented in `Algorithms.cpp`.

---

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
