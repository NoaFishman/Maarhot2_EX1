/*
ID: 319055430
Email: noa.fishman@gmail.com
*/

#include "Algorithms.hpp"
using noa::Algorithms;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    noa::Graph g;
    cout << endl;
    cout << "graph #1" << endl;
    // 3x3 matrix that represents a connected and bipartite graph.
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true)
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: "0->1->2"
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false)
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={2,0,}, B={1,}."
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "0" (false)
    cout << endl;

    cout << "graph #2" << endl;
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "0" (false)
    cout << endl;

    cout << "graph #3" << endl;
    // 5x5 matrix that reprsents a connected weighted and bipartite graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "0->1->2->3->4"
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={4,2,0,}, B={3,1,}."
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "0" (false)
    cout << endl;

    cout << "graph #4" << endl;
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
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
    cout << endl;

    cout << "graph #5" << endl;
    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "0->1->2->3->4"
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={4,2,0,}, B={3,1,}."
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "0" (false)
    cout << endl;

    cout << "graph #6" << endl;
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, -2},
        {0, 0, 1, 0, 0},
        {-3, 0, 0, 2, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 6 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false)
    cout << Algorithms::shortestPath(g, 1, 4) << endl; // Should print: "-1" (there is no path between 1 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "the cycle is: 0->1->2->0"
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false)
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "the negetive cycle is: 0->1->2->0"
    cout << endl;

    cout << "graph #7" << endl;
    vector<vector<int>> graph7 = {
        {0, 2, -1, 0},
        {0, 0, 1, 2},
        {0, 0, 0, -1},
        {-2, 0, 0, 0}};
    g.loadGraph(graph7);

    g.printGraph();                                    // Should print: "Graph with 4 vertices and 6 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false)
    cout << Algorithms::shortestPath(g, 1, 3) << endl; // Should print: "-1" (there is no path between 1 and 4)
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "the cycle is: 0->1->2->3->0"
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false)
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "the negetive cycle is: 0->2->3->0"
    cout << endl;

    cout << "graph #8" << endl;
    vector<vector<int>> graph8 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, -2, 0},
        {-1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 5 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 1, 3) << endl; // Should print: "-1" (there is no path between 1 and 4)
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "the cycle is: 0->1->2->3->0"
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={4,2,0,}, B={3,1,}."
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "the negetive cycle is: 0->1->2->3->0"
    cout << endl;

    cout << "graph #9" << endl;
    vector<vector<int>> graph9 = {
        {1, 0, 3, 0},
        {0, 1, 0},
        {2, 3, 0, 4},
        {0, 0, 0, 5}};

    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
    cout << endl;

    cout << "graph #10" << endl;
    vector<vector<int>> graph10 = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, -2, 0, 0, 0},
        {0, -2, 0, -1, 0, 0},
        {1, 0, -1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph10);

    g.printGraph();                                    // Should print: "Graph with 6 vertices and 10 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4)
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "the cycle is: 0->1->2->3->0"
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={4,2,0,}, B={5,3,1,}."
    cout << Algorithms::negativeCycle(g) << endl;      // Should print: "the negetive cycle is: 0->1->2->3->0"
    cout << endl;

    return 1;
}
