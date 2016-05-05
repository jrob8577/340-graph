#include "graph.h"

Graph::Graph() {
  counter = 0;
}

void Graph::insertVertex( char id ) {
  Vertex * vertex = new Vertex( id, counter++ );

  vertices.push_back( vertex );
}

void Graph::insertEdge( char from, char to ) {
  Vertex * fromVertex = find( from );
  Vertex * toVertex = find( to );

  fromVertex->insertEdge( toVertex );
}

Vertex * Graph::find( char id ) {
  for( vector<Vertex *>::iterator it = vertices.begin(); it != vertices.end(); ++it ) {
    if( (*it)->id == id ) {
      return *it;
    }
  }

  return NULL;
}

int Graph::dfs( char start, char end ) {
  Vertex * startVertex = find( start );
  Vertex * endVertex = find( end );

  vector<Vertex *> visitQueue;

  // initialize visited array
  int visited[ vertices.size() ];
  for( int i = 0; i < vertices.size(); i++ ) {
    visited[ i ] = -1;
  }

  // Distance to self is 0
  visited[ startVertex->index ] = 0;

  // Enqueue neighbors of start vertex
  for( vector<Vertex *>::iterator it = startVertex->edges.begin(); it != startVertex->edges.end(); ++it ) {
    if( visited[ (*it)->index ] == -1 ) {
      visited[ (*it)->index ] = 1 + visited[ startVertex->index ];
      visitQueue.push_back( *it );
    }
  }

  cout << endl;
  // While Queue not empty, process each entry in Q
  while( ! visitQueue.empty() ) {
    startVertex = visitQueue.front();
    cout << "Visiting " << startVertex->id << endl;

    visitQueue.erase( visitQueue.begin() );

    for( vector<Vertex *>::iterator it = startVertex->edges.begin(); it != startVertex->edges.end(); ++it ) {
      if( visited[ (*it)->index ] == -1 ) {
        cout << "Distance from " << startVertex->id << " to " <<
          (*it)->id << " is " << 1 + visited[ startVertex->index ] << endl;
        visited[ (*it)->index ] = 1 + visited[ startVertex->index ];
        visitQueue.push_back( *it );
      }
    }
  }

  return visited[ endVertex->index ];
}