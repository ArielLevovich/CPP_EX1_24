#include "Graph.hpp"
#include "Algorithms.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace ariel;
using namespace std;

int main()
{
    Graph g;
    // 3x3 matrix that represents a connected graph.
    const vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl; 
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;
    cout << Algorithms::hasNegativeCycle(g) << endl;     
    cout << Algorithms::isBipartite(g) << endl;        

    // 5x5 matrix that represents a non-connected graph with a cycle.
    const vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();            
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl;
    cout << Algorithms::isContainsCycle(g) << endl; 
    cout << Algorithms::hasNegativeCycle(g) << endl;
    cout << Algorithms::isBipartite(g) << endl;        

    // 5x5 matrix that reprsents a connected weighted graph.
    const vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };    
    
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl; 
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl;
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::hasNegativeCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        

    // 5x4 matrix that reprsents invalid graph.
    const vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

    // 7x7 matrix that represents a non-connected graph with a cycle.
    const vector<vector<int>> graph5 = {
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},};

    g.loadGraph(graph5); // Load the graph to the object.

    g.printGraph();            
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl;
    cout << Algorithms::isContainsCycle(g) << endl; 
    cout << Algorithms::hasNegativeCycle(g) << endl;
    cout << Algorithms::isBipartite(g) << endl;    

    // 7x7 matrix that represents a non-connected graph with a cycle.
    const vector<vector<int>> graph6 = {
        {0, 0, 0, 0},
        {4, 0, -6, 0},
        {0, 0, 0, 5},
        {0, -2, 0, 0}};

    g.loadGraph(graph6); // Load the graph to the object.

    g.printGraph();            
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl;
    cout << Algorithms::isContainsCycle(g) << endl; 
    cout << Algorithms::hasNegativeCycle(g) << endl;
    cout << Algorithms::isBipartite(g) << endl;   

    vector<vector<int>> graph7={{0, 10, -1, 1, 0},
                                {10, 0, 10, 0, 0},
                                {-1, 10, 0, 0, 2},
                                {1, 0, 0, 0, 0},
                                {0, 0, 2, 0, 0}};
    g.loadGraph(graph7); // Load the graph to the object.

    g.printGraph();            
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, g.getVertices()-1) << endl;
    cout << Algorithms::isContainsCycle(g) << endl; 
    cout << Algorithms::hasNegativeCycle(g) << endl;
    cout << Algorithms::isBipartite(g) << endl;   
}
