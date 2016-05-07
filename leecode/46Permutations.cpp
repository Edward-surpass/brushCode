/*********************************************************************************
*     File Name           :     46Permutations.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-22 20:28]
*     Last Modified       :     [2015-07-25 18:11]
*     Description         :     Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            if(nums.empty())
                return vector<vector<int>>();
            int i,j,k,len = nums.size(),tempS;
            vector<int> temp = {nums.front()},vi;
            vector<vector<int>> res,interRes;
            res.push_back(temp);
            for (i = 1; i < len ; ++i) {
                for (j = 0;  j< (int)res.size(); ++j) {
                    temp = res[j];
                    temp.push_back(nums[i]);
                    tempS = temp.size();
                    interRes.push_back(temp);
                    for (k = 0; k < tempS-1; ++k) {
                        vi = temp;
                        swap(vi[k],vi[tempS-1]);
                        interRes.push_back(vi);
                    }
                }
                res = interRes;
                interRes.clear();
            }
            return res;
        }
};

