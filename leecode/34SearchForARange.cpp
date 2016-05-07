/*********************************************************************************
*     File Name           :     34SearchForARange.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 10:24]
*     Last Modified       :     [2015-07-19 10:45]
*     Description         :      
topic:Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int len = nums.size(),i=0,j=len,lop,upp;
            int mid;
            while(i<j)
            {
                mid = i + (j-i)/2;
                if(nums[mid] == target)
                {
                    lop = upp = mid;
                    j=1;
                    while((mid-j)>=0 && nums[mid-j]==target)
                        lop = mid-j++;
                    while((mid+j)<len && nums[mid+j]==target)
                        upp = mid+j++;
                    return {lop,upp};
                }
                else if(nums[mid]>target)
                {
                    j=mid;
                }
                else
                    i=mid+1;
            }
            return {-1,-1};
        }
};
int main(int argc, char *argv[])
{
    vector<int> nums = {3,3,3};
    Solution so;
    so.searchRange(nums,1);
    return 0;
}
