#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        int len = s.size();
        if (len == 0)
            return -1;
        unordered_map<char, int> um;
        for (int i = 0; i < len; i++) {
            char cur = s[i];
            if (um.find(cur) == um.end()) {
                um[cur] = 1;
            } else {
                um[cur]++;
            }
        }
        for (int i = 0; i < len; i++) {
            if (um[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};