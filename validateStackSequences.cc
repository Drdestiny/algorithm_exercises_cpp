#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int stackSize = pushed.size();
        if (stackSize == 0)
            return true;
        int popIdx = 0;
        stack<int> aux;
        for (int i = 0; i < pushed.size(); i++) {
            if (pushed[i] != popped[popIdx]) {
                aux.push(pushed[i]);
            } else {
                popIdx++;
                while (!aux.empty() && popped[popIdx] == aux.top()) {
                    popIdx++;
                    aux.pop();
                }
            }
        }
        return popIdx == stackSize;
    }
};

int main() {
    Solution s;
    vector<int> pushed1 = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    vector<int> pushed2 = {1, 2, 3, 4, 5};
    vector<int> popped2 = {4, 3, 5, 1, 2};
    cout << s.validateStackSequences(pushed1, popped1) << endl;
    cout << s.validateStackSequences(pushed2, popped2) << endl;
    return 0;
}