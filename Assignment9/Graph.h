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
struct adjVertex{
    vertex<T> *v;
    int weight;
};

template<class T>
struct vertex{
    T key;
    int distance = 0;
    int hops = -1;
    bool visited = false;
    int groupID = 0;
    vertex<T>* parent = nullptr;
    std::vector<adjVertex<T>> adj;

    bool operator==(const vertex& r) {
        return this->key == r.key;
    }
};

template <class T>
class Graph {
public:
    Graph<T>();
    ~Graph();
    void insertVertex(T value);
    void insertEdge(T v1, T v2, int weight);
//    void DFS(T value);
//    int BFS(T startValue, T endValue);
    void BFS(T startValue);
    void printGraph();
    vertex<T>* search(T val);
//    int searchIndex(T value);
//    bool adjacent(T value, T other);
//    void connectedComponents();
    void daijkstra(T src);
    int findDistBetween(T start, T end);
    void findPeopleNAway(T start, int num);

private:
    int V = 0;
    int E = 0;
    int ID = 0;
    vector<vertex<T>> vertices;
//    void DFSUtil(vertex<T>* vertex);
    int findIndex(T start);
    void clearDistAndHops();
};


#endif //ASSIGNMENT8_GRAPH_H
