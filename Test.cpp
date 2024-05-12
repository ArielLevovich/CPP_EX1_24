#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test is Not Connected")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test Undirected shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}

TEST_CASE("Test Directed shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 0},
        {4, 0, -1, 0},
        {0, 0, 0, 5},
        {0, -2, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1->2->3");
}

TEST_CASE("Test Directed shortestPath Find Negative Cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 13},
        {4, 0, -6, 0},
        {0, 0, 0, 5},
        {0, -2, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "The graph contains a negative weight cycle.");
}

TEST_CASE("Test Undirected shortestPath - No Path Exists")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path from source to destination.");
}

TEST_CASE("Test Directed shortestPath - No Path Exists")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 0, 0, 0},
        {4, 0, -6, 0},
        {0, 0, 0, 5},
        {0, -2, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "No path from source to destination.");
}

TEST_CASE("Test Directed with a cycle - shortestPath")
{
    ariel::Graph g;
    const vector<vector<int>> graph5 = {
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->5->2->1");
}

TEST_CASE("Test Undirected isBipartite - Not")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite.");
}
TEST_CASE("Test Directed isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test Undirected Graph Does Not ContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test Undirected Graph ContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test Directed Is Contains Cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},};

    g.loadGraph(graph); 

    CHECK(ariel::Algorithms::isContainsCycle(g) == true);     
}

TEST_CASE("Test Directed Does Not Contain Cycle")
{
    ariel::Graph g;
    const vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph); 

    CHECK(ariel::Algorithms::isContainsCycle(g) == false);     
}

TEST_CASE("Is Graph Directed")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},};

    g.loadGraph(graph); 

    CHECK(g.isDirected() == true);       
}

TEST_CASE("Is Graph UnDirected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    g.loadGraph(graph); 

    CHECK(g.isDirected() == false);       
}

TEST_CASE("Directed Has Negative Cycle")
{
    ariel::Graph g;
    const vector<vector<int>> graph6 = {
        {0, 0, 0, 0},
        {4, 0, -6, 0},
        {0, 0, 0, 5},
        {0, -2, 0, 0}};
    g.loadGraph(graph6); 

    CHECK(ariel::Algorithms::hasNegativeCycle(g) == true);       
}

TEST_CASE("Directed Does Not Have Negative Cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},};

    g.loadGraph(graph); 

    CHECK(ariel::Algorithms::hasNegativeCycle(g) == false);       
}

TEST_CASE("UnDirected Does Not Have Negative Cycle")
{
    ariel::Graph g;
    const vector<vector<int>> graph6 = {
        {0, 1, 0, 0},
        {1, 0, -6, 0},
        {0, -6, 0, 4},
        {0, 0, 4, 0}};
    g.loadGraph(graph6); 

    CHECK(ariel::Algorithms::hasNegativeCycle(g) == false);       
}
