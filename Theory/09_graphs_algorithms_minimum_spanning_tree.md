# Minimum Spanning Tree

Tree which **connects graph nodes** using **edges with minimum weight**.

 - **Not directed** graph
 - Graph has to be **connected**
 - tree -> connected acyclic graph
 - number of edges = `|V| - 1`

## Examples

<img src="images/graph_algorithms_shortest_path_minimum_spanning_trees_examples.png" width="500"><br>

## Prim's Algorithm

 - Expand tree by adding edges and according node
    - **Selection**: choose edge `(u, v)` of least weight such that `u` already belongs in the tree and `v` does not;
    - **Beggining**: Any node
 - Identical to Dijkstra's Algorithm
    - Node information:
        - `dist(v)` - least weight edge that connect to a vertice in the tree
        - `path(v)` - last vertice to change `dist(v)`
        - `known(v)` - `true` if vertice was precessed and belongs to the tree
    - After selecting a vertice `v`, for each not processed `w`, adjacent to `v` do `dist(w) = min {dist(w), cost(v, w)}`
    - Execution Time:
        - `O(|V|^2)` without priority queue
        - `O(|V| * log|V|)` with priority queue

<img src="images/graph_algorithms_shortest_path_minimum_spanning_trees_prim.png" width="500"><br>

## Kruskal's Algorithm

 - analize all edges from lighest to heaviest and **accept all that do not create loops** (greedy) 
 - method:
    - **forest**: initially with one vertice in each tree
    - add an edge and merge two trees
    - when the algorithm ends we only get one tree
 - **Edge acceptande** - Search/Merge Algorithm:
    - represented as trees
    - if two vertices belong to the same tree/set, one more edge between them creates a loop
    - if two vertices belong from disjointed sets, accepting an edge is the same as applying a Union operation
 - **Edge selection**: sort by weight or build a priority queue in linear time and use `deleteMin` (heapsort)
    - Time: `O(|E| log|E|)`, dominated by queue operations
    - Since `|E| <= |V|^2`, `log|E| <= 2log|V|`, efficiency is also `O(|E| log|E|)`

```
void kruskal() {
   int edgesAccepted = 0;
   
   PriorityQueue<Edge> h = readGraphIntoHeapArray();
   h.buildHeap();
   DisjSet<Vertex> s = new DisjSet(NUM_VERTICES);
   
   while(edgesAccepted < NUM_VERTICES -1 ) {
      Edge e = h.deleteMin(); // e = (u,v)
      SetType uset = s.find(u);
      SetType vset = s.find(v);
      if (uset != vset) {
         edgesAccepted++;
         s.union(uset, vset);
      }
   }
}
```

<img src="images/graph_algorithms_shortest_path_minimum_spanning_trees_kruskal_1.png" width="500"><br>

<img src="images/graph_algorithms_shortest_path_minimum_spanning_trees_kruskal_2.png" width="500"><br>
