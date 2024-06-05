#include <bits/stdc++.h>

using namespace std;

// Striver Video Link
// https://www.youtube.com/watch?v=80Zug6D1_r4

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    return root;
}

// space O(1)
vector<int> inorderMorris(TreeNode *root) {
    TreeNode *node = root;
    vector<int> inorderTraversal;
    while (node != nullptr) {
        if (node->left == nullptr) {
            inorderTraversal.push_back(node->val);
            node = node->right;
        } else {
            TreeNode *prev = node->left;
            while (prev->right != nullptr && prev->right != node) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = node;
                node = node->left;
            } else {
                prev->right = nullptr;
                inorderTraversal.push_back(node->val);
                node = node->right;
            }
        }
    }
    return inorderTraversal;
}

// space O(n)
vector<int> inorderRecursive(TreeNode *root) {
    vector<int> inorderTraversal;
    function<void(TreeNode *)> helper = [&](TreeNode *root) {
        if (root != nullptr) {
            helper(root->left);
            inorderTraversal.push_back(root->val);
            helper(root->right);
        }
    };
    helper(root);
    return inorderTraversal;
}

// space O(1)
vector<int> preorderMorris(TreeNode *root) {
    TreeNode *node = root;
    vector<int> preorderTraversal;
    while (node != nullptr) {
        if (node->left == nullptr) {
            preorderTraversal.push_back(node->val);
            node = node->right;
        } else {
            TreeNode *prev = node->left;
            while (prev->right != nullptr && prev->right != node) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = node;
                preorderTraversal.push_back(node->val);
                node = node->left;
            } else {
                prev->right = nullptr;
                node = node->right;
            }
        }
    }
    return preorderTraversal;
}

// space O(n)
vector<int> preorderRecursive(TreeNode *root) {
    vector<int> preorderTraversal;
    function<void(TreeNode *)> helper = [&](TreeNode *root) {
        if (root != nullptr) {
            preorderTraversal.push_back(root->val);
            helper(root->left);
            helper(root->right);
        }
    };
    helper(root);
    return preorderTraversal;
}

int main() {
    auto root = createTree();
    auto res1 = inorderRecursive(root);
    cout << "inorderRecursive" << endl;
    for (auto v : res1) {
        cout << v << " ";
    }
    cout << endl;
    auto res2 = inorderMorris(root);
    cout << "inorderMorris" << endl;
    for (auto v : res2) {
        cout << v << " ";
    }
    cout << endl;
    auto res3 = preorderRecursive(root);
    cout << "preorderRecursive" << endl;
    for (auto v : res3) {
        cout << v << " ";
    }
    cout << endl;
    auto res4 = preorderMorris(root);
    cout << "preorderMorris" << endl;
    for (auto v : res4) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}