#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> preorder, inorder, postorder;
unordered_map<int, int> inorder_index;

void findPostorder(int preStart, int inStart, int inEnd) {
    if (inStart > inEnd) return;

    int root = preorder[preStart];
    int rootIndex = inorder_index[root];

    // Recursively find postorder of the left subtree
    findPostorder(preStart + 1, inStart, rootIndex - 1);

    // Recursively find postorder of the right subtree
    findPostorder(preStart + (rootIndex - inStart) + 1, rootIndex + 1, inEnd);

    // Add root to postorder traversal
    postorder.push_back(root);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    preorder.resize(n);
    inorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorder_index[inorder[i]] = i;  // Store the index of each element in inorder traversal
    }

    findPostorder(0, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << postorder[i] << " ";
    }
    cout << endl;

    return 0;
}