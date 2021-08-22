#include <iostream>
#include <vector>

using namespace std;

// Leetcode 135: 分发糖果

class Solution {
private:
    vector<int> candies;

public:
    // 贪心，两遍遍历，一遍顺序（左规则）一遍逆序（右规则），最后合并结果
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return 1;
        vector<int> res;
        res.resize(len, 1);
        // 左遍历
        for (int i = 1; i < len; i++) {
            // 左规则
            if (ratings[i] > ratings[i - 1]) {
                res[i] = res[i - 1] + 1;
            } else {
                res[i] = 1;
            }
        }
        res[len - 1] = res[len - 1] > 1 ? res[len - 1] : 1;
        // 右遍历
        int rightTmp = 0;
        for (int i = len - 2; i >= 0; i--) {
            // 右规则，不需要再为逆序遍历创建另一个数组了，用一个值存储当前值，再比较即可
            if (ratings[i] > ratings[i + 1]) {
                rightTmp = res[i + 1] + 1;
            } else {
                rightTmp = 1;
            }
            res[i] = res[i] > rightTmp ? res[i] : rightTmp;
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += res[i];
        }
        return sum;
    }
};

int main() {
    vector<int> r1{1, 0, 2};
    vector<int> r2{1, 2, 2};
    vector<int> r3{1, 3, 2, 2, 1};
    Solution s;
    cout << s.candy(r1) << endl;
    cout << s.candy(r2) << endl;
    cout << s.candy(r3) << endl;
    return 0;
}