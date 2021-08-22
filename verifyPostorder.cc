#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 验证从start到end的序列是不是一颗二叉搜索树
    bool verifyPostorder(vector<int> &postorder, int start, int end) {
        if (start == end) {
            return true;
        }
        int rootVal = postorder[end];
        int rightStart = end;
        for (int i = start; i < end; i++) {
            int curVal = postorder[i];
            if (curVal > rootVal) {
                rightStart = i;
                break;
            }
        }
        for (int i = rightStart + 1; i < end; i++) {
            if (postorder[i] < rootVal) {
                return false;
            }
        }
        // 如果只有左子树或者右子树，只需要一个函数
        if (rightStart == start || rightStart == end) {
            return verifyPostorder(postorder, start, end - 1);
            // 否则就需要两个函数，分别检测左子树和右子树
        } else {
            return verifyPostorder(postorder, start, rightStart - 1) &&
                   verifyPostorder(postorder, rightStart, end - 1);
        }
    }

public:
    bool verifyPostorder(vector<int> &postorder) {
        int len = postorder.size();
        if (len == 0) {
            return true;
        }
        return verifyPostorder(postorder, 0, len - 1);
    }
};

int main() {
    vector<int> postorder1{1, 6, 3, 2, 5};
    Solution s;
    cout << s.verifyPostorder(postorder1) << endl;
    return 0;
}