#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main()
{
    Graph g;
    g.addVertex("Boulder");
    g.addVertex("Denver");
    g.addVertex("New Mexico");
    g.addVertex("Texas");
    g.addVertex("New Orleans");
    //edge written to be undirected
    g.addEdge("Boulder", "Denver", 30);
    g.addEdge("Boulder", "New Mexico", 200);
    g.addEdge("Boulder", "Texas", 500);
    g.addEdge("Denver", "Texas", 300);
    g.addEdge("Texas", "New Orleans", 500);
    g.displayEdges();
    return 0;
}
