// 剑指offer 8：二叉树的下一个节点
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *findNextNodeinBinaryTree(TreeNode *node) {
    TreeNode *travNode;
    // 该节点有右子树，直接找到右子树的最左节点
    if ((travNode = node->right) != NULL) {
        while (travNode->left != NULL) {
            travNode = travNode->left;
        }
        return travNode;
        // 该节点没有右子树
    } else {
        // 该节点没有父节点，直接返回NULL
        if (node->parent == NULL) {
            return NULL;
            // 该节点有父节点，且该节点为左子节点，返回父节点
        } else if (node == node->parent->left) {
            return node->parent;
            // 该节点有父节点，且该节点为右子节点，就要一直向上追溯到一个最近的，满足“该祖先节点是某个节点的左子节点”的条件的祖先节点
        } else if (node == node->parent->right) {
            travNode = node->parent;
            while ((travNode = travNode->parent) != NULL) {
                if (travNode == travNode->parent->left) {
                    return travNode;
                }
            }
        }
    }
    return NULL;
}