/*********************************************************************************
*     File Name           :     78SubSets.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-11 21:07]
*     Last Modified       :     [2016-04-17 16:29]
*     Description         :      
**********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
            //std::sort(nums.begin(), nums.end(), [](const int &lbs, const int &rbs){return lbs > rbs;});
            std::vector<std::vector<int>> res,  cur_res;
            res.push_back(std::vector<int>());
            if(nums.empty())
            {
                return res;

            }
            for (int i = 0; i < nums.size(); ++i)
            {
                cur_res = res;
                for (int j = 0; j < cur_res.size(); ++j)
                {
                    res.push_back(cur_res[j]);
                    int temp = nums[i];
                    auto it = std::find_if(res.back().begin(), res.back().end(), [temp](const int &a){return a > temp;});
                    res.back().insert(it, temp);
                }
            }

        }

};
