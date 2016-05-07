/*********************************************************************************
*     File Name           :     46Permutations.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-22 20:28]
*     Last Modified       :     [2015-07-25 18:36]
*     Description         :    Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

**********************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
    public:

        friend bool operator<(const vector<int> &lhs, const vector<int> &rhs)
        {
            int sz = lhs.size() < rhs.size()?lhs.size():rhs.size();
            for (int i = 0; i < sz; ++i) {
                if(lhs[i] > rhs[i])
                    return false;
            }
            if(lhs.size() > rhs.size())
                return false;
            return true;
        }
        friend bool operator==(const vector<int> &lhs,const vector<int> &rhs)
        {
            int sz;
            if((sz = lhs.size()) != rhs.size())
                return false;
            for (int i = 0; i < sz; ++i) {
                if(lhs[i]!=rhs[i])
                    return false;
            }
            return true;
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
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
                        if(vi[k]!= vi[tempS-1])
                        {
                            swap(vi[k],vi[tempS-1]);
                            interRes.push_back(vi);
                        }
                    }
                }
                res = interRes;
                interRes.clear();
            }
            processRes(res);
            return std::move(res);
        }
        void processRes(vector<vector<int>> &res)
        {
            sort(res.begin(),res.end());
            auto p = unique(res.begin(),res.end());
            res.resize(p-res.begin());
        }
};
