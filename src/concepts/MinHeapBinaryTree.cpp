#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class MinHeapBinaryTree {
   private:
    TreeNode* root;

    // Function to heapify up to maintain min-heap property
    void heapifyUp(TreeNode* node) {
        if (node == nullptr) return;
        TreeNode* parent = findParent(node);
        if (parent && parent->val > node->val) {
            std::swap(parent->val, node->val);
            heapifyUp(parent);
        }
    }

    // Helper function to find the parent node of a newly inserted node
    TreeNode* findParent(TreeNode* node) {
        // Return the parent of the node by tracking its position
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left == node || curr->right == node) return curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return nullptr;
    }

    // Function to heapify down after extracting the root
    void heapifyDown(TreeNode* node) {
        if (node == nullptr) return;

        TreeNode* smallest = node;
        if (node->left && node->left->val < smallest->val)
            smallest = node->left;
        if (node->right && node->right->val < smallest->val)
            smallest = node->right;

        if (smallest != node) {
            std::swap(smallest->val, node->val);
            heapifyDown(smallest);
        }
    }

    // Find last node using level order traversal
    TreeNode* findLastNode() {
        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* last = nullptr;
        while (!q.empty()) {
            last = q.front();
            q.pop();

            if (last->left) q.push(last->left);
            if (last->right) q.push(last->right);
        }

        return last;
    }

    // Remove last node in level order (used after swapping with root)
    void removeLastNode(TreeNode* last) {
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left == last) {
                curr->left = nullptr;
                delete last;
                return;
            } else if (curr->right == last) {
                curr->right = nullptr;
                delete last;
                return;
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

   public:
    MinHeapBinaryTree() : root(nullptr) {}

    // Insert a new element in the min-heap-like binary tree
    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);

        if (!root) {
            root = newNode;
        } else {
            std::queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                if (!curr->left) {
                    curr->left = newNode;
                    heapifyUp(newNode);
                    break;
                } else if (!curr->right) {
                    curr->right = newNode;
                    heapifyUp(newNode);
                    break;
                } else {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
    }

    // Extract the minimum element (root) from the binary tree
    int extractMin() {
        if (!root) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1;
        }

        int minVal = root->val;

        TreeNode* last = findLastNode();
        if (root != last) {
            root->val = last->val;
            removeLastNode(last);
            heapifyDown(root);
        } else {
            delete root;
            root = nullptr;
        }

        return minVal;
    }

    // Print the tree using level order traversal
    void printTree() {
        if (!root) {
            std::cout << "Tree is empty" << std::endl;
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            std::cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeapBinaryTree heap;

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);
    heap.insert(0);

    std::cout << "Binary Tree Min Heap: ";
    heap.printTree();

    for (int i = 0; i < 5; i++) {
        std::cout << "Extracted Min: " << heap.extractMin() << std::endl;

        std::cout << "Tree after extracting min: ";
        heap.printTree();
    }
    return 0;
}
