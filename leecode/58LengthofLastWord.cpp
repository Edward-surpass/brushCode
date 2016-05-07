/*********************************************************************************
*     File Name           :     58LengthofLastWord.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-29 09:04]
*     Last Modified       :     [2015-07-29 09:14]
*     Description         :     Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
**********************************************************************************/
#include <string>
using namespace std;
class Solution {
    public:
        int lengthOfLastWord(string s) {
            if(s.empty())
                return 0;
            int i = s.size()-1;
            int len=0;
            while(i>=0 && s[i]==' ')
                --i;
            while(i>=0 && s[i]!=' ')
            {
                ++len;
                --i;
            }
            return len;
        }
};

