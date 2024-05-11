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
    cout << Algorithms::shortestPath(g, 0, 2) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl; 
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
    cout << Algorithms::shortestPath(g, 0, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl; 
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

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << "Is graph directed:" << g.isDirected() << endl;
    cout << "Is graph connected:" << Algorithms::isConnected(g) << endl; 
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;        
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

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
    cout << Algorithms::shortestPath(g, 0, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl; 
    cout << Algorithms::isBipartite(g) << endl;    
}
