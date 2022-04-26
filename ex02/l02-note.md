
## Subset Sum
Given set A of n integers, find subset whose sum is x.  
Idea: split $A$ into two subsets $A_1$ $A_2$, $S_i$ = sum of $A_i$.
find $\exist y: y \in S_1 \wedge x-y \in S_2$


## Square Root Decomposition
$A$: array of size n, queries:  
`sum(a, b)`: return $\sum_{i=a}^b A[i]$  
`update(i, v)`: set $A[i] = v$  
Idea: split $A$ into $\sqrt{n}$ subarrays of size $s = \lceil n \rceil$  
$B[i] = \sum_{j=i \cdot s}^{(i+1) \cdot s -1} A[j]$, we have  

`update(i, v)`: update $A[i]$ and $B[i/s]$  
`sum(a, b)`: use $B[a/s+1:b/s]$


## Customer Service Decision Problem 
*n* customer service counters, *m* customers, $i$-th counter takes $s_i$ sec to serve one customer  
how long to serve all customers?  



## Exponential Search
- start at max = min+1


## Knapsack variant
Pick $k$ elements from $n$ elements, find out maximum value.  
Idea: greedy, build solution incrementally.  


## Scheduling
$n$ tasks with start and end times, no overlap allowed, find out maximum tasks that can be fulfilled.  
Idea: choose tasks that end first.  
Using *Greedy* needs optimal substructure.


## bitmask technique
Place the guard


## Questions
1. add `cout << var;` changed how program is compiled? 
2. char vs string: `'a'` vs `"a"`  


