/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "Graph.hpp"
using namespace std;

namespace noa{

    Graph Graph::loadGraph(vector<vector<int>> graph){
        for(unsigned int i=0; i<graph.size(); ++i){
            if(graph.size() != graph[i].size()){
                throw std::invalid_argument{"Invalid graph: The graph is not a square matrix"};
            }
        }
        
        this->g = graph;
        this->size=graph.size();
        int count=0;
        for(unsigned int i=0; i<this->size; i++){
            for(unsigned int j=0; j<this->size; j++){
                if(this->getWeight(i,j) != 0){
                    count++;
                }
            }
        }
        this->edge = count;
        return *this;
    }

    int Graph::getSize(){
        return this->size;
    }
    
    int Graph::getWeight(unsigned int x, unsigned int y){
        return this->g[x][y];
    }

    void Graph::printGraph(){
        cout << "this graph have " << this->size << " vertex and " << this->edge << " edges"<< endl;
        unsigned int n = static_cast<unsigned int>(this->size);
        for(unsigned int i=0 ; i< n; i++){
            cout << "| ";
            for(unsigned int j=0; j<n; j++){
                cout << to_string(this->g[i][j]);
                cout << " ";
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
}
    



