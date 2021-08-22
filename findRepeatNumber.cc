#include <iostream>
#include <vector>

using namespace std;

// 剑指Offer03

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout << s.findRepeatNumber(nums) << endl;
    return 0;
}