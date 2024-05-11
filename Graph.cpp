#include <iostream>
#include <vector>
#include <iostream>
#include "Graph.hpp"

using namespace std;

namespace ariel {
    bool Graph::isSymmetric(const vector<vector<int>> mtr){
        //function that checks if a matrix is symetric - means the graph is undirected.
        for (unsigned int i = 0; i < vertices; i++) {
            for (unsigned int j = 0; j < vertices; j++) { 
                if (mtr[i][j] != mtr[j][i]) {
                    return false; //means the graph is directed
                }
            }
        }
        return true;
    }
    bool Graph::hasGraphNegativeWeight(const vector<vector<int>> mtr) {
        for (unsigned int i = 0; i < vertices; i++) {
            for (unsigned int j = 0; j < vertices; j++) { 
                if (mtr[i][j] < 0) {
                    return true;
                }
            }
        }
        return false;
    }  
    void Graph::loadGraph(const vector<vector<int>> mtr) {
        vertices = mtr.size();
        isNegativeWeight = hasGraphNegativeWeight(mtr); 
        if(isSymmetric(mtr)){
            setAdjMatrix(mtr,false);  //if the matrix is symmetric , then set the bool isDirectedGraph = false
        }else{
            setAdjMatrix(mtr,true);
        }                
    }
    
    void Graph::printGraph() {
        int edges = 0;
        if (isDirectedGraph) {
            // Count all non-zero entries for a directed graph
            for (unsigned int i = 0; i < vertices; i++) {
                for (unsigned int j = 0; j < vertices; j++) {
                    if (adjMatrix[i][j] != 0) {
                        edges++;
                    }
                }
            }
        } else {
            // Count each edge only once for an undirected graph
            for (unsigned int i = 0; i < vertices; i++) {
                for (unsigned int j = i; j < vertices; j++) { // Start from i to avoid counting twice
                    if (adjMatrix[i][j] != 0) {
                        edges++;
                    }
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
    const vector<vector<int>> Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    // Setter for the adjacency matrix
    void Graph::setAdjMatrix(const vector<vector<int>> graph, bool isDirectedGraph) {
        // Check if the matrix is square
        unsigned int rows = graph.size();
        for (const auto& row : graph) {
            if (row.size() != rows) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        this->adjMatrix = graph;
        this->isDirectedGraph = isDirectedGraph;
    }    
    
    bool Graph::isDirected() const {
        return isDirectedGraph;
    }

    bool Graph::hasNegativeWeight() const {
        return isNegativeWeight;
    }
}
