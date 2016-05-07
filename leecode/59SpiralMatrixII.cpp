/*********************************************************************************
*     File Name           :     59SpiralMatrixII.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-29 09:16]
*     Last Modified       :     [2015-07-29 09:41]
*     Description         :     iGiven an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3  ],
  [ 8, 9, 4  ],
   [ 7, 6, 5  ]

]
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int upedp=0,downedp = n-1,leftedp = 0,rightedp = n-1;
            vector<int> temp;
            temp.resize(n);
            vector<vector<int>> res(n,temp);
            int x,y,i=1;
            while(upedp<=downedp && leftedp<=rightedp)
            {
                for (y = leftedp,x=upedp; y <= rightedp; ++y) {
                    res[x][y]=i;
                    ++i;
                }
                ++upedp;
                if(upedp>downedp)
                    break;
                for(x=upedp,y=rightedp;x<=downedp;++x)
                {
                    res[x][y]=i++;
                }
                --rightedp;
                if(leftedp>rightedp)
                    break;
                for(x=downedp,y=rightedp;y>=leftedp;--y)
                    res[x][y]=i++;
                --downedp;
                if(upedp>downedp)
                    break;
                for(x=downedp,y=leftedp;x>=upedp;--x)
                    res[x][y]=i++;
                ++leftedp;
            }
            return std::move(res);
        }

};

