#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string encodedStr;  // 序列化后的字符串
    queue<string> q;    // 用来存储字符串分割的结果

    // serialize的辅助函数
    void serializeHelper(TreeNode *root) {
        if (root == NULL) {
            encodedStr += "#,";
            return;
        }
        encodedStr += to_string(root->val) + ",";
        serializeHelper(root->left);
        serializeHelper(root->right);
    }

    // deserialize的辅助函数
    TreeNode *deserializeHelper() {
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
        root->left = deserializeHelper();
        root->right = deserializeHelper();
        return root;
    }

    // 将serialize的结果转化成queue
    void strToList(string str) {
        string tmp;
        for (char c : str) {
            if (c == ',') {
                q.push(tmp);
                tmp.resize(0);
                continue;
            } else if (c >= '0' && c <= '9' || c == '-') {
                tmp.push_back(c);
            } else {
                tmp = "#";
            }
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        serializeHelper(root);
        return encodedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        strToList(data);
        return deserializeHelper();
    }
};

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
    cout << "#" << endl;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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
    Codec ser, deser;
    string encodedStr = ser.serialize(one);
    TreeNode *root = deser.deserialize(encodedStr);
    preorder(root);
    return 0;
}