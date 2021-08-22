class UnionFind {
private:
    vector<int> sz;
    vector<int> parent;

public:
    UnionFind(int len) {
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
        }
    }
};