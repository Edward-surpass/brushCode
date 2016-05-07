/*********************************************************************************
*     File Name           :     67AddBinary.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-03 21:50]
*     Last Modified       :     [2015-10-03 22:24]
*     Description         :     Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
**********************************************************************************/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
    public:
        string addBinary(string a, string b) {
            int lenLf = a.size()-1,lenRf = b.size()-1;
            int r=0,lf,rf,tol;
            string res;
            while (lenLf >= 0 || lenRf >=0) {
                if(lenLf >= 0)
                {
                    lf = a[lenLf]-'0';
                    --lenLf;
                }
                else
                    lf = 0;
                if(lenRf >=0 )
                {
                    rf = b[lenRf]-'0';
                    --lenRf;
                }
                else
                    rf = 0;
                tol = rf + lf + r;
                if(tol == 3)
                {
                    r = 1;
                    res.push_back('1');
                }
                else if(tol == 2)
                {
                    r = 1;
                    res.push_back('0');
                }
                else if(tol == 1 || tol == 0)
                {
                    r = 0;
                    res.push_back(tol + '0');
                }
                std::cout << res << std::endl;
            }
            if(r == 1)
                res.push_back('1');
            reverse(res.begin(),res.end());
            return res;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    std::cout << so.addBinary("111","1011") << std::endl;

    return 0;
}
