/*********************************************************************************
*     File Name           :     64MinimumPathSum.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-30 13:55]
*     Last Modified       :     [2015-07-30 14:02]
*     Description         :     iGiven a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int sum,row = grid.size(),col = grid[0].size();
            int i,j;
            for (i = 1; i < row; ++i) {
                grid[i][0] += grid[i-1][0];
            }
            for (j = 1; j < col; ++j) {
                grid[0][j] += grid[0][j-1];
            }
            for (i = 1; i < row; ++i) {
                for (j = 1; j < col; ++j) {
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                }
            }
            return grid[row-1][col-1];
        }

};

