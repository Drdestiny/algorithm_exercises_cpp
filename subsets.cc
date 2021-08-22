#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtrace(vector<int> &nums, int subsetSize, int idx) {
        if (path.size() == subsetSize) {
            res.emplace_back(path);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrace(nums, subsetSize, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        for (int subsetSize = 0; subsetSize <= nums.size(); subsetSize++) {
            backtrace(nums, subsetSize, 0);
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution s;
    auto vec = s.subsets(nums);
    return 0;
}