#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Leetcode 1319: 连通网络的操作次数
// 连通集

class UnionFind {
private:
    vector<int> sz;
    vector<int> parent;
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
            if (sz[p] > sz[q]) {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            } else {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            compNum--;
        }
    }
    int getCompNum() { return compNum; }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        int connNum = connections.size();
        if (connNum < n - 1) {
            return -1;
        }
        UnionFind uf(n);
        for (int i = 0; i < connNum; i++) {
            uf.Union(connections[i][0], connections[i][1]);
        }
        return uf.getCompNum() - 1;
    }
};

int main() {
    vector<vector<int>> input{{0, 1}, {0, 2}, {1, 2}};
    Solution s;
    cout << s.makeConnected(4, input) << endl;
    return 0;
}