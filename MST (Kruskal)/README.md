<h2>MINIMUM SPANNING TREE</h2>
<h5>Also contains a MST finidng alogorithm as the previous one but uses the Kruskal algorithm.</h5>
<p>The Kruskal algorithm involves the following steps:</p></br>
<ul>
  <li>Sort all the edges in the graph in the ascending order.</li>
  <li>Create a forest where all nodes are individual trees. Now remove the edge with minimum length/cost/weight and connect the two nodes corresponding to that
    edge.</li>
  <li>If the two nodes are already connected i.e they are in the same tree, then just pop off the edge from the set.</li>
  <li> Continue this until we have all the nodes in one tree.</li>
  <li>If any node is left out that means the graph is not connected.</li>
  </ul>
  