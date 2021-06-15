<h2>Minimum Spanning Tree</h2>

<p>This includes implementation of a minimum spanning tree (MST) algorithm for a weighted undirected graph (Graph). A spanning tree for a Graph g is a tree that 
reaches all the nodes of the graph. The cost for such a spanning tree is the sum of all the edge costs (weights) in the spanning tree’s edge set. Over all possible
spanning trees, the MST is the one with the least total cost (it may not be unique).</p></br>

<p> This implementation uses Prim Minimum Spanning Tree Algorithm. This algorithm is similar in flavor to Dijkstra’s shortest path algorithm."main.cpp" implements
  this without taking into consideration the colours of the edges of the graph.</p></br>
  <p>In "main2.cpp" the edges are given any one of the three colors--say(RED,BLUE,GREEN)--(0,1,2). We compute the MST where the edges are a constraint.e.g all edges
  must be of the choosen color.</p>
  
