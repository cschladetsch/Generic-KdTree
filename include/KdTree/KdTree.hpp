#pragma once

#include <array>
#include <assert.h>
#include <type_traits>

template <class Ty, int Dim>
struct KDTree {
    struct Node;
    typedef Node* NodePtr;
    typedef std::array<Ty, Dim> Tuple;

    struct Node {
        Tuple point;
        Node *left, *right;
        Node(const Tuple& tuple)
            : point(tuple), left(0), right(0) { }
        Node(std::initializer_list<Ty> values)
            : point(values), left(nullptr), right(nullptr) {
        }
    };

    KDTree() = default;

    void insert(const Tuple &point) {
        _root = insertRecord(_root, point, 0);
    }

    Tuple nearestNeighbor(std::initializer_list<Ty> point) {
        Tuple res;
        double minDist = std::numeric_limits<double>::max();
        getNearestNeighbor(_root, array_from_initializer_list<Ty, Dim>(point), res, minDist, 0);
        return res;
    }

private:
    NodePtr _root =  nullptr;

    NodePtr insertRecord(NodePtr node, const Tuple& point, int depth) {
        if (!node) {
            return new Node(point);
        }

        int cd = depth % Dim;
        if (point[cd] < node->point[cd]) {
            node->left = insertRecord(node->left, point, depth + 1);
        }
        else {
            node->right = insertRecord(node->right, point, depth + 1);
        }

        return node;
    }

    double distance(const Tuple &a, const Tuple& b) {
        double res = 0.0;
        for (int i = 0; i < Dim; i++) {
            res += pow(a[i] - b[i], 2);
        }

        return sqrt(res);
    }

    void getNearestNeighbor(NodePtr node, const Tuple &target, Tuple& res, double& minDist, int depth) {
        if (!node) {
            return;
        }

        double d = distance(node->point, target);
        if (d < minDist) { 
            minDist = d;
            res = node->point; 
        }

        int cd = depth % Dim;
        if (target[cd] < node->point[cd]) {
            getNearestNeighbor(node->left, target, res, minDist, depth + 1);
            if (minDist >= abs(target[cd] - node->point[cd])) {
                getNearestNeighbor(node->right, target, res, minDist, depth + 1);
            }
        }
        else {
            getNearestNeighbor(node->right, target, res, minDist , depth + 1);
            if (minDist >= abs(target[cd] - node->point[cd])) {
                getNearestNeighbor(node->left, target, res, minDist, depth + 1);
            }
        }
    }

    constexpr array<Ty, Dim> array_from_initializer_list(initializer_list<Ty> l) {
        assert(l.size() == N);
        std::array<Ty, Dim> result;
        std::copy(l.begin(), l.end(), result.begin());
        return result;
    }
};
