#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int tmpSum;
    vector<int> path;
    vector<vector<int>> res;
    void backtrace(vector<int> &candidates, int idx, int target) {
        if (tmpSum == target) {
            res.emplace_back(path);
            return;
        } else if (tmpSum > target) {
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            tmpSum += candidates[i];
            backtrace(candidates, i, target);
            tmpSum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int len = candidates.size();
        if (len == 0) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        tmpSum = 0;
        backtrace(candidates, 0, target);
        return res;
    }
};

int main() {
    vector<int> vec{2, 3, 6, 7};
    Solution s;
    auto res = s.combinationSum(vec, 7);
    return 0;
}