#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Leetcode 228: 汇总区间
// 这个写法不用处理nums为空的情况，关键在于第一个while循环的条件

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> area;
        int len = nums.size();
        int i = 0;
        int start = 0;
        while (i < len) {
            start = i;
            i++;
            while (i < len && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            string tmp = to_string(nums[start]);
            if (i - start > 1) {
                tmp.append("->" + to_string(nums[i - 1]));
            }
            area.emplace_back(tmp);
        }
        return area;
    }
};