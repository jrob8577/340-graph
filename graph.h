#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>

#include "vertex.h"

using namespace std;

class Graph {
  public:
    Graph();
    void insertVertex( char );
    void insertEdge( char, char );
    int dfs( char, char );
  private:
    Vertex * find( char );
    vector<Vertex *> vertices;

    int counter;
};

#endif