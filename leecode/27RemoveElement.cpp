/*********************************************************************************
*     File Name           :     26RemoveElement.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 22:04]
*     Last Modified       :     [2015-07-11 22:10]
*     Description         :      
topic:Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            size_t i,j;
            for (i = 0,j=0; j < nums.size(); ++j) {
                if(nums[j] != val)
                    nums[i++] = nums[j];
            }
            return i;
                
        }

};
