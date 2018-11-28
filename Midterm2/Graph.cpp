#include "Graph.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(){}; 
Graph::~Graph(){};


void Graph::addEdge(string v1, string v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if(j != vertices[i].adj.size()-1)
                cout << "***";
        }
        cout << endl;
    }

}

void Graph::BFS(string startValue) {
    queue<vertex*> t;

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
    }

    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == startValue) {
            vertices[i].visited = true;
            vertices[i].hops = 0;
            t.push(&vertices[i]);
            break;
        }
    }

    while (!t.empty()) {
        vertex* front = t.front();
        t.pop();
        for(int i = 0; i < front->adj.size(); i++) {
            if (!front->adj[i].v->visited) {
                front->adj[i].v->visited = true;
                front->adj[i].v->hops = front->hops + 1;
                t.push(front->adj[i].v);
            }
        }
    }
}

void Graph::colorVertices(string key) {
    BFS(key);

    for(int i = 0; i < vertices.size(); i++) {
//        Check if reachable from starting vertex
        if(vertices[i].visited) {
            if(vertices[i].hops == 0) {
                vertices[i].color = "Red";
            }
            else if(vertices[i].hops % 2 != 0) {
                vertices[i].color = "Black";
            }
            else {
                vertices[i].color = "Red";
            }
        }
        else {
            vertices[i].color = "";
        }
        cout<<endl<<vertices[i].name<<" "<<vertices[i].hops<<" "<<vertices[i].color<<endl;
    }
}