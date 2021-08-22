#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode 455: 分发饼干

class Solution {
public:
    // g为小朋友胃口值，s为饼干尺寸
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gp = 0;        // g指针
        int sp = 0;        // s指针
        int children = 0;  // 最多满足的孩子
        while (gp < g.size() && sp < s.size()) {
            if (g[gp] <= s[sp]) {
                children++;
                gp++;
                sp++;
            } else {
                sp++;
            }
        }
        return children;
    }
};

int main() {
    Solution s;
    vector<int> g1{1, 2, 3};
    vector<int> s1{1, 1};
    vector<int> g2{1, 2};
    vector<int> s2{1, 2, 3};
    cout << s.findContentChildren(g1, s1) << endl;
    cout << s.findContentChildren(g2, s2) << endl;
    return 0;
}