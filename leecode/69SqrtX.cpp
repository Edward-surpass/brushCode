/*********************************************************************************
*     File Name           :     69SqrtX.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-04 14:57]
*     Last Modified       :     [2015-10-04 16:23]
*     Description         :     Implement int sqrt(int x).

Compute and return the square root of x.
**********************************************************************************/
class Solution {
    public:
        int mySqrt(int x) {
            if(x < 0)
                return 0;
            if(x == 0 || x == 1)
                return x;
            int i;
            for (i = 1; i*i < x; ) 
            {
                i += i;
            }
            if(i * i != x)
                i /= 2;
            for (; i*i < x; ++i) ;
            if(i * i != x)
                i -= 1;
            return i;
            
        }

};

