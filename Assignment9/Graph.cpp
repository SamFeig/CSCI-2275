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
Graph<T>::Graph() = default;

template<class T>
Graph<T>::~Graph() = default;

template<class T>
void Graph<T>::insertEdge(T v1, T v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].key == v2 && i != j){
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
//                    //other direction
//                    adjVertex<T> av2;
//                    av2.v = &vertices[i];
//                    av2.weight = weight;
//                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

template<class T>
void Graph<T>::insertVertex(T n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == n){
            found = true;
            cout<<vertices[i].key<<" found."<<endl;
        }
    }
    if(!found){
        vertex<T> v;
        v.key = n;
        vertices.push_back(v);
        V++;
    }
}

//template<class T>
//int Graph<T>::searchIndex(T value) {
//    for(int i = 0; i < vertices.size(); i++){
//        if(vertices[i].key == value) {
//            return i;
//        }
//    }
//    return -1;
//}

template<class T>
vertex<T>* Graph<T>::search(T value) {
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) {
            return &vertices[i];
        }
    }
    return nullptr;
}

//template<class T>
//bool Graph<T>::adjacent(T value, T other) {
//    int index = searchIndex(value);
//    for(int x = 0; x < vertices[index].adj.size(); x++){
//        if(vertices[index].adj[x].v->key == other) {
//            return true;
//        }
//    }
//    return false;
//}
//
//template<class T>
//void Graph<T>::DFSUtil(vertex<T>* vertex) {
//    vertex->visited = true;
//        for (int x = 0; x < vertex->adj.size(); x++) {
//            if (!vertex->adj[x].v->visited) {
//                vertex->adj[x].v->visited = true;
//                cout << vertex->adj[x].v->key << endl;
//                vertex->adj[x].v->groupID = ID;
//                DFSUtil(vertex->adj[x].v);
//            }
//        }
//}
//
//template<class T>
//void Graph<T>::DFS(T value) {
//    vertex<T> *vertex = search(value);
//    cout<<vertex->key<<endl;
//    vertex->groupID = ID;
//
//    DFSUtil(vertex);
//}

template<class T>
void Graph<T>::BFS(T startValue) {
    queue<vertex<T>*> t;

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
    }

    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].key == startValue) {
            vertices[i].visited = true;
            vertices[i].hops = 0;
            t.push(&vertices[i]);
            break;
        }
    }

    while (!t.empty()) {
        vertex<T>* front = t.front();
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

template<class T>
void Graph<T>::daijkstra(T src) {
    priority_queue<pair<T, int>, vector<pair<T, int>> , greater<pair<T, int>>> pq;

    for(int i = 0; i < vertices.size(); i++) {
        vertices[i].distance = INT_MAX;
    }

    int srcIndex = findIndex(src);
    pq.push(make_pair(src, 0));
    vertices[srcIndex].distance = 0;

    while(!pq.empty()) {
        T u = pq.top().first;
        pq.pop();
        int uIndex = findIndex(u);
        if(uIndex == -1) {
            cout<<u <<" not in vector"<<endl;
            return;
        }

        for(int i = 0; i < vertices[uIndex].adj.size(); i++) {

            T v = vertices[uIndex].adj[i].v->key;
            int weight = vertices[uIndex].adj[i].weight;
            int vIndex = findIndex(v);

            if(vIndex == -1) {
                cout << v << " not in vector" << endl;
                return;
            }

            if((vertices[uIndex].distance + weight) < vertices[vIndex].distance) {
                vertices[vIndex].distance = vertices[uIndex].distance + weight;
                vertices[vIndex].parent = &vertices[uIndex];
                pq.push(make_pair(v, vertices[vIndex].distance));
            }
        }
    }
}

template<class T>
int Graph<T>::findIndex(T start) {
    std::pair<bool, int> result;
    result.first = false;
    result.second = -1;

    auto it1 = vertices.begin();
    auto it = std::find_if(vertices.begin(), vertices.end(), [=] (vertex<T> const& f) { return (f.key == start); });//[=] (vertex<T> const& f) { return (f.key == start); }

    if (it != vertices.end()) {
        result.first = true;
        result.second = distance(it1, it);
    }
    else {
        result.first = false;
        result.second = -1;
    }

    return result.second;
}

template<class T>
int Graph<T>::findDistBetween(T start, T end) {
    clearDistAndHops();
    daijkstra(start);

    vertex<T>* s = search(end);
    if(s != nullptr) {
        return s->distance;
    }
}

template<class T>
void Graph<T>::findPeopleNAway(T start, int num) {
    clearDistAndHops();
    BFS(start);

    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].visited) {
            if(vertices[i].hops == num && vertices[i].hops != 0 && vertices[i].hops != -1) {
                cout << endl << vertices[i].key << " " << vertices[i].hops << endl;
            }
        }
    }
}
template<class T>
void Graph<T>::clearDistAndHops() {
    for(int i = 0; i <= vertices.size(); i++) {
        vertices[i].distance = 0;
        vertices[i].hops = -1;
    }
}

//template<class T>
//void Graph<T>::connectedComponents() {
//
//    for (int i = 0; i < vertices.size(); i++) {
//        vertices[i].visited = false;
//        vertices[i].groupID = 0;
//        ID = 0;
//    }
//    for(int v = 0; v < V; v++) {
//        if(!vertices[v].visited) {
//            ID++;
//            vertices[v].groupID = ID;
//            cout<<vertices[v].groupID<<endl;
////            DFSUtil(&vertices[v]);
//            DFS(vertices[v].key);
//            cout << "\n";
//        }
//    }
//}

template<class T>
void Graph<T>::printGraph(){
    for(int x = 0; x < vertices.size(); x++){
        cout<<vertices[x].key<<"->";
        for(int y = 0; y < vertices[x].adj.size(); y++){
            cout<<vertices[x].adj[y].v->key<<","<<vertices[x].adj[y].weight<<",";
        }
        cout<<endl;
    }
}