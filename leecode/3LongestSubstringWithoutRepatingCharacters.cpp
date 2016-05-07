/*********************************************************************************
*     File Name           :     3LongestSubstringWithoutRepatingCharacters.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-01 12:53]
*     Last Modified       :     [2015-07-01 13:42]
*     Description         :      
topic:Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
**********************************************************************************/
#include <string>
#include <iostream>
#include <set>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.empty())
                return 0;
            set<char> schar;
            size_t maxlen=1;
            size_t i=0,j=1;
            schar.insert(s[0]);
            while(j < s.size())
            {
                set<char>::iterator p = schar.find(s[j]);
                if(p != schar.cend())
                {
                    while(s[i]!=s[j])
                    {
                        schar.erase(s[i]);
                        ++i;
                    }
                    ++i;
                    ++j;
                }
                else{
                    schar.insert(s[j++]);
                    maxlen=maxlen>(j-i)?maxlen:(j-i);
                }
                
            }
            return maxlen;
        }

};

int main(int argc, char *argv[])
{
    Solution so;
    string str = "abcdbcv";
    cout << so.lengthOfLongestSubstring(str) << endl;;
    return 0;
}
