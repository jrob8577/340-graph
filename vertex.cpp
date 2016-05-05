#include "vertex.h"

Vertex::Vertex( char value, int i ) {
  id = value;
  index = i;
}

void Vertex::insertEdge( Vertex * edge ) {
  edges.push_back( edge );
}