#include <iostream>
#include <vector>

using namespace std;

// Leetcode 189: 旋转数组

class Solution {
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

public:
    void rotate(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len;
        if (k == 0)
            return;
        int start = -1;
        int count = 0;
        int cur, next;
        while (count < len) {
            start++;
            count++;
            cur = (start + k) % len;
            while (cur != start) {
                swap(nums, start, cur);
                cur = (cur + k) % len;
                count++;
            }
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 3);
    return 0;
}