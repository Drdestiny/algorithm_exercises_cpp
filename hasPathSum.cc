#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Leetcode 112: 路径总和

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    root->left = left;
    Solution s;
    cout << s.hasPathSum(root, 1) << endl;
    return 0;
}