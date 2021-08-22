#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(NULL), right(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void *BFS(Node *root) {
        if (root == NULL) {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        Node *tmp;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                tmp = q.front();
                q.pop();
                cout << tmp->val << " ";
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    Node *seven = new Node(7);
    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    three->left = six;
    three->right = seven;
    s.BFS(one);
    return 0;
}