#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Leetcode 49: 字母异位词分组
// 对每一个词进行排序，然后放到unordered_map中

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int strsNum = strs.size();
        vector<vector<string>> ans;
        if (strsNum == 0)
            return ans;
        unordered_map<string, vector<string>> us;
        string tmp;
        for (int i = 0; i < strsNum; i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            us[tmp].emplace_back(strs[i]);
        }
        for (auto iter = us.begin(); iter != us.end(); iter++) {
            ans.emplace_back(iter->second);
        }
        return ans;
    }
};