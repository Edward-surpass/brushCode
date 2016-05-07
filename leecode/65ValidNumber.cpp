/*********************************************************************************
*     File Name           :     65ValidNumber.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-30 14:10]
*     Last Modified       :     [2015-10-03 21:48]
*     Description         :     Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        bool isNumber(string s) {
            len = s.size();
            int i,j;
            for (i = 0; i < len; ++i) {
                if(s[i] != ' ')
                    break;
            }
            for (j = len-1; j >=0 ; --j) {
                if(s[j] != ' ')
                    break;
            }
            s = s.substr(i,j-i+1);
            len = s.size();
            size_t r = s.find(' ');
            if(r!=string::npos)
                return false;
            if(s[0] == '-' || s[0] == '+')
                s.erase(0,1);
            size_t p = s.find('e');
            len = s.size();
            if(p != string::npos && p < len-1)
            {
                if(s[p+1] == '-' || s[p+1] == '+')
                    s.erase(p+1,1);
            }
            if(s.empty())
                return false;
            p = s.find('e');
            size_t q = s.find('.');
            len = s.size();
            if(p!=string::npos && (p ==0 || p == len-1 ))
                return false;
            if(p!=string::npos && len < 2 || q!=string::npos && len < 2)
                return false;
                
            if(p != string::npos && q != string::npos)
            {
                if(q+1 == p)
                {
                    if(q==0 || p == len-1)
                        return false;
                }
                if(q < p)
                {
                    for (i = 0; i < len; ++i) {
                        if(i != q && i != p)
                        {
                            if(!isDig(s[i]))
                                return false;
                        }
                    }
                    return true;
                }
                else
                    return false;
            }
            else if(p != string::npos)
            {
                for (i = 0; i < len; ++i) {
                    if(i != p)
                    {
                        if(!isDig(s[i]))
                            return false;
                    }
                }
                return true;
            }
            else if(q != string::npos)
            {
                for (i = 0; i < len; ++i) {
                    if(i != q)
                    {
                        if(!isDig(s[i]))
                            return false;
                    }
                }
                return true;
            }
            else
            {
                for (i = 0; i < len; ++i) {
                    if(!isDig(s[i]))
                        return false;
                }
                return true;
            }
        }
        bool isDig(char c)
        {
            if( c>='0' && c<='9')
                return true;
            else
                return false;
        }
    private:
        int len;
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isNumber(".e3 ") << endl;
    return 0;
}

