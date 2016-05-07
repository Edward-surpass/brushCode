/*********************************************************************************
*     File Name           :     35SearchInsertPosition.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 10:47]
*     Last Modified       :     [2015-07-19 11:05]
*     Description         :      
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int i=0,len = nums.size(),j=len,mid;
            while(i<j)
            {
                mid = i + (j-i)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] > target)
                    j = mid;
                else
                    i = mid+1;
            }
            return i;
        }
};

int main(int argc, char *argv[])
{
    vector<int> nums= {1,3,5,6};
    Solution so;
    cout << so.searchInsert(nums,0) << endl;
    return 0;
}
