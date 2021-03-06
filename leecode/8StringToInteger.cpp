/*********************************************************************************
      File Name           :     8StringToInteger.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-04 17:55]
*     Last Modified       :     [2015-07-04 18:46]
*     Description         :      
topic:Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int myAtoi(string str) {
            size_t i=0;
            bool isneg = false;
            for (; i < str.size(); ++i) {
                if(str[i] == 32)
                    continue;
                else
                    break;
            }
            if(str[i] == 43)
            {
                isneg = false;
                ++i;
            }
            else if(str[i] == 45)
            {
                isneg = true;
                ++i;
            }
            long int num=0;
            for (; i < str.size(); ++i) {
                if(str[i]<48 || str[i]>57)
                    break;
                num = num*10+(str[i]-48);
                if(num > 0x7fffffff)
                {
                    if(!isneg)
                        return 0x7fffffff;
                    else 
                        return 0x80000000;
                }
                
            }
            if(isneg)
                return -num;
            return num;
        }
};
int main(int argc, char *argv[])
{
    string nums="9223372036854775809";
    Solution so;
    cout << so.myAtoi(nums) << endl;
    return 0;
}
