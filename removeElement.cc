#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int rmvNum = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) {
                rmvNum++;
                continue;
            } else {
                if (rmvNum) {
                    nums[i - rmvNum] = nums[i];
                }
            }
        }
        return len - rmvNum;
    }
};