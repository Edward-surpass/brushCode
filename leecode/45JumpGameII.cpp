/*********************************************************************************
*     File Name           :     45JumpGameII.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-22 17:28]
*     Last Modified       :     [2015-07-22 20:14]
*     Description         :     Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            lastIndex = nums.size();
            int i,curRch,maxRch,ret;
            for (i = curRch = maxRch = ret = 0; i < lastIndex; ++i) {
                if(curRch < i)
                {
                    ++ret;
                    curRch = maxRch;
                }
                maxRch = maxRch>(i+nums[i])?maxRch:(i+nums[i]);
            }
            return ret;
        }
    private:
        int lastIndex;
};
int main(int argc, char *argv[])
{
    vector<int> nums = {2,3,1,1,4};
    Solution so;
    cout << so.jump(nums) << endl;
    return 0;
}
