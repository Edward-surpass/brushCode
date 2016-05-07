/*********************************************************************************
*     File Name           :     41FirstMissingPositive.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-21 14:07]
*     Last Modified       :     [2015-07-21 17:42]
*     Description         :     Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
**********************************************************************************/
#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            if(nums.empty())
                return 1;
            int i=0,len = nums.size();
            while(i < len && nums[i] <= 0)
                ++i;
            if(i == len)
                return 1;
            set<int> lowindex,upperindex;
            lowindex.insert(nums[i]-1);
            upperindex.insert(nums[i]+1);
            ++i;
            for (; i < len; ++i) {
                if(nums[i]>0)
                {
                    set<int>::iterator p = lowindex.find(nums[i]),q;
                    if(p != lowindex.end())
                    {
                        lowindex.erase(p);
                        lowindex.insert(nums[i]-1);
                        p = upperindex.find(nums[i]);
                        if(p!=upperindex.end())
                        {
                            upperindex.erase(p);
                            lowindex.erase(nums[i]-1);
                        }
                        continue;
                    }
                    p = upperindex.find(nums[i]);
                    if(p != upperindex.end())
                    {
                        upperindex.erase(p);
                        upperindex.insert(nums[i]+1);
                        continue;
                    }
                    bool isin =false;
                    for (p = lowindex.begin(),q = upperindex.begin();  p != lowindex.end()&&q != upperindex.end(); ++p,++q) {
                        if(nums[i]>*p && nums[i]<*q)
                        {
                            isin = true;
                            break;
                        }
                    }
                    if(isin)
                        continue;
                    lowindex.insert(nums[i]-1);
                    upperindex.insert(nums[i]+1);
                }
            }
            if(*lowindex.begin()!=0)
                return 1;
            else
                return *(upperindex.begin());
            
        }

};
int main(int argc, char *argv[])
{
    vector<int> nums={0,2,2,1,1};
    Solution so;
    cout << so.firstMissingPositive(nums) << endl;
    return 0;
}
