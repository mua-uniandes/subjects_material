# Fenwick tree

Fenwick tree, similar to segment tree, is a data structure specialized for range query processing following a divide and conquer approach with a recursive implementation.

The added value of using Fenwick trees, over other range query solutions, is that this datastructure uses O(n) memory. However, fenwick trees are only usable for group operations, that is the operations that can form a group (are associative, have an inverse, and have a unit).

- Fenwick trees [presentation][pres]
- Implementation [C++][cpp] - Kotlin - Python - Java

[pres]:https://github.com/mua-uniandes/subjects_material/blob/master/Datastructures/fenwick/MUA_fenwicktree.pdf
[cpp]:https://github.com/mua-uniandes/subjects_material/blob/master/Datastructures/fenwick/fenwick.cpp
