/*********************************************************************************
*     File Name           :     55JumpGame.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-28 20:19]
*     Last Modified       :     [2015-07-28 20:32]
*     Description         :     iGiven an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.empty())
                return true;
            int maxrec=0+nums[0],currec=-1,i,len = nums.size();
            for (i = 0; i < len; ++i) {
                if(maxrec>=i)
                {
                    currec = i+nums[i];
                    if(currec > maxrec)
                        maxrec = currec;
                    if(maxrec >= len-1)
                        return true;
                }
            }
            return false;
        }
};

