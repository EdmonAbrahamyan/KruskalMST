# KruskalMST
Minimum spanning tree - Kruskal with Disjoint Set 

We sort all the edges of the graph in non-decreasing order of weights. Then put each vertex in its own tree (i.e. its set) via calls 
to the make_set function - it will take a total of O(N). We iterate through all the edges (in sorted order) and for each edge determine 
whether the ends belong to different trees (with two find_set calls in O(1) each). Finally, we need to perform the union of the two 
trees (sets), for which the DSU union_sets function will be called - also in O(1). 
So we get the total time complexity of O(MlogN+N+M) = O(MlogN).


Pseudocode:
 A = ∅
  foreach v ∈ G.V:
    MAKE-SET(v)
 foreach (u, v) in G.E ordered by weight(u, v), increasing:
    if FIND-SET(u) ≠ FIND-SET(v):
       A = A ∪ {(u, v)}
       UNION(FIND-SET(u), FIND-SET(v))
 return A
