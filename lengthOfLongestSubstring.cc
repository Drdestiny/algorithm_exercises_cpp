#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Leetcode 3: 无重复字符的最长子串
// 左边起点依次遍历，设 以begin为起点的最长无重复子串的终点 为end,
// 那么begin+1到end必然是无重复子串，然后再从end+1开始找

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        if (strLen == 0)
            return 0;
        unordered_set<int> us;
        int maxLen = 0;
        int cur = 0;
        for (int begin = 0; begin < strLen; begin++) {
            // 只要begin不为0，那么就先删掉前一个begin的项，然后继续往后找
            if (begin != 0) {
                us.erase(s[begin - 1]);
            }
            // cur在每一轮的开始要到上一轮最长子串的末尾后一个位置
            while (cur < strLen && !us.count(s[cur])) {
                us.insert(s[cur]);
                cur++;
            }
            maxLen = cur - begin > maxLen ? cur - begin : maxLen;
            if (cur == strLen)
                return maxLen;
        }
        return maxLen;
    }
};

int main() {
    string s1("abcabcbb");
    Solution s;
    cout << s.lengthOfLongestSubstring(s1) << endl;
    return 0;
}