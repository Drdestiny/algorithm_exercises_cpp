#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        Node *tmp;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                tmp = q.front();
                q.pop();
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
                if (size > 0) {
                    tmp->next = q.front();
                }
            }
        }
        return root;
    }
};