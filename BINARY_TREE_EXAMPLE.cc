#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<string> lst;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

queue<string> strToList(string str) {
    string tmp;
    queue<string> q;
    for (char c : str) {
        if (c == ',') {
            q.push(tmp);
            tmp.resize(0);
            continue;
        } else if (c >= '0' && c <= '9') {
            tmp.push_back(c);
        } else {
            tmp = "#";
        }
    }
    return q;
}

void preorder(TreeNode *root) {
    if (root == NULL) {
        cout << "#" << endl;
        return;
    }
    stack<TreeNode *> stk;
    while (!stk.empty() || root != NULL) {
        while (root != NULL) {
            cout << root->val << ",";
            stk.push(root);
            root = root->left;
        }
        cout << "#,";
        if (!stk.empty()) {
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }
    cout << endl;
}

TreeNode *deserialize(queue<string> q) {
    if (q.empty()) {
        return NULL;
    }
    string rootVal = q.front();
    q.pop();
    if (rootVal == "#") {
        return NULL;
    }
    TreeNode *root = new TreeNode(stoi(rootVal));
    root->val = stoi(rootVal);
    root->left = deserialize(q);
    root->right = deserialize(q);
    return root;
}

int main() {
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    one->left = two;
    one->right = three;
    three->left = four;
    three->right = five;
    string exp = "1,2,#,#,3,4,#,#,5,#,#,";
    queue<string> q = strToList(exp);
    TreeNode *root = deserialize(q);
    preorder(root);
    return 0;
}