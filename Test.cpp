/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"

using namespace std;

// graph1- is connected, is bipartite , no cycle
// graph2- not connected, have cycle, not bipartite
// graph3- is bipartite, is connected,  
// graph4- invalid
// graph5- is connected
// graph6- have negative cycle, 
// graph7- have cycle, have negative cycle,
// graph8- not connected, is bipartite, have negative cycle
// graph9- invalid,one row is shorter then the others
// graph10- is bipartite, not connected , have negative cycle (like two diffrent graphs)

TEST_CASE("Test isConnected")
{
    noa::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(noa::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(noa::Algorithms::isConnected(g) == false);

    // kashir but not connected
    vector<vector<int>> graph8 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, -2, 0},
        {-1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(noa::Algorithms::isConnected(g) == false);

    // a directed graph that have one big cycle 
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 0, 3},
        {1, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(noa::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(noa::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph7 = {
        {0, 2, -1, 0},
        {0, 0, 1, 2},
        {0, 0, 0, -1},
        {-2, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(noa::Algorithms::isConnected(g) == false);

    // two saprate graphs
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);
    CHECK(noa::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    noa::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(noa::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(noa::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph7 = {
        {0, 2, -1, 0},
        {0, 0, 1, 2},
        {0, 0, 0, -1},
        {-2, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(noa::Algorithms::shortestPath(g, 1, 3) == "-1");

    // not connected graph
    vector<vector<int>> graph8 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, -2, 0},
        {-1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(noa::Algorithms::shortestPath(g, 4, 0) == "-1");
    CHECK(noa::Algorithms::shortestPath(g, 3, 4) == "-1"); // 3 is part of the negative cycle 

    // two saprate graphs
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);
    CHECK(noa::Algorithms::shortestPath(g, 4, 0) == "-1");
    CHECK(noa::Algorithms::shortestPath(g, 4, 5) == "4->5");
    CHECK(noa::Algorithms::shortestPath(g, 3, 0) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    noa::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(noa::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(noa::Algorithms::isContainsCycle(g) == "the cycle is: 0->1->2->0");

    vector<vector<int>> graph7 = {
        {0, 2, -1, 0},
        {0, 0, 1, 2},
        {0, 0, 0, -1},
        {-2, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(noa::Algorithms::isContainsCycle(g) == "the cycle is: 0->1->2->3->0");

    // two saprate graphs
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);
    CHECK(noa::Algorithms::isContainsCycle(g) == "the cycle is: 0->1->2->3->0");

}
TEST_CASE("Test isBipartite")
{
    noa::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(noa::Algorithms::isBipartite(g) == "The graph is bipartite: A={2,0,}, B={1,}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(noa::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(noa::Algorithms::isBipartite(g) == "The graph is bipartite: A={4,2,0,}, B={3,1,}");

    vector<vector<int>> graph8 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, -2, 0},
        {-1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(noa::Algorithms::isBipartite(g) == "The graph is bipartite: A={4,2,0,}, B={3,1,}");

    // check if graph with two not connected group is bipartite
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);
    CHECK(noa::Algorithms::isBipartite(g) == "The graph is bipartite: A={4,2,0,}, B={5,3,1,}");
}
TEST_CASE("test negativeCycle"){
    noa::Graph g;
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, -2},
        {0, 0, 1, 0, 0},
        {-3, 0, 0, 2, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(noa::Algorithms::negativeCycle(g) == "the negetive cycle is: 0->1->2->0");

    vector<vector<int>> graph7 = {
        {0, 2, -1, 0},
        {0, 0, 1, 2},
        {0, 0, 0, -1},
        {-2, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(noa::Algorithms::negativeCycle(g) == "the negetive cycle is: 0->2->3->0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(noa::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph8 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, -2, 0},
        {-1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(noa::Algorithms::negativeCycle(g) == "the negetive cycle is: 0->1->2->3->0");

    // check if graph with two not connected group is bipartite
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);
    CHECK(noa::Algorithms::negativeCycle(g) == "the negetive cycle is: 0->1->2->3->0");


}
TEST_CASE("Test invalid graph")
{
    noa::Graph g;
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph4));

    vector<vector<int>> graph9 = {
        {1, 0, 3, 0},
        {0, 1, 0},
        {2, 3, 0, 4},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph9));
}
