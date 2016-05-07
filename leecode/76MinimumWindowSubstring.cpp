/*********************************************************************************
*     File Name           :     76MinimumWindowSubstring.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-09 21:11]
*     Last Modified       :     [2016-04-09 22:55]
*     Description         :      
**********************************************************************************/
#include <string>
#include <vector>
#include <iostream>

class Solution {
    public:
        std::string minWindow(std::string s, std::string t) {
            if(t.empty())
                return std::string("");
            int needNum[128] = {0};
            for (int i = 0; i < t.size(); ++i)
            {
                ++needNum[static_cast<int>(t[i])];
            }
            int st = -1, en =  0;
            int re_st = -1, re_en = -1;
            int curNum[128] = {0};
            while(en < s.size())
            {
                if(st == -1)
                {
                    ++curNum[static_cast<int>(s[++st])];
                }
                if(en - st + 1 < t.size())
                {
                    ++curNum[static_cast<int>(s[++en])];
                    continue;
                }
                if(my_judge(needNum, curNum))
                {
                    if(re_st == -1)
                    {
                        re_st = st;
                        re_en = en;
                    }
                    else
                    {
                        if(en - st < re_en - re_st)
                        {
                            re_st = st;
                            re_en = en;
                        }
                    }
                    --curNum[static_cast<int>(s[st++])];
                }
                else
                    ++curNum[static_cast<int>(s[++en])];
            }
            if(re_st == -1)
                return std::string("");
            std::cout << re_st << " " << re_en << std::endl;
            return std::string(s, re_st, re_en - re_st +1);
        }
        bool my_judge(int *need, int *cur)
        {
            for(int i = 0; i <=128; ++i)
            {
                if(cur[i] < need[i])
                {
                    return false;
                }
            }
            return true;
        }

};
int main(int argc, char *argv[])
{
    std::string s = "a";
    std::string t = "a";
    Solution so;
    so.minWindow(s,t);
    std::cout << so.minWindow(s,t) << std::endl;
    return 0;
}
