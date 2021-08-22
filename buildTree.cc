#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Leetcode 105: 从前序与中序遍历序列构造二叉树
// 前序遍历为:[根节点][左子树][右子树]
// 中序遍历为:[左子树][根节点][右子树]
// 所以先确定根节点，再去左子树和右子树确定对应根节点
// 这也就是题目中强调“无重复元素”的原因，如果有重复元素且都两者在中序遍历结果中在一起，那没有办法确定哪个才是根节点

class Solution {
private:
    map<int, int> inIdx2Val;
    TreeNode *buildTree(vector<int> &preorder,
                        vector<int> &inorder,
                        int preLo,
                        int preHi,
                        int inLo,
                        int inHi) {
        // 时刻注意，这个函数只返回每个子树的根节点
        if (preLo > preHi) {
            return NULL;
        }
        int rootVal = preorder[preLo];
        TreeNode *root = new TreeNode(rootVal);
        int inRootIdx = inIdx2Val[rootVal];
        root->left = buildTree(preorder, inorder, preLo + 1,
                               preLo + inRootIdx - inLo, inLo, inRootIdx - 1);
        root->right = buildTree(preorder, inorder, preHi - inHi + inRootIdx + 1,
                                preHi, inRootIdx + 1, inHi);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int treeSize = preorder.size();
        for (int i = 0; i < inorder.size(); i++) {
            inIdx2Val[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, treeSize - 1, 0, treeSize - 1);
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    return 0;
}