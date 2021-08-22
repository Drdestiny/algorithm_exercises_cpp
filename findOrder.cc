#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Leetcode 210: 课程表II
// dfs

class Solution {
    vector<int> visited;
    vector<vector<int>> inEdges;
    vector<int> result;
    bool valid = true;
    void dfs(int node) {
        visited[node] = 1;
        for (int i = 0; i < inEdges[node].size(); i++) {
            if (visited[i] == 0) {
                dfs(inEdges[node][i]);
            } else if (visited[i] == 1) {
                valid = false;
                return;
            }
        }
        visited[node] = 2;
        result.push_back(visited[node]);
    }

public:
    // prerequisites是由边缘列表表示的图形，而不是邻接矩阵
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        inEdges.resize(numCourses, vector<int>());
        visited.resize(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            inEdges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(i);
            }
            if (!valid) {
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};