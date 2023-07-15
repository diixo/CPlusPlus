// https://itnext.io/the-114-standard-c-algorithms-introduction-2a75a2df4300

/*
Sorting and partitioning algorithms
- Algorithms that operate on sorted or partitioned ranges
- Transformation algorithms
- Left folds and other reductions
- Generators, copies and moves
- Heap and heap
- Searching and min-max

***************************************************
Iterators: the interoperability layer

At the core that lies between C++ data structures and algorithms are iterators. 
Iterators abstract away the details of how a particular data structure is traversed while capturing 
the behavioural limitations that a data structure imposes.

****************************************************
C++ recognizes the following categories of iterators:

- input iterator: advance, read, one pass
- forward iterator: advance, read
- bidirectional iterator: forward iterator + move back
- random access iterator: bidirectional iterator + advance & move back by any integer, calculate distance between two iterators
- contiguous iterator: random access + the storage of elements is contiguous
- output iterator: advance, write, one pass
*/
