/*********************************************************************************
*     File Name           :     20ValidParentheses.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-08 20:42]
*     Last Modified       :     [2015-07-09 10:57]
*     Description         :      
topic:Valid Parentheses Total Accepted: 57921 Total Submissions: 218453 My Submissions Question Solution 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not."))"
**********************************************************************************/
#include <string>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> sc;
            set<char> rbra = {')','}',']'};
            set<char> lbrk = {'(','[','{'};
            map<char,char>lrbar = {{')','('},{']','['},{'}','{'}};
            int slen = s.size();
            int i;
            for (i = 0; i < slen; ++i) {
                if(rbra.find(s[i]) != rbra.end())
                {
                    if(sc.empty())
                        return false;
                    while(!sc.empty() && sc.top() != lrbar[s[i]]) 
                    {
                        
                        if(lbrk.find(sc.top())!=lbrk.end())
                            return false;
                        sc.pop();
                    }
                    if(sc.empty())
                        return false;
                    sc.pop();
                }
                else
                {
                    sc.push(s[i]);
                }
            }
            while(!sc.empty())
            {
                if(lbrk.find(sc.top()) != lbrk.end())
                    return false;
                sc.pop();
            }
            return true;
                
        }

};
