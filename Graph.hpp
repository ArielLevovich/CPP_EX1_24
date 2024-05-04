#include <string>
#include <vector> 
#include <iostream>

#pragma once
using namespace std;

namespace ariel {
    class Graph {
        private:
            unsigned int vertices;  
            vector<vector<int>> adjMatrix;
        public:
            void printGraph();
            void loadGraph(const std::vector<std::vector<int>> &graph);
            unsigned int getVertices() const;
            void setVertices(unsigned int v);
            const vector<vector<int>>& getAdjMatrix() const;
            void setAdjMatrix(const vector<vector<int>>& matrix);
    };
}
