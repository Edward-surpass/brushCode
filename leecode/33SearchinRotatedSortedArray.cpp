/*********************************************************************************
*     File Name           :     33SearchinRotatedSortedArray.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-18 14:23]
*     Last Modified       :     [2015-07-18 15:29]
*     Description         :      
topic:Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if(nums.empty())
                return -1;
            int len = nums.size();
            if(nums[0] <= nums[len-1])
                return b_search(nums,0,len,target);
            int mid = len/2;
            if(nums[mid] == target)
                return mid;
            if(target <= nums[len-1])
            {
                if(target>nums[mid])
                    return b_search(nums,mid,len,target);
                else
                {
                    if(nums[mid] < nums[len-1])
                    {
                        vector<int> temp(nums.begin(),nums.begin()+mid);
                        return search(temp,target);
                    }
                    else
                    {
                        vector<int> temp(nums.begin()+mid+1,nums.end());
                        int res = search(temp ,target);
                        return res == -1?res:res+mid+1;
                    }
                }
            }
            else{
                if(target < nums[mid])
                    return b_search(nums,0,mid,target);
                else
                {
                    if(nums[mid] > nums[0])
                    {
                        vector<int> temp(nums.begin()+mid+1,nums.end());
                        int res = search(temp ,target);
                        return res == -1?res:res+mid+1;
                    }
                    else
                    {
                        vector<int> temp(nums.begin(),nums.begin()+mid);
                        return search(temp,target);
                    }
                }
            }
                
        }
        int b_search(vector<int> &nums,int b,int e,int target)
        {
            if(b == e)
                return -1;
            int mid = b + (e-b)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                return b_search(nums,b,mid,target);
            else
                return b_search(nums,mid+1,e,target);
        }

};
int main(int argc, char *argv[])
{
    vector<int> nums = {3,1};
    Solution so;
    cout << so.search(nums,0) << endl;
    return 0;
}
