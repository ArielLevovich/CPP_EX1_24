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
            bool isDirectedGraph;
            bool isNegativeWeight;
        public:
            void printGraph();
            void loadGraph(const std::vector<std::vector<int>>& mtr);
            unsigned int getVertices() const;            
            const vector<vector<int>>& getAdjMatrix() const;            
            bool isDirected() const;         
            bool hasNegativeWeight() const;   
        private:
            void setAdjMatrix(const vector<vector<int>>& mtr, bool isDirected);
            bool isSymmetric(const vector<vector<int>>& mtr) const;
            void setVertices(unsigned int v);            
            bool hasGraphNegativeWeight(const vector<vector<int>>& mtr) const;
    };
}
