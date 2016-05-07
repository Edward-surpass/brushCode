/*********************************************************************************
*     File Name           :     75SortColors.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-09 17:32]
*     Last Modified       :     [2016-04-09 21:10]
*     Description         :      
**********************************************************************************/

#include <vector>

class Solution {
    public:
        void sortColors(std::vector<int>& nums) {
            int i = 0;
            int j = nums.size()-1;
            while (i <= j)
            {
                while(i <= j && nums[i] == 0) ++i;
                while(i <= j && nums[j] != 0) --j;
                if(i < j)
                    std::swap(nums[i++], nums[j--]);
            }
            j = nums.size()-1;
            while(i <= j)
            {
                while(i <= j && nums[i] == 1) ++i;
                while(i <= j && nums[j] != 1) --j;
                if(i < j)
                    std::swap(nums[i++], nums[j--]);
            }
        }
};
