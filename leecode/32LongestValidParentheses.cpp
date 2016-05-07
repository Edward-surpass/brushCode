/*********************************************************************************
*     File Name           :     32LongestValidParentheses.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-17 21:41]
*     Last Modified       :     [2015-07-18 14:18]
*     Description         :      
topic:Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
**********************************************************************************/
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int longestValidParentheses(string s) {
            int i,j,len = s.size(),bmax = 0;
            vector<int> dp(len,0);
            for (i = len-2; i >=0; --i) {
                if(s[i] == '(')
                {
                    j=i+1+dp[i+1];
                    if(j<len && s[j] == ')')
                    {
                        dp[i] = dp[i+1] +2;
                        if(j+1 < len)
                            dp[i] += dp[j+1];
                    }
                }
                if(bmax < dp[i])
                    bmax = dp[i];
            }
            return bmax;
        }
};

