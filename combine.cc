#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> res;
    void backtrace(int n, int k, int idx) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }
        for (int i = idx; i <= n; i++) {
            path.push_back(i);
            backtrace(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrace(n, k, 1);
        return res;
    }
};

int main() {
    Solution s;
    auto vec = s.combine(4, 2);
    return 0;
}