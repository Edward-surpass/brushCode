/*********************************************************************************
*     File Name           :     10RegularExpressionMatching.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-04 22:17]
*     Last Modified       :     [2015-07-06 12:27]
*     Description         :      
topic:Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
**********************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool isMatch(string s, string p) {
            string::iterator lb = s.begin(),le = s.end(),rb = p.begin(),re = p.end();
            return poinMathc(lb,le,rb,re);
        }
        bool poinMathc(string::iterator lb,string::iterator le,string::iterator rb,string::iterator re)
        {
            if(rb == re)
                return lb == le;
            if(*(rb +1) == '*')
            {
                while(lb != le && (*lb == *rb || *rb == '.'))
                {
                    if(poinMathc(lb,le,rb+2,re))
                        return true;
                    ++lb;
                }
                poinMathc(lb,le,rb+2,re);
            }
            else
            {
                if(lb != le &&(*lb == *rb || *rb == '.'))
                    return poinMathc(lb+1,le,rb+1,re);
                return false;
            }
        }

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isMatch("a","a*a") << endl;
    return 0;
}
