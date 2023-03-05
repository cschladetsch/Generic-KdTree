# N-Dimensionsal Generic KD-Tree

christian.schladetsch@gmail.com

## Introduction

A genertic implementation of an N-dimensional KDTree with any node type `Ty` that is a model of [StrictWeakOrdering](https://en.cppreference.com/w/cpp/concepts/strict_weak_order).

*Note*: a single-header only C++17 library that requires no external dependancies or source files.

## Building

```bash
$ mkdir -p build && cd build && cmake .. && ../bin/test
```

## Use Cases

Any time you want to find a set of nearest neighbors in a set of N-dimensional points of arbitrary type `Ty`. `Ty` must behave well with relational operators, such that A < B implies A != B and B > A. 

## Tests

The tests live in the folder `tests` and use Catch3.

## Todo

Always things to do, right?

* Always - always - more tests. Also haven't tested on Ubuntu, but have with VS2019, VS2022, VS Code on Mac and PC.
* There is no memory management. Just have to change KdTree<Ty,N>::NodePtr to be a std::shared_ptr<Node>.
* Add `remove` method.
* Add iteration over all Nodes.
