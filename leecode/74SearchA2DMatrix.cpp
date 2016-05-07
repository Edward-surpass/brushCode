/*********************************************************************************
*     File Name           :     74SearchA2DMatrix.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-05 21:49]
*     Last Modified       :     [2016-04-09 17:31]
*     Description         :      
**********************************************************************************/
#include <iostream>
#include <vector>
class Solution{
    public:
        bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
        {
            int i;
            if(matrix.empty())
                return false;
            if(matrix[0].empty())
                return false;
            if(matrix[0][0] > target )
                return false;
            auto p = matrix.end();
            auto q = (--p)->end();
            if(*(--q) < target)
                return false;
            for(i = 0; i+1 < matrix.size(); ++i)
            {
                if(matrix[i+1][0] > target)
                    break;
            }
            std::vector<int> &veci = matrix[i];
            return search_tar(veci, 0, veci.size(), target);
        }
        bool search_tar(std::vector<int> &veci, int i, int j, int tar)
        {
            if(i == j) return false;
            int mid = (i+j)/2;
            if(veci[mid] == tar)
                return true;
            if(veci[mid] > tar)
                return search_tar(veci,i,mid,tar);
            if(veci[mid] < tar)
                return search_tar(veci, mid+1, j, tar);
        }
};

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> matrix{{1}};
    Solution so;
    std::cout << so.searchMatrix(matrix,1) << std::endl;
    return 0;
}
