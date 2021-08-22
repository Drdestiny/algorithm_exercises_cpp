#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Leetcode 98: 验证二叉搜索树

class Solution {
    bool isValidBST(TreeNode *root, int lowerBound, int upperBound) {
        if (root == NULL) {
            return true;
        }
        if (root->val > lowerBound && root->val < upperBound) {
            return isValidBST(root->left, lowerBound, root->val) &&
                   isValidBST(root->right, root->val, upperBound);
        }
        return false;
    }

public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT32_MIN, INT32_MAX);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(6);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution s;
    cout << s.isValidBST(node1) << endl;
    return 0;
    //[5,4,6,null,null,3,7]
}