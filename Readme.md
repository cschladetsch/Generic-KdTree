# N-Dimensionsal Generic KD-Tree

christian.schladetsch@gmail.com

## Inrtroduction

A genertic implementation of an N-dimensional KDTree with any node type that is a model of StrictWeakOrdering.

## Use Cases

Any time you want to find a set of nearest neighbors in a set of N-dimensional points of arbitrary type `Ty`. `Ty` must behave well with relational operators, such that A < B implies A != B and/or B > A. 

## Tests

The tests live in the folder `tests` and use NUnit 3.

