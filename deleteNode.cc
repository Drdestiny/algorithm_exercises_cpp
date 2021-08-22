#include <iostream>
#include <stack>
#include <vector>

using namespace std;
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
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        // 向左找
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            // 向右找
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            // 找到了
        } else {
            TreeNode *rootChildTmp =
                nullptr;  // 用来存储root的子节点，方便delete待删除节点
            // 没有左子节点，把右子节点接上
            if (root->left == nullptr) {
                rootChildTmp = root->right;
                delete root;
                root = nullptr;
                return rootChildTmp;
            }
            // 没有右子节点，把左子节点接上
            if (root->right == nullptr) {
                rootChildTmp = root->left;
                delete root;
                root = nullptr;
                return rootChildTmp;
            }
            // 左右都有子节点，把左子树的最大节点，即最右子节点替换上（或者右子树的最小节点，即最左子节点）
            TreeNode *trav = root->left;
            TreeNode *parent = root;
            bool isRight =
                false;  // 判断最终找到的节点究竟是其父节点的左子节点还是右子节点
            while (trav->right != nullptr) {
                isRight = true;
                parent = trav;
                trav = trav->right;
            }
            // 把替换节点原本的位置替换成nullptr，把待删除节点的左右子树分别接到替换节点上
            if (isRight) {
                parent->right = nullptr;
                trav->left = root->left;
            }
            trav->right = root->right;
            // 把待删除节点处理掉
            delete root;
            root = nullptr;
            return trav;
        }
        return root;
    }
};