#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Leetcode 1202: 交换字符串中的元素
// 并查集

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int len) {
        parent = vector<int>(len);
        for (int i = 0; i < len; i++) {
            parent[i] = i;
        }
        size = vector<int>(len, 1);
    }
    void Union(int p, int q) {
        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot == qRoot)
            return;
        if (size[pRoot] > size[qRoot]) {
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        } else {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
    }
    int Find(int p) {
        while (p != parent[p]) {
            // 路径压缩
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int strLen = s.size();
        UnionFind uf = UnionFind(strLen);
        int pairsLen = pairs.size();
        for (int pairIdx = 0; pairIdx < pairsLen; pairIdx++) {
            uf.Union(pairs[pairIdx][0], pairs[pairIdx][1]);
        }
        unordered_map<int, vector<char>> um;
        for (int i = 0; i < strLen; i++) {
            int root = uf.Find(i);
            if (um.find(root) == um.end()) {
                um[root] = vector<char>(1, s[i]);
            } else {
                um[root].emplace_back(s[i]);
            }
        }
        for (auto iter = um.begin(); iter != um.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(),
                 greater_equal<char>());
        }
        for (int strIdx = 0; strIdx < strLen; strIdx++) {
            int root = uf.Find(strIdx);
            s[strIdx] = um[root].back();
            um[root].pop_back();
        }
        return s;
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int len) {
        parent = vector<int>(len);
        for (int i = 0; i < len; i++) {
            parent[i] = i;
        }
        size = vector<int>(len, 1);
    }
    void Union(int p, int q) {
        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot == qRoot)
            return;
        if (size[pRoot] > size[qRoot]) {
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        } else {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
    }
    int Find(int p) {
        while (p != parent[p]) {
            // 路径压缩
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
};