/*********************************************************************************
*     File Name           :     44#ildcardMatching.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-22 13:07]
*     Last Modified       :     [2015-07-22 17:09]
*     Description         :     Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
**********************************************************************************/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool isMatch(string s, string p) {
            s_len = s.size();
            p_len = p.size();
            return interMatch(s,0,p,0);
        }
        bool interMatch(string &s,int s_be,string &p,int p_be)
        {
            int i = s_be,j = p_be,xinPs,xinPp;
            s+="#";
            p+="#";
            bool hasxin = false;
            while(i<s_len && j<p_len+1)
            {
                if(s[i] == p[j] || p[j] == '?')
                {
                    ++i;
                    ++j;
                    continue;
                }
                else if(p[j]=='*' )
                {
                    hasxin = true;
                    xinPs = i;
                    xinPp = j;
                    ++j;
                }
                else if(hasxin) 
                {
                    
                    i = ++xinPs;
                    j = xinPp+1;
                }
                else
                    return false;
            }
            while(j<p_len+1 && p[j]=='*') 
            {
                ++j;   
            }
            return (j==p_len);
        }
    private:
        int s_len;
        int p_len;

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isMatch("ho", "ho**") << endl;
    return 0;
}
