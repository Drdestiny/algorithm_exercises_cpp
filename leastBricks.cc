#include <iostream>
#include <vector>

using namespace std;

// Leetcode 554: 砖墙

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        int height = wall.size();
        int width = 0;
        for (int i = 0; i < wall[0].size(); i++) {
            width += wall[0][i];
        }
        vector<int> pos(height, 0);
        vector<int> left;
        for (int i = 0; i < height; i++) {
            left.emplace_back(wall[i][0]);
        }
        int minCnt = INT32_MAX;
        for (int ptr = 1; ptr < width - 1; ptr++) {
            int cntTmp = height;
            for (int i = 0; i < height; i++) {
                left[i]--;
                if (left[i] == 0) {
                    cntTmp--;
                    left[i] = wall[i][++pos[i]];
                }
            }
            minCnt = cntTmp < minCnt ? cntTmp : minCnt;
        }
        return minCnt;
    }
};

int main() {
    vector<vector<int>> bricks = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                                  {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};
    Solution s;
    cout << s.leastBricks(bricks) << endl;
    return 0;
}