//
// Created by Sam Feig on 11/2/18.
//

#include "Graph.h"
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <string>
using namespace std;

template<class T>
Graph<T>::Graph() {
}

template<class T>
Graph<T>::~Graph() {}

template<class T>
void Graph<T>::insertVertex(T value) {
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value){
            found = true;
            cout<<vertices[i].key<<" found."<<endl;
            break;
        }
    }
    if(!found){
        vertex<T> v;
        v.key = value;
        vertices.push_back(v);
        V++;
    }
}

template<class T>
void Graph<T>::insertEdge(T v1, T v2) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].key == v1) {
            for (int j = 0; j < vertices.size(); j++) {
                if (vertices[j].key == v2 && i != j) {
                    vertices[i].adj.push_back(&vertices[j]);
                }
            }
        }
    }
}

template<class T>
int Graph<T>::searchIndex(T value) {
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) {
            return i;
        }
    }
    return -1;
}

template<class T>
vertex<T>* Graph<T>::search(T value) {
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) {
            return &vertices[i];
        }
    }
    return nullptr;
}

template<class T>
bool Graph<T>::adjacent(T value, T other) {
    int index = searchIndex(value);
    for(int x = 0; x < vertices[index].adj.size(); x++){
        if(vertices[index].adj[x]->key == other) {
            return true;
        }
    }
    return false;
}

template<class T>
void Graph<T>::DFSUtil(vertex<T>* vertex) {
    vertex->visited = true;
        for (int x = 0; x < vertex->adj.size(); x++) {
            if (!vertex->adj[x]->visited) {
                vertex->adj[x]->visited = true;
                cout << vertex->adj[x]->key << endl;
                vertex->adj[x]->groupID = ID;
                DFSUtil(vertex->adj[x]);
            }
        }
}

template<class T>
void Graph<T>::DFS(T value) {
    vertex<T> *vertex = search(value);
    cout<<vertex->key<<endl;
    vertex->groupID = ID;

    DFSUtil(vertex);
}

template <class T>
int Graph<T>::BFS(T startValue, T endValue) {
    vertex<T>* e = search(endValue);
    queue<vertex<T> *> t;

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
    }

    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].key == startValue) {
            vertices[i].visited = true;
            t.push(&vertices[i]);
            break;
        }
    }

    while (!t.empty()) {
        vertex<T> *front = t.front();
        t.pop();
        for(int i = 0; i < front->adj.size(); i++) {
            if (!front->adj[i]->visited) {
                front->adj[i]->visited = true;
                front->adj[i]->distance = front->distance + 1;
                front->adj[i]->parent = front;
                t.push(front->adj[i]);
            }
            if(front ==  e) {
                return front->distance-1;
            }
        }
    }
    return 0;
}

template<class T>
void Graph<T>::findLeastIntroductions(T start, T end) {
    vertex<T>* s = search(start);
    vertex<T>* e = search(end);
    connectedComponents();
//    check if in same group
    if(s->groupID != e->groupID) {
        cout<<"No way to introduce them"<<endl;
        return;
    }
//    check if directly adj
    if(adjacent(start, end)) {
        cout<<"No Introduction Needed"<<endl;
        return;
    }
//    not directly adj, needs introductions
    else {
        cout<<BFS(start, end)<<", ";
        for(int i = 0; i < e->distance; i++) {

            if(e->distance > 1) {
                cout<<e->parent->key<<"-";
            }
            else {
                cout<<e->parent->key;
            }
            e = e->parent;
        }
        cout<<endl;
    }
}

template<class T>
void Graph<T>::connectedComponents() {

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
        vertices[i].groupID = 0;
        ID = 0;
    }
    for(int v = 0; v < V; v++) {
        if(!vertices[v].visited) {
            ID++;
            vertices[v].groupID = ID;
            cout<<vertices[v].groupID<<endl;
//            DFSUtil(&vertices[v]);
            DFS(vertices[v].key);
            cout << "\n";
        }
    }
}

template<class T>
void Graph<T>::printGraph(){
    for(int x = 0; x < vertices.size(); x++){
        cout<<vertices[x].key<<"->";
        for(int y = 0; y < vertices[x].adj.size(); y++){
            cout<<vertices[x].adj[y]->key<<",";
        }
        cout<<endl;
    }
}