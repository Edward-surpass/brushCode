/*********************************************************************************
*     File Name           :     48RotateImage.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-25 21:56]
*     Last Modified       :     [2015-07-26 10:20]
*     Description         :     You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
**********************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            if(matrix.empty())
                return ;
            if(matrix.size() == 1)
                return;
            int n = matrix.size();
            int i,j,m,k,x,y;
                m =k = n-1;
                for (i = 0; i < n/2; ++i) {
                    for (j = i;  j< k; ++j) {
                        //cout << "i:" << i << " j:" << j << endl;
                        x = j;
                        y = m-i;
                        //cout << x << " " << y << endl;
                        swap(matrix[i][j],matrix[x][y]);
                        x = m-i;
                        y = m-j;
                        //cout << x << " " << y << endl;
                        swap(matrix[i][j],matrix[x][y]);
                        x=m-j;
                        y=i;
                        //cout << x << " " << y << endl;
                        swap(matrix[i][j],matrix[x][y]);
                        //cout << "=-=============" << endl;
                    }
                    --k;
                }
        }
};
int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution so;
    so.rotate(matrix);
    return 0;
}
