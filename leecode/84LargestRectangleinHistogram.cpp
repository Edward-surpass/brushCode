/*********************************************************************************
*     File Name           :     84LargestRectangleinHistogram.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-18 21:08]
*     Last Modified       :     [2016-04-20 18:57]
*     Description         :      
**********************************************************************************/
#include <vector>
class Solution {
    public:
        int largestRectangleArea(std::vector<int>& heights) {
            return my_fun(heights, 0, heights.size()-1);
        }
        int my_fun(std::vector<int>& heights, int i, int j)
        {
            if( i > j )
                return 0;
            int min_val = i;
            for (int k =i; k <= j; ++k)
            {
                if (heights[k] < heights[min_val])
                    min_val = k;
            }
            int this_val = (j-i+1) * heights[min_val];
            int lfs_max = my_fun(heights, i, min_val-1);
            int rfs_max = my_fun(heights, min_val + 1, j);
            if(this_val < lfs_max)
                this_val = lfs_max;
            return this_val > rfs_max ? this_val : rfs_max;
        }

};
