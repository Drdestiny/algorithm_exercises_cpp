#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<bool> tracked;
    vector<int> path;
    void backtrack(vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // tracked[i-1] == false是从树层上去重
            // 而tracked[i-1] ==
            // true是从树枝上去重，也就是只允许有一个顺序：逆着原数组里的顺序的排列
            if (i > 0 && nums[i] == nums[i - 1] && !tracked[i - 1]) {
                continue;
            }
            if (!tracked[i]) {
                tracked[i] = true;
                path.push_back(nums[i]);
                backtrack(nums);
                path.pop_back();
                tracked[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0) {
            return res;
        }
        tracked = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return res;
    }
};