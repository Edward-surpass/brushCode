/*********************************************************************************
*     File Name           :     54SpiralMatrix.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-27 20:06]
*     Last Modified       :     [2015-07-27 20:42]
*     Description         :     Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3  ],
  [ 4, 5, 6  ],
   [ 7, 8, 9  ]

]
You should return [1,2,3,6,9,8,7,4,5].
**********************************************************************************/

#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if(matrix.empty())
                return vector<int>();
            int lowRow = 0,lowCol = 0,upRow = matrix.size()-1,upCol = matrix[0].size()-1;
            vector<int> res;
            int x=0,y=0;
            while(lowRow<=upRow && lowCol<=upCol)
            {
                x = lowRow;
                y = lowCol;
                for ( y = lowCol; y <= upCol; ++y) {
                    res.push_back(matrix[x][y]);
                }
                --y;
                ++lowRow;
                if(lowRow > upRow)
                    break;
                for (x = lowRow;  x <= upRow; ++x) {
                    res.push_back(matrix[x][y]);
                }
                --x;
                --upCol;
                if(lowCol > upCol)
                    break;
                for ( y = upCol; y >= lowCol; --y) {
                    res.push_back(matrix[x][y]);
                }
                ++y;
                --upRow;
                if(lowRow > upRow)
                    break;
                for (x = upRow;  x >= lowRow; --x) {
                    res.push_back(matrix[x][y]);
                }
                ++lowCol;
                ++x;
                if(lowCol > upCol)
                    break;
            }
            return res;
        }
};
int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res;
    Solution so;
    res = so.spiralOrder(matrix);
    for(auto &e:res)
        cout << e << endl;
    return 0;
}
