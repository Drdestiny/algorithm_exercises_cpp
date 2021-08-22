#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int len = nums.size();
        if (len == 0)
            return INT32_MIN;
        int second, third, sum, sumTmp, dfrAbsTmp;
        int dfrAbs = INT32_MAX;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < len - 2; first++) {
            second = first + 1;
            third = len - 1;
            while (second < third) {
                sumTmp = nums[first] + nums[second] + nums[third];
                dfrAbsTmp = abs(sumTmp - target);
                if (dfrAbsTmp == 0)
                    return target;
                if (sumTmp > target) {
                    third--;
                } else {
                    second++;
                }
                if (dfrAbsTmp < dfrAbs) {
                    sum = sumTmp;
                    dfrAbs = dfrAbsTmp;
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums1{-1, 2, 1, -4};
    vector<int> nums2{1, 2, 4, 8, 16, 32, 64, 128};
    Solution s;
    cout << s.threeSumClosest(nums1, 1) << endl;
    cout << s.threeSumClosest(nums2, 82) << endl;
    return 0;
}