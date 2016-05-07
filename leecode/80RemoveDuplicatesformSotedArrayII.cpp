/*********************************************************************************
*     File Name           :     80RemoveDuplicatesformSotedArrayII.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-18 16:39]
*     Last Modified       :     [2016-04-18 16:51]
*     Description         :      
**********************************************************************************/
#include <vector>
class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            if (nums.empty())
                return 0;
            int temp_val = *nums.begin();
            int dupli = 1;
            int j = 1;
            int res = 1;
            for (int i = 1 ; i < nums.size(); ++i)
            {
                while (i < nums.size() && temp_val == nums[i])
                {
                    if(dupli == 2)
                    {
                        ++i;
                        continue;
                    }
                    else
                    {
                        nums[j] = nums[i];
                        ++dupli;
                        ++res;
                        ++i;
                        ++j;
                        continue;
                    }
                }
                if ( i < nums.size() )
                {
                    nums[j++] = nums[i];
                    temp_val = nums[i];
                    ++res;
                    dupli = 1;
                }
            }
            return res;
        }
};

