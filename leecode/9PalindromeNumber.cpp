/*********************************************************************************
*     File Name           :     9PalindromeNumber.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-04 18:52]
*     Last Modified       :     [2015-07-04 22:14]
*     Description         :      
topic:Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
**********************************************************************************/

#include <iostream>
using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            int leftd,rightd;
            if(x <0)
                return false;
            if(x == 0)
                return true;
            int base = 1;
            while(x/base > 9)
                base *= 10;
            while(x)
            {
                leftd = x/base;
                rightd = x%10;
                if( leftd != rightd )
                    return false;
                x = x-leftd*base;
                base=base/100;
                x=x/10;
            }
            return true;
        }

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isPalindrome(10) << endl;
    return 0;
}
