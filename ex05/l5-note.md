# GRAPH

## dense vs sparse
$E \approx V^2$ vs $E \approx V$  


## Representation
- adjacency matrix

- adjacency list

- edge list (usu. in input files)


## Traversal
- bfs: `queue`, FIFO

- dfs: recursive, still $O(V + E)$ time complexity


## Problem: City Planning
Add min edges to make graph connected  
**connected component**: a connected maximal subgraph of graph  
if $c$ connected componets, then $c-1$ edges needed


## Problem: Ordering of Graph
topological ordering  
use `deque`, `push_front()` after dfs  


## Shortest Path
- single source shortest path (unweighted)
- Dijkstra: a queue, an array of distance
- Bellman-Ford: $u$, $v$ adjacent, `dist[u] = min(dist[u], dist[v]+w)`, $O(VE)$  
  improve: 
- Floyd-Warshall: `adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j])`, $O(V^3)$
  order of loops: `k-i-j`
