/*********************************************************************************
*     File Name           :     UniquePaths.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-30 11:54]
*     Last Modified       :     [2015-07-30 12:15]
*     Description         :     iA robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?
**********************************************************************************/
#include <iostream>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(m<n)
                return uniquePaths(n,m);
            long long mlclr=1,dnmtr=1;
            int i;
            for (i = m; i <= m+n-2; ++i) {
                mlclr *= i;
            }
            for (i = 1; i <= n-1; ++i) {
                dnmtr *= i;
            }
            cout << mlclr << " " << dnmtr << endl;
            i = mlclr/dnmtr;
            return i;
        }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.uniquePaths(36,7) << endl;
    return 0;
}
