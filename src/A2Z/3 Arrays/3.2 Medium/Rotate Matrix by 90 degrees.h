#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols / 2; j++) {
                swap(matrix[i][j], matrix[i][cols - j - 1]);
            }
        }
    }
};