/*********************************************************************************
*     File Name           :     70ClimbingStairs.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-04 16:23]
*     Last Modified       :     [2015-10-04 16:35]
*     Description         :     You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**********************************************************************************/
#include <iostream>
class Solution {

    public:
        int climbStairs(int n) {
            int pre1,pre2,res;
            pre1 = 1,pre2 = 2;
            if(n==1)
                return 1;
            if(n==2)
                return 2;
            int i = 3;
            for (; i <= n; ++i) {
                res = pre1+pre2;
                pre1 = pre2;
                pre2 = res;
            }
            return res;
        }

};
int main(int argc, char *argv[])
{
    Solution so;
    std::cout << so.climbStairs(16) << std::endl;
    return 0;
}
