#include <iostream>
#include <vector>

using namespace std;

// Leetcode 684: 冗余连接
// 并查集
// 一棵树，如果在遍历到一条新的边时，发现它们属于同一个连通分量，那必然出现了环，这是由树的性质决定的

class UnionFind {
    vector<int> size;
    vector<int> parent;

public:
    UnionFind(int len) {
        size = vector<int>(len + 1, 1);
        parent = vector<int>(len + 1);
        for (int i = 1; i < len + 1; i++) {
            parent[i] = i;
        }
    }
    int Find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void Union(int p, int q) {
        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot == qRoot) {
            return;
        }
        if (size[pRoot] > size[qRoot]) {
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        } else {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
    }
    bool Connected(int p, int q) { return Find(p) == Find(q); }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int numEdges = edges.size();
        UnionFind uf(numEdges);
        for (vector<int> edge : edges) {
            if (uf.Connected(edge[0], edge[1])) {
                return edge;
            } else {
                uf.Union(edge[0], edge[1]);
            }
        }
        return {};
    }
};