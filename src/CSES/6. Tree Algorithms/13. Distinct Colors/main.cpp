#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int maxN = 2e5 + 5;
vector<int> adj[maxN];               // Adjacency list to represent the tree
int colors[maxN];                    // Colors of the nodes
int result[maxN];                    // To store the number of distinct colors in the subtree
unordered_set<int>* colorSet[maxN];  // Array of pointers to sets storing colors for each node

void dfs(int node, int parent) {
    colorSet[node] = new unordered_set<int>();
    colorSet[node]->insert(colors[node]);

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            // POINT: this optimization is crucial and the main idea of the problem
            if (colorSet[child]->size() > colorSet[node]->size()) {
                swap(colorSet[child], colorSet[node]);
            }
            colorSet[node]->insert(colorSet[child]->begin(), colorSet[child]->end());
        }
    }

    result[node] = colorSet[node]->size();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Start DFS from the root node (1)
    dfs(1, -1);

    // Output the result for each node
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
