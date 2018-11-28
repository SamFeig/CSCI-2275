#include <iostream>
#include "BST.h"
#include "Graph.h"

using namespace std;


int main(int argc, char*argv[])
{
    int input;
    // Determine the size of the text file.
    //int fileSize = getFileSize(argv[1]);
    //cout << "about to create object\n";
    // Create a new communication network

    BST *bst = new BST();
    bst->addBSTNode(24);
    bst->addBSTNode(5);
    bst->addBSTNode(2);
    bst->addBSTNode(3);
    bst->addBSTNode(36);
    bst->addBSTNode(29);
    bst->addBSTNode(30);
    bst->addBSTNode(16);
    bst->addBSTNode(11);

    bst->deleteRootAndReplaceLeftMin();
    bst->printBST();

//
//    // Free memory and return
//
    delete bst;

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
    g.colorVertices("Boulder");


    return 0;
}
