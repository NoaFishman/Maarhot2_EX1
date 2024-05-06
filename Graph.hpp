/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

namespace noa{

    class Graph{

        vector<vector<int>> g;
        int size;
        int edge;
        
    public:

        Graph loadGraph(vector<vector<int>> g);
        void printGraph();
        int getSize();
        int getWeight(unsigned int x, unsigned int y);

        // constractor
        Graph(){
            g = {{0}};
            size=0;
        }
    };
}