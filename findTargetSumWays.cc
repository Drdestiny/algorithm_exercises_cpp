#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode 494: 目标和
// 动态规划(背包问题)

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int len = nums.size();
        // nums的数组和不超过1000
        if (len == 0 || S > 1000 || S < -1000) {
            return 0;
        }
        // 第1维对应数字，第2维对应当前的和，值对应当前状态的最多方法数
        // 因为和最小可能是-1000，最大可能是1000，所以第2维长度为2001
        // 为了避免负的index，第2维在运算时要加1000
        vector<vector<int>> dp(len, vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        // 这里的+=非常重要！！！因为nums[0]可能是0
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < len; i++) {
            for (int j = -1000; j < 1000; j++) {
                // 为了防止第2维超出边界，也为了减少计算次数，加一个判断条件
                if (dp[i - 1][j + 1000] > 0) {
                    dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000];
                    dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000];
                }
            }
        }
        return dp[len - 1][S + 1000];
    }
};

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    Solution s;
    cout << s.findTargetSumWays(nums, 3) << endl;
    return 0;
}