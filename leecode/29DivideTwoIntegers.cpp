/*********************************************************************************
*     File Name           :     28DivideTwoIntegers.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 22:22]
*     Last Modified       :     [2015-07-12 18:57]
*     Description         :      
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
**********************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_INT 0x7fffffff
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(divisor == 0) 
                return MAX_INT;
            long long resul = 0,cnt = 1;        
            bool isneg = true;
            if((dividend>0&&divisor>0) || (dividend<0&&divisor<0))
                isneg =false;
            long long dend = abs((long long)dividend);
            long long disr = abs((long long)divisor);
            if(dend < disr)
                return 0;
            long long temp = disr;
            while(dend >= disr)
            {
                temp = disr;
                cnt = 1;
                while(dend>= (temp<<1))
                {
                    cnt <<= 1;
                    temp <<= 1;
                }
                dend -= temp;
                resul += cnt;
            }
            if(!isneg && resul > MAX_INT)
                return MAX_INT;
            return isneg?-resul:resul;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.divide(-2147483648, 1) << endl;
    return 0;
}
