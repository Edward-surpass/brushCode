/*********************************************************************************
*     File Name           :     53MaximumSubarray.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-27 19:39]
*     Last Modified       :     [2015-07-27 20:04]
*     Description         :     iFind the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxnum=0,curnum=0,i,len = nums.size();
            for (i = 0; i < len; ++i) {
                if(i==0)
                    maxnum=nums[i];
                if(curnum < 0)
                {
                    curnum = 0;
                    curnum += nums[i];
                }
                else
                {
                    curnum+=nums[i];
                }
                if(maxnum < curnum)
                    maxnum = curnum;
            }
            return maxnum;
        }
};

