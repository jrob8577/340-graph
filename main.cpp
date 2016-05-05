#include <iostream>

#include "graph.h"

using namespace std;

int main() {

  Graph graph;

  graph.insertVertex( 'P' );
  graph.insertVertex( 'Q' );
  graph.insertVertex( 'R' );
  graph.insertVertex( 'S' );
  graph.insertVertex( 'T' );
  graph.insertVertex( 'W' );
  graph.insertVertex( 'X' );
  graph.insertVertex( 'Y' );
  graph.insertVertex( 'Z' );

  graph.insertEdge( 'P', 'R' );
  graph.insertEdge( 'P', 'W' );
  graph.insertEdge( 'R', 'X' );
  graph.insertEdge( 'Q', 'X' );
  graph.insertEdge( 'W', 'S' );
  graph.insertEdge( 'W', 'Y' );
  graph.insertEdge( 'S', 'T' );
  graph.insertEdge( 'T', 'W' );
  graph.insertEdge( 'Y', 'Z' );
  graph.insertEdge( 'Y', 'R' );

  cout << "Distance from P to Z is " << graph.dfs( 'P', 'Z' ) << endl;

  return 0;
}