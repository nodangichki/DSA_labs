#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w); // func to add an edge to graph
    void DFS(int v); // DFS of the vertices reachable from v
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 	// Add w to v’s list.
}

void Graph::DFS(int v)
{
    visited[v] = true;    	// Mark the current node as visited and
    cout << v << " ";		// print it
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    Graph g; // Create a graph given in the above diagram
    int Start = 5;
    g.addEdge(0, 1); g.addEdge(0, 4);
    g.addEdge(1, 5); g.addEdge(1, 0); g.addEdge(1, 2);
    g.addEdge(2, 1); g.addEdge(2, 6); g.addEdge(2, 3);
    g.addEdge(3, 2); g.addEdge(3, 7);
    g.addEdge(4, 0); g.addEdge(4, 8);
    g.addEdge(5, 1); g.addEdge(5, 10); g.addEdge(5, 6);
    g.addEdge(6, 5); g.addEdge(6, 2); g.addEdge(6, 11);
    g.addEdge(7, 3); g.addEdge(7, 12);
    g.addEdge(8, 4); g.addEdge(8, 9);
    g.addEdge(9, 8); g.addEdge(9, 10);
    g.addEdge(10, 9); g.addEdge(10, 11); g.addEdge(10, 5);
    g.addEdge(11, 6); g.addEdge(11, 10); g.addEdge(11, 12);
    g.addEdge(12, 7); g.addEdge(12, 11);
    cout << "Depth First Search (from vertex " << Start << " ) \n";
    g.DFS(Start);
    system("PAUSE"); return 0;
}
