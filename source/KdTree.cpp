#if 0
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class KDTree {
public:
    KDTree(int k) : k(k), _root(NULL) {}
    void insert(vector<int> point) { _root = insertRec(_root, point, 0); }
    vector<int> nearestNeighbor(vector<int> point) {
        vector<int> res(k);
        double minDist = numeric_limits<double>::max();
        nearestNeighborRec(_root, point, res, minDist, 0);
        return res;
    }
private:
    int k;
    Node* _root;
    Node* insertRec(Node* node, vector<int>& point, int depth) {
        if (!node) return new Node(point);
        int cd = depth % k;
        if (point[cd] < node->point[cd]) node->left = insertRec(node->left, point, depth + 1);
        else node->right = insertRec(node->right, point, depth + 1);
        return node;
    }
    double dist(vector<int>& a, vector<int>& b) {
        double res = 0.0;
        for (int i = 0; i < k; i++)res += pow(a[i] - b[i], 2);
        return sqrt(res);
    }
    void nearestNeighborRec(Node* node, vector<int>& target, vector<int>& res, double& minDist, int depth) {
        if (!node)return;
        double d = dist(node->point, target);
        if (d < minDist) { minDist = d; res = node->point; }
        int cd = depth % k;
        if (target[cd] < node->point[cd]) {
            nearestNeighborRec(node->left, target, res, minDist, depth + 1);
            if (minDist >= abs(target[cd] - node->point[cd]))nearestNeighborRec(node->right, target, res, minDist, depth + 1);
        }
        else {
            nearestNeighborRec(node->right, target, res, minDist
                , depth + 1);
            if (minDist >= abs(target[cd] - node->point[cd]))nearestNeighborRec(node->left, target, res, minDist, depth + 1);
        }
    }
};

int main() {
    KDTree tree(2);
    tree.insert({ 3, 6 });
    tree.insert({ 17, 15 });
    tree.insert({ 13, 15 });
    tree.insert({ 6, 12 });
    tree.insert({ 9, 1 });
    tree.insert({ 2, 7 });
    tree.insert({ 10, 19 });

    vector<int> point = { 10, 10 };
    vector<int> nearest = tree.nearestNeighbor(point);

    cout << "Nearest point to (" << point[0] << ", " << point[1] << ") is (" << nearest[0] << ", " << nearest[1] << ")" << endl;

    vector<int> point1 = { 17, 16 };
    vector<int> nearest1 = tree.nearestNeighbor(point1);

    cout << "Nearest point to (" << point1[0] << ", " << point1[1] << ") is (" << nearest1[0] << ", " << nearest1[1] << ")" << endl;
    return 0;
}
#endif
