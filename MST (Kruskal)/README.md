<h2>MINIMUM SPANNING TREE</h2>
<h5>Contains a MST finding alogorithm as the previous one but uses the Kruskal algorithm.</h5>
<p>The Kruskal algorithm involves the following steps:</p>
<ul>
  <li>Create a set containing all edges in the graph and sort them in ascending order.</li>
  <li>Create a forest where all nodes are individual trees. Now remove the edge with minimum length/cost/weight and connect the two nodes corresponding to that
    edge.i.e both nodes will belong to the same tree.</li>
  <li>If the two nodes are already connected i.e they are in the same tree, then just remove the edge from the set.</li>
  <li> Continue this until we have all the nodes in one tree.</li>
  <li>If any node is left out that means the graph is not connected.</li>
  </ul>
  <p>"main.cpp" implements the MST where as "main2.cpp" implements a MST where all edges belong to the same color-i.e edge specific or edge constrained MST.</p> 
  
