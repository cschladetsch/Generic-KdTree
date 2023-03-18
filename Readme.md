# N-Dimensionsal Generic KD-Tree

christian.schladetsch@gmail.com

## Introduction

A generic implementation of an N-dimensional [KDTree](https://en.wikipedia.org/wiki/K-d_tree) with any node type `Q` that has ordinate of type `T0.. TN`, where each supports `float operator-(const Ty &a, const Ty &b)`

*Note*: This a single-header only C++17 library that requires no external dependancies or source files.

## Building

```bash
$ mkdir -p build && cd build && cmake .. && ../bin/test
```

## Use Cases

Any time you want to find a set of nearest neighbors in a set of N-dimensional points with ordinate type arbitrary type `Ty0`... `TyN`. `TyX` must have `float operator-`. That's only conceptual requirement.

## Tests

The tests live in the folder `tests` and use Catch3. Needs nor etests.

## Todo

Always things to do, right?

* Always - always - more tests. Also haven't tested on Ubuntu, but have with VS2019, VS2022, VS Code on Mac and PC.
* There is no memory management. Just have to change KdTree<Ty,N>::NodePtr to be a std::shared_ptr<Node>.
* Add `remove` method.
* Add iteration over all Nodes.
* Currently, all nodes are a tuple of N dimensions of the same type. This is not really a great restriction, even if it is the most practical.
