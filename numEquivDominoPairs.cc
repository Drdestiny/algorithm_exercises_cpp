#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Leetcode

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        int len = dominoes.size();
        if (len == 0) {
            return 0;
        }
        for (int i = 0; i < len; i++) {
            sort(dominoes[i].begin(), dominoes[i].end());
        }
        sort(dominoes.begin(), dominoes.end());
        map<vector<int>, int> recordMap;
        for (auto domino : dominoes) {
            if (recordMap.count(domino) == 0) {
                recordMap[domino] = 1;
            } else {
                recordMap[domino]++;
            }
        }
        int numEquivPairs = 0;
        for (auto iter = recordMap.begin(); iter != recordMap.end(); iter++) {
            numEquivPairs += iter->second * (iter->second - 1) / 2;
        }
        return numEquivPairs;
    }
};