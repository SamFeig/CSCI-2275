#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::string color;
    int hops = -1;
    bool visited = false;
    int groupID = 0;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();  
        ~Graph(); 
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();

        void colorVertices(std::string key);
    protected:
    private:
        std::vector<vertex> vertices;
        void countHops(std::string start);
        void connectedComponents();
        void BFS(std::string startValue);
        int ID = 0;
};

#endif // GRAPH_H
