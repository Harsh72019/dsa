#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; 
    list<int>* adj; 
    vector<vector<int>> adjMatrix;    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        adjMatrix.resize(V, vector<int>(V, 0)); 
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); 
        adj[w].push_back(v); 
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }

    void printGraph() {
        for (int v = 0; v < V; v++) {
            cout << "Adjacency list of vertex " << v << ": ";
            for (auto x : adj[v])
                cout << "-> " << x << " ";
            cout << endl;
        }
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}