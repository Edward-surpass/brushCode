/*********************************************************************************
*     File Name           :     11ContainerWithMostWater.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-06 12:55]
*     Last Modified       :     [2015-07-06 15:15]
*     Description         :      
topic:Container With Most Water Total Accepted: 43118 Total Submissions: 135137 My Submissions Question Solution 
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
**********************************************************************************/

#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int cap = 0,maxS = 0;;
            int le = 0,ri = height.size()-1;
            while(le < ri)
            {
                cap = (height[le] < height[ri]?height[le]:height[ri])*(ri-le);
                maxS = maxS > cap? maxS:cap;
                if(height[le]<height[ri])
                {
                    ++le;
                }
                else
                {
                    --ri;
                }
            }
            return maxS;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    vector<int> vi = {9,6,14,11,2,2,4,9,3,8};
    cout << so.maxArea(vi) << endl;
    return 0;
}
