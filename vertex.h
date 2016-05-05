#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <vector>

using namespace std;

class Vertex {
  public:
    Vertex( char, int );
    void insertEdge( Vertex * );
    char id;
    int index;
    vector<Vertex *> edges;
};

#endif