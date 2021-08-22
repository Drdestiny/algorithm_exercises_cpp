#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 后序遍历的迭代写法

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    stack<TreeNode *> stk;

public:
    // 后序遍历需要分清楚两种情况：下一个应该遍历该节点的根节点还是右兄弟节点
    void backorder(TreeNode *root) {
        TreeNode *lastNode = nullptr;
        TreeNode *curNode = root;
        while (curNode != nullptr || !stk.empty()) {
            while (curNode) {
                stk.push(curNode);
                curNode = curNode->left;
            }
            curNode = stk.top();
            // 当前节点没有右子节点，或者右子节点已经遍历过，才可以到当前节点
            if (curNode->right == nullptr || lastNode == curNode->right) {
                cout << curNode->val << endl;
                stk.pop();
                lastNode = curNode;
                // 当前节点有右子节点，先遍历右子节点
            } else {
                curNode = curNode->right;
            }
        }
    }
};