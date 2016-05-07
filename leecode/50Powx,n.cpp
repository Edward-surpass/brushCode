/*********************************************************************************
*     File Name           :     50Powx,n.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-27 13:28]
*     Last Modified       :     [2015-07-27 16:43]
*     Description         :     iImplement 
**********************************************************************************/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        double myPow(double x, int n) {
            if(n==0)
                return 1.0;
            if(x==0 || x==1)
                return x;
            if(n<0)
            {
                x=1/x;
                n=-n;
            }
            double half = myPow(x,n>>1);
            if(n%2==0)
                return half * half;
            else
                return half * half * x;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.myPow(2,5) << endl;
    return 0;
}
