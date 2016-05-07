/*********************************************************************************
*     File Name           :     15LongestCommonPrefix.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-06 17:28]
*     Last Modified       :     [2015-07-06 17:49]
*     Description         :      
topic:Write a function to find the longest common prefix string amongst an array of strings
**********************************************************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {          
            int i,len=strs.size(),j=0;
            if(strs.empty())
                return string("");
            while(1)
            {
                char c;
                if(j<strs[0].size())
                    c = strs[0][j];
                else
                    return strs[0].substr(0,j);
                for (i = 1; i < len; ++i) {
                    if(j == strs[i].size() || c != strs[i][j])
                    {
                        return strs[0].substr(0,j);
                    }
                }
                ++j;
            }
        }
};
int main(int argc, char *argv[])
{
    vector<string> vs;
    Solution so;
    cout << so.longestCommonPrefix(vs) << endl;
    return 0;
}
