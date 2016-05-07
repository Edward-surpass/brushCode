/*********************************************************************************
*     File Name           :     49Anagrams.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-26 19:03]
*     Last Modified       :     [2015-07-27 10:43]
*     Description         :     iGiven an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
**********************************************************************************/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<string> anagrams(vector<string>& strs) {
            vector<string> res;
            string s;
            unordered_map<string,int> vmsi;
            size_t i,len = strs.size();
            for (i = 0; i < len; ++i) {
                s = strs[i];
                sort(s.begin(),s.end());
                if(vmsi.find(s) == vmsi.end())
                    vmsi[s] = i;
                else
                {
                    if(vmsi[s]>=0)
                    {
                        res.push_back(strs[vmsi[s]]);
                        vmsi[s]=-1;
                    }
                    res.push_back(strs[i]);
                }
            }
            return res;
        }
};
