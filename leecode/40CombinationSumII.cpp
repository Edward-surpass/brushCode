/*********************************************************************************
*     File Name           :     40CombinationSumII.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-21 10:04]
*     Last Modified       :     [2015-07-21 13:58]
*     Description         :     Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
**********************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class isVequal{
    public:
        bool operator()(const vector<int> &lhs,const vector<int> &rhs)
        {
            if(lhs.size()!=rhs.size())
                return false;
            for (size_t i = 0; i < lhs.size(); ++i) {
                if(lhs[i]!=rhs[i])
                    return false;
            }
            return true;
        }
};
bool operator<(const vector<int> &lhs,const vector<int> &rhs)
{
    if(rhs.size() < lhs.size())
        return operator<(rhs,lhs);
    size_t len = lhs.size();
    for (size_t i = 0; i < len; ++i) {
        if(lhs[i]>rhs[i])
            return false;
    }
    return true;
}
class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>> res;
            vector<int> path;
            interCombonation(candidates,0,0,target,res,path);
            //sort(res.begin(),res.end());
            //auto p = unique(res.begin(),res.end(),isVequal());
            //res.resize(p-res.begin());
            for (size_t i = 0; i< res.size(); ++i) {
                for (size_t j = 0; j < res[i].size(); ++j) {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
            return res;
        }
        void interCombonation(vector<int> &candidates,int index,int sum,int target,vector<vector<int>> &res,vector<int> &path)
        {
            if(sum == target)
            {
                res.push_back(path);
                return ;
            }
            else if(sum > target)
                return ;
            else
            {
                for (int i = index; i < candidates.size(); ++i) {
                    path.push_back(candidates[i]);
                    interCombonation(candidates,i+1,sum+candidates[i],target,res,path);
                    path.pop_back();
                    int j = i+1;
                    while(j<candidates.size() && candidates[j] == candidates[i])
                        ++j;
                    i = j-1;
                }
            }
        }

};
int main(int argc, char *argv[])
{
    vector<int> can = {10,1,2,7,6,1,5};
    Solution so;
    so.combinationSum2(can,8);
    return 0;
}
