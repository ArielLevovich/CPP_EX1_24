#include <string>
#include <vector> 
#include <iostream>

#pragma once

namespace ariel {
    class Graph {
        public:
            void printGraph();
            void loadGraph(const std::vector<std::vector<int>> &graph);
    };
}
