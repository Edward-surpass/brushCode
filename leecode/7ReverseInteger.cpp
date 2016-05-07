/*********************************************************************************
*     File Name           :     7ReverseInteger.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-04 16:36]
*     Last Modified       :     [2015-07-04 17:55]
*     Description         :      
topic:Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
**********************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        int reverse(int x) {
            if(x == 0)
                return 0;
            bool isneg = false;
            long int re=0;
            vector<int> numi;
            if(x<0)
            {
                isneg = true;
                x=-x;
            }
            while(x>0)
            {
                numi.push_back(x%10);
                x /= 10;
            }
            size_t i;
            for (i = 0; i < numi.size(); ++i) {
                re=re*10+numi[i];
                if(re>0x7fffffff)
                    return 0;
            }
            if(isneg)
                return -re;
            else
            {
                if(re == 0x080000000)
                    return 0;
                return re;
            }
        }

};
int main(int argc, char *argv[])
{
    int a = -1;
    Solution so;
    cout << so.reverse(1534236469) << endl;
    return 0;
}
