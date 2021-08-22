#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Leetcode 547: 省份数量
// 并查集

class Solution {
    vector<int> size;
    vector<int> parent;
    // 用quick-union
    int Find(int m) {
        while (m != parent[m]) {
            m = parent[m];
        }
        return m;
    }
    void Union(int m, int n) {
        int mRoot = Find(m);
        int nRoot = Find(n);
        if (mRoot == nRoot)
            return;
        if (size[mRoot] > size[nRoot]) {
            parent[nRoot] = mRoot;
            size[mRoot] += size[nRoot];
        } else {
            parent[mRoot] = nRoot;
            size[nRoot] += size[mRoot];
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                if (isConnected[row][col] == 1) {
                    Union(row, col);
                }
            }
        }
        int circle = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                circle++;
            }
        }
        return circle;
    }
};

int main() {
    vector<vector<int>> isConnected1 = {
        {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}};
    vector<vector<int>> isConnected2 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution s;
    cout << s.findCircleNum(isConnected1) << endl;
    cout << s.findCircleNum(isConnected2) << endl;
    return 0;
}