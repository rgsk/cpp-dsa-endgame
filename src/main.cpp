#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> findMode(TreeNode *root) {
        inorder(root);
        modes.resize(modeCount);
        modeCount = 0;
        currCount = 0;
        inorder(root);
        return modes;
    }

   private:
    int currVal = INT_MIN;
    int currCount = 0;
    int maxCount = 0;
    int modeCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        currCount++;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        } else if (currCount == maxCount) {
            if (!modes.empty())
                modes[modeCount] = currVal;
            modeCount++;
        }
    }

    void inorder(TreeNode *root) {
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->left == nullptr) {
                handleValue(node->val);
                node = node->right;
            } else {
                TreeNode *prev = node->left;
                while (prev->right != nullptr && prev->right != node)
                    prev = prev->right;
                if (prev->right == nullptr) {
                    prev->right = node;
                    node = node->left;
                } else {
                    prev->right = nullptr;
                    handleValue(node->val);
                    node = node->right;
                }
            }
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}