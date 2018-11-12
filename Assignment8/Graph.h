//
// Created by Sam Feig on 11/2/18.
//
#include <vector>
using namespace std;

#ifndef ASSIGNMENT8_GRAPH_H
#define ASSIGNMENT8_GRAPH_H

template<class T>
struct vertex;

template<class T>
struct vertex {
    T key;
    bool visited = false;
    int distance = 0;
    int groupID = 0;
    vertex<T>* parent = nullptr;
    vector<vertex<T>*> adj;
};

template <class T>
class Graph {
public:
    Graph<T>();
    ~Graph();
    void insertVertex(T value);
    void insertEdge(T v1, T v2);
    void DFS(T value);
    int BFS(T startValue, T endValue);
    void findLeastIntroductions(T start, T end);
    void printGraph();
    vertex<T>* search(T val);
    int searchIndex(T value);
    bool adjacent(T value, T other);
    void connectedComponents();

private:
    int V = 0;
    int E = 0;
    int ID = 0;
    vector<vertex<T>> vertices;
    void DFSUtil(vertex<T>* vertex);
};


#endif //ASSIGNMENT8_GRAPH_H
