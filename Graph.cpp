#include <iostream>
#include <vector>
#include <iostream>
#include "Graph.hpp"

using namespace std;

namespace ariel {
    void Graph::loadGraph(const vector<vector<int>>& graph) {
            vertices = graph.size();
            adjMatrix = graph;  
        }

    // Print the details of the graph
    void Graph::printGraph() {
        int edges = 0;
        vector<vector<bool>> boolMat(vertices, vector<bool>(vertices, false));  

        for (unsigned int i = 0; i < vertices; i++) {
            for (unsigned int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] != 0 && !boolMat[i][j]) {  
                    if (adjMatrix[i][j] == adjMatrix[j][i]) {
                        boolMat[j][i] = true;  //for the case of undirected graphs - won't count the same edge twice.
                    }
                    edges++;
                }
            }
        }
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
    }

    // Getter for vertices
    unsigned int Graph::getVertices() const {
        return vertices;
    }

    // Setter for vertices,allowing setting vertices with adjustment to the adjacency matrix)
    void Graph::setVertices(unsigned int v) {
        if (v != vertices) {
            vertices = v;
            adjMatrix.resize(vertices);
            for (auto& row : adjMatrix) {
                row.resize(vertices, 0);
            }
        }else{
            vertices = v;
        }
    }

    // Getter for the adjacency matrix
    const vector<vector<int>>& Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    // Setter for the adjacency matrix
    void Graph::setAdjMatrix(const vector<vector<int>>& matrix) {
        if (matrix.size() == vertices) {
            adjMatrix = matrix;
        } else {
            cout << "Error: Matrix size does not match the number of vertices." << endl;
        }
    }    
}
