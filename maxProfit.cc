#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode 123: 买卖股票的最佳时机III（只能买卖两次）
// 三维dp，第1维天数，第2维持有股票与否（0没有1有），第3维剩余卖的次数(2,1,0)，选择是卖或不卖

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<vector<int>>> dp(
            len, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = 0; i < 3; i++) {
            dp[0][1][i] = -prices[0];
        }
        for (int day = 1; day < len; day++) {
            // 当天手上没有股票时
            for (int exchTimes = 0; exchTimes < 2; exchTimes++) {
                dp[day][0][exchTimes] =
                    max(dp[day - 1][1][exchTimes + 1] + prices[day],
                        dp[day - 1][0][exchTimes]);
                dp[day][1][exchTimes] =
                    max(dp[day - 1][0][exchTimes] - prices[day],
                        dp[day - 1][1][exchTimes]);
            }
            dp[day][1][2] =
                max(dp[day - 1][0][2] - prices[day], dp[day - 1][1][2]);
            dp[day][0][2] = dp[day - 1][0][2];
        }
        int maxMoney = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                maxMoney =
                    maxMoney > dp[len - 1][i][j] ? maxMoney : dp[len - 1][i][j];
            }
        }
        return maxMoney;
    }
};