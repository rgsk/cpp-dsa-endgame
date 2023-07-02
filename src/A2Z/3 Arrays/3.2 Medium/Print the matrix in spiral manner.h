
#include <bits/stdc++.h>

#include "../../utils/utils.h"
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;
        int startRow = 0, endRow = rows - 1;
        int startCol = 0, endCol = cols - 1;
        int dir = 0;

        while (startRow <= endRow && startCol <= endCol) {
            switch (dir) {
                case 0:  // RIGHT
                    for (int col = startCol; col <= endCol; col++)
                        result.push_back(matrix[startRow][col]);
                    startRow++;
                    break;
                case 1:  // DOWN
                    for (int row = startRow; row <= endRow; row++)
                        result.push_back(matrix[row][endCol]);
                    endCol--;
                    break;
                case 2:  // LEFT
                    for (int col = endCol; col >= startCol; col--)
                        result.push_back(matrix[endRow][col]);
                    endRow--;
                    break;
                case 3:  // UP
                    for (int row = endRow; row >= startRow; row--)
                        result.push_back(matrix[row][startCol]);
                    startCol++;
                    break;
            }
            dir = (dir + 1) % 4;
        }

        return result;
    }
};