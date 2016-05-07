/*********************************************************************************
*     File Name           :     81SearchinRotatedSortedArrayII.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-18 16:52]
*     Last Modified       :     [2016-04-18 20:13]
*     Description         :      
**********************************************************************************/
#include <vector>
#include <iostream>

class Solution {
    public:
        bool search(std::vector<int>& nums, int target) {
            if (nums.empty())
                return -1;
            int mid = -1, i = 0;
            int j = nums.size() - 1;
            if (nums[i] >= nums[j] && nums.size() > 2)
            {
                while (i < j)
                {
                    mid = (i + j) / 2;
                    if ((nums[mid] < nums[mid-1] && nums[mid] <= nums[mid+1]) || (nums[mid] >= nums[mid-1] && nums[mid] > nums[mid+1]))
                    {
                        break;
                    }
                    else if (nums[mid-1] == nums[mid] && nums[mid] == nums[mid+1])
                    {
                        std::vector<int> nums1(nums.begin(), nums.begin() + mid);
                        std::vector<int> nums2(nums.begin() + mid, nums.end());
                        bool res = search(nums1, target);
                        if (!res )
                            res = search(nums2, target);
                        return res;
                    }
                    if(nums[mid] >= nums[i])
                    {
                        i = mid ;
                    }
                    else
                    {
                        j = mid  ;
                    }
                }
            }
            else if(nums.size() == 2)
            {
                if (nums[0] == target)
                    return true;
                else if (nums[1] == target)
                    return true;
                else
                    return false;
            }
            else
            {
                return b_search(nums, i, j, target);
            }
            std::cout << "mid:" << mid << std::endl;
            bool res;
            if ((nums[mid] < nums[mid-1] && nums[mid] <= nums[mid+1]))
            {
                res = b_search(nums, 0, mid-1, target);
                if (!res)
                {
                    res = b_search(nums, mid, nums.size()-1, target);
                }
            }
            else
            {
                res = b_search(nums, 0, mid, target);
                if (!res)
                {
                    res = b_search(nums, mid + 1, nums.size()-1, target);
                }
            }
            return res;
            
        }
        int b_search(std::vector<int> &nums, int i, int j, int target)
        {
            while( i <= j )
            {
                int mid = (i + j) / 2;
                std::cout << "b i:" << i << std::endl;
                std::cout << "b j:" << j << std::endl;
                std::cout << "b mid:" << mid << std::endl;
                if (nums[mid] == target)
                {
                    return true;
                }
                if(nums[mid] > target)
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            return false;
        }
};
int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,1,1};
    Solution so;
    std::cout << so.search(nums, 1) << std::endl;
    return 0;
}

