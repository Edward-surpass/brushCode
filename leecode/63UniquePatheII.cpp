/*********************************************************************************
*     File Name           :     63UniquePatheII.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-30 13:28]
*     Last Modified       :     [2015-07-30 13:51]
*     Description         :     Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
    [0,1,0],
      [0,0,0]

]
The total number of unique paths is 2.

Note: m and n will be at most 100.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int row = obstacleGrid.size(),col = obstacleGrid[0].size();
            vector<vector<int>> dp(row,vector<int>(col,0));
            int i,j;
            for (i = 0; i < row; ++i) {
                if(obstacleGrid[i][0] != 1)
                    dp[i][0]=1;
                else
                    break;
            }
            for (j = 0; j < col; ++j) {
                if(obstacleGrid[0][j] != 1)
                    dp[0][j]=1;
                else
                    break;
            }

            for (i = 1; i < row; ++i) {
                for (j = 1; j < col; ++j) {
                    if(obstacleGrid[i][j]!=1)
                    {
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                    else
                        dp[i][j]=0;
                }
            }
            return dp[row-1][col-1];
        }
};

