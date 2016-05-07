/*********************************************************************************
*     File Name           :     77Combinations.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-09 22:55]
*     Last Modified       :     [2016-04-09 23:30]
*     Description         :      
**********************************************************************************/
#include <vector>
class Solution {
    public:
        std::vector<std::vector<int>> combine(int n, int k) {
            std::vector<std::vector<int>> res;
            std::vector<std::vector<int>> temp_res;
            std::vector<int> temp;
            for (int i = 1; i <= k; ++i)
            {
                if(i == 1)
                {
                    for (int j = 1; j <= n; ++ j)
                    {
                        res.push_back(std::vector<int>{j});
                    }
                    continue;
                }
                for(int j = 0; j < res.size(); ++j)
                {
                    temp = res[j];
                    for (int l = temp.back() + 1; l <= n; ++l)
                    {
                        temp_res.push_back(temp);
                        temp_res.back().push_back(l);
                    }
                }
                res = temp_res;
                temp_res.clear();
            }
                
            return res;
        }

};
int main(int argc, char *argv[])
{
    Solution so;
    so.combine(1,1);
    return 0;
}
