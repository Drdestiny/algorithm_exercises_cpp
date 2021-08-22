#include <iostream>
#include <vector>

using namespace std;

// Leetcode 1579: 保证图可完全遍历

class UnionFind {
private:
    vector<int> parent;
    vector<int> sz;
    int compNum;

public:
    UnionFind(int len) : compNum(len) {
        sz = vector<int>(len, 1);
        parent = vector<int>(len);
        for (int i = 0; i < len; i++) {
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
        if (pRoot != qRoot) {
            if (sz[pRoot] > sz[qRoot]) {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            } else {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            compNum--;
        }
    }
    bool Connected(int p, int q) { return Find(p) == Find(q); }

    int getCount() { return compNum; }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        int edgeNum = edges.size();
        if (edgeNum == 0) {
            return 0;
        }
        // 将node编号变为从0开始
        for (auto edge : edges) {
            edge[1]--;
            edge[2]--;
        }
        UnionFind ufAlice(n);
        UnionFind ufBob(n);
        int numEdgesToRemove = 0;
        // 先处理公共边
        for (auto edge : edges) {
            if (edge[0] == 3) {
                if (!ufAlice.Connected(edge[1], edge[2])) {
                    ufAlice.Union(edge[1], edge[2]);
                    ufBob.Union(edge[1], edge[2]);
                } else {
                    numEdgesToRemove++;
                }
            }
        }
        // 再处理Alice边和Bob边
        for (auto edge : edges) {
            if (edge[0] == 1) {
                if (!ufAlice.Connected(edge[1], edge[2])) {
                    ufAlice.Union(edge[1], edge[2]);
                } else {
                    numEdgesToRemove++;
                }
            } else if (edge[0] == 2) {
                if (!ufBob.Connected(edge[1], edge[2])) {
                    ufBob.Union(edge[1], edge[2]);
                } else {
                    numEdgesToRemove++;
                }
            }
        }
        return numEdgesToRemove;
    }
};

int main() {
    vector<vector<int>> edges{{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
                              {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    Solution s;
    cout << s.maxNumEdgesToRemove(4, edges) << endl;
    return 0;
}