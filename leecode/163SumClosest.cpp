/*********************************************************************************
*     File Name           :     3SumClosest.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-07 19:42]
*     Last Modified       :     [2015-07-07 21:44]
*     Description         :      
topic:Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            if(nums.size() < 3)
                return 0;
            sort(nums.begin(),nums.end());
            vector<int>::iterator b,e,p=nums.begin();
            int minsum = nums[0]+nums[1]+nums[2],minsub=abs(minsum-target),tempsum;
            while(p < nums.end()-1)
            {
                if(p!=nums.begin() && *p == *(p-1))
                {
                    ++p;
                    continue;
                }
                b=p+1;
                e=nums.end()-1;
                while(b < e)
                {
                    tempsum = *b + *e + *p;
                    if(b!=p+1&&*b == *(b-1))
                        ++b;
                    else if(e != nums.end()-1 && *e == *(e+1))
                        --e;
                    else if(tempsum > target)
                    {
                        if(minsub >= tempsum-target)
                        {
                            minsub = tempsum-target;
                            minsum = tempsum;
                        }
                        --e;
                    }
                    else if(tempsum < target)
                    {
                        if(minsub >= target-tempsum)
                        {
                            minsub = target - tempsum;
                            minsum = tempsum;
                        }
                        ++b;
                    }
                    else{
                        return target;
                    }
                }
                ++p;
            }
            return minsum;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    vector<int> vi ={86,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4};
    sort(vi.begin(),vi.end());
    for(auto e:vi)
        cout << e << " ";
    cout << endl;
    cout << so.threeSumClosest(vi,-275) << endl;
    return 0;
}
