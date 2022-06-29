# Flow, Matching

## Ford-Fulkerson
- augmenting path: a path from $s$ to $t$ that has extra capacity
- back edges: flowing backwards -> cancalling prior flow
- $\mathcal{O}(\mathcal{F}^* \cdot E)$, $\mathcal{F}^*$ = maximum flow.

## Edmonds-Karp
- instead of picking augmenting paths arbitrarily, pick the shortest one (hop-wise)
- bfs
- $\mathcal{O}(VE^2)$


## Maximum Cardinality Matching
alg
- start from empty matching
- `while` exist augmenting paths:
    - find an augmenting path
    - augment along the path

**Hopcroft–Karp**