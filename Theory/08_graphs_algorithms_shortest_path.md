# Graph Algorithms - Shortest Path

## Problem
 - Given a **weighted graph** `G = (V, E)` and a vertice `s`, we need to obtain the "shortest" path (minimal total weight) from `s` to **every other vertice** in `G`

<img src="images/graph_algorithms_shortest_path_problem.png" width="500"><br>

## Variations
 - **Regular Case**: weigthed graph, stringly connected with weights >= 0
 - **Not-directed graph**
    - Same as with directed graph but with simetrical edges
 - **Not connected graph**:
    - There may not be a route to some vertices, giving us an infinite route
 - **Not weighted graph**:
    - Same as regular case with weights = 1 (shortest path = least ammount of edges)
 - **Edges with negative weight**_
    - There are less efficient algorithms for this case when compared to the regular case
    - Loops with negative weights make the shortest route undefined

## Applications

 - **Route planning**
 - **Overall planning problems**

## Not-weighted directed graph case

 - **Basic method**: (depth-first search + distance calculations)
    1. Make distance to vertice `s` equal to 0 and all others's equal to infinite
    2. Between all explored vertices (distance != infinite) and not processed in step 3, choose to process vertice `v` with the least distance
    3. Process vertice `v`: analize `adj(v)`, marking the ones not yet explored (distance = infinite) with distance v + 1
    4. Repeat process 2 and 3, if there are unexplored vertices

### Data Structures
 - Using a queue (FIFO) to insert the newly explored vertices and extract the next vertice to process (BFS), we can garentee the desired progression order
 - To each vertice we must have the following information:
    - **dist**: distance to the original vertice (`s`)
    - **path**: antecessor vertice in the shortest path

### Pseudo-Code

```
SHORTEST-PATH-UNWEIGHTED(G=(V,E), s):
    for each v ∈ V do
        dist(v) ← infinite
        path(v) ← nil
    dist(s) ← 0
    Q ← { }
    
    ENQUEUE(Q, s)
    while Q != { } do
        v ← DEQUEUE(Q)
        for each w ∈ Adj(v) do
            if dist(w) = infinite then
                ENQUEUE(Q, w)
                dist(w) ← dist(v) + 1
                path(w) ← v
```

<img src="images/graph_algorithms_shortest_path_not-weighted.png" width="500"><br>

## Weighted directed graph case

 - **Regular Method** similar to not-weighted method
 - Distance is obtained by adding edges's weights instead of 1
 - Next vertice to process still is the one with the least distance
    - But we no longer need the oldest one - use a **priority queue** (minimum distance in the head) instead of a regular queue
    - But it may be necessary to **revise the distance** of an **explored and unprocessed** vertice - use a **changeable priority queue**
    - The order is crucial to garentee that the distance from the staring vertice to the already processed vertices is no longer changed, assuming that there are no negative weights
 - Its a **greedy algorithm**: in each step we want to **minimze distance**

### Dijkstra Algorithm - Pseudo-Code

```
DIJKSTRA(G, s): // G=(V,E), s  V
    for each v ∈ V do
        dist(v) ← infinite
        path(v) ← nil
    dist(s) ← 0
    Q ← { } // min-priority queue

    INSERT(Q, (s, 0)) // inserts s with key 0
    while Q != { } do
        v ← EXTRACT-MIN(Q) // greedy
        for each w ∈ Adj(v) do
            if dist(w) > dist(v) + weight(v,w) then
                dist(w)  dist(v)+ weight(v,w)
                path(w)  v
                if w !∈ Q then // old dist(w) was infinite
                    INSERT(Q, (w, dist(w)))
                else
                    DECREASE-KEY(Q, (w, dist(w)))
```

<img src="images/graph_algorithms_shortest_path_weighted.png" width="500"><br>

### `DECREASE-KEY` efficiency

 - Imagine the `priority queue` implemented with a `heap` (array) with the minimum in its head and let `n` be the heap size (maximum is |V|)
 - **Naive Method**: *O(n)*
    1. Sequentially search the object array which key we want to change: O(n)
    2. Go up (or down) the object in the tree until we have reestablished the tree's invariation (each node lesser or equal then its children): O(log n)
 - **Updated Method**: *O(log n)*
