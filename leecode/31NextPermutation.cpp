/*********************************************************************************
*     File Name           :     31NextPermutation.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-17 19:46]
*     Last Modified       :     [2015-07-17 21:33]
*     Description         :      
topic:Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
**********************************************************************************/
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if(nums.empty())
                return;
            size_t i,j,len=nums.size(),temp;
            int minnum = nums[len-1];
            for (i = len-1; i >0; --i) {
                if(nums[i]>nums[i-1])
                {
                    if(minnum > nums[i-1])
                    {
                        nums.insert(nums.begin()+i-1,nums[len-1]);
                        nums.resize(len);
                        reverse(nums.begin()+i+1,nums.end());
                    }
                    else
                    {
                        temp = i;
                        for (j = i+1; j < len; ++j) {
                            if(nums[j] > nums[i-1])
                                temp = j;
                        }
                        swap(nums[temp],nums[i-1]);
                        nums.resize(len);
                        reverse(nums.begin()+i,nums.end());
                    }
                    return;
                }
            }
            reverse(nums.begin(),nums.end());
            return;
        }
};
int main(int argc, char *argv[])
{
    vector<int> nums = {1,3,2};
    nums.insert(nums.begin(),nums[2]);
    for(auto e : nums)
        cout << e << " ";
    return 0;
}
