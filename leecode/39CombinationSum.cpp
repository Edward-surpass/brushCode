/*********************************************************************************
*     File Name           :     39CombinationSum.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 15:45]
*     Last Modified       :     [2015-07-21 10:35]
*     Description         :      
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
**********************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> path;
            vector<vector<int>> res;
            sort(candidates.begin(),candidates.end());
            dfs(candidates,0,0,res,path,target);
            return res;
        }
        void dfs(vector<int> &candidates,int index,int sum,vector<vector<int>> &res,vector<int> &path,int target)
        {
            if(sum > target)
                return;
            if(sum == target)
                res.push_back(path);
            size_t i;
            for (i = index; i < candidates.size(); ++i) {
                path.push_back(candidates[i]);
                dfs(candidates,i,sum+candidates[i],res,path,target);
                path.pop_back();
            }
        }
};

