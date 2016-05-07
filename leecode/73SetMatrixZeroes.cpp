/*********************************************************************************
*     File Name           :     a.cpp
*     Created By          :     edward *     Creation Date       :     [2016-04-01 21:12] *     Last Modified       :     [2016-04-05 14:02] *     Description         :      
**********************************************************************************/
#include <iostream>
#include <vector>
class Solution {
    public:
        void setZeroes(std::vector<std::vector<int>> &matrix){
            m = matrix.size();
            if(m > 0)
            {
                n = matrix[0].size();
            }
            else 
            {
                return;
            }
            bool rowZeros = false, colZeros = false;
            for (int i = 0; i < m; ++i) {
                if(matrix[i][0] == 0)
                {
                    colZeros = true;
                    break;
                }
            }
            for (int j = 0; j < n; ++j) {
                if(matrix[0][j] == 0)
                {
                    rowZeros = true;
                    break;
                }
            }
            for (int i = 1; i < m; ++i) {
                for (int j = 1;  j< n; ++j) {
                    if(matrix[i][j] == 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
            for (int i = 1; i < m; ++i) {
                if(matrix[i][0] == 0)
                {
                    setRow(matrix, i);
                }
            }
            for (int j = 1; j < n; ++j)
            {
                if(matrix[0][j] == 0)
                {
                    setCol(matrix, j);
                }
            }
            if(rowZeros)
                setRow(matrix, 0);
            if(colZeros)
                setCol(matrix, 0);
        }
        void setCol(std::vector<std::vector<int>> &matrix,int col)
        {
            for (int k = 0;  k < m; ++k) {
                matrix[k][col] = 0;
            }
        }
        void setRow(std::vector<std::vector<int>> &matrix,int row)
        {
            for (int k = 0;  k < n ; ++k) {
                matrix[row][k] = 0;
            }
        }
    private:
        int m;
        int n;
};
int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,0,6},{7,8,9}};
    Solution so;
    so.setZeroes(matrix);
    for(auto &temp : matrix)
    {
        for (auto &e: temp)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

