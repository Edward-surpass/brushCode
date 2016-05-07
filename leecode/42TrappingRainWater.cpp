/*********************************************************************************
*     File Name           :     42TrappingRainWater.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-21 18:09]
*     Last Modified       :     [2015-07-22 10:06]
*     Description         :     Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
**********************************************************************************/
#include<vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            if(height.empty())
                return 0;
            int lh = 0,rh = height.size()-1,sz = 0;
            interTrap(height,lh,rh,sz);
            return sz;
        }
        void interTrap(vector<int> &height,int be,int en,int &sz)
        {
            if(be == en || be == en-1 )
                return;
            int lh=be,rh=en;
            int lt = lh,rt = rh;
            int cap=0,i;
            while(lh<rh-1)
            {
                if(height[lh]<height[rh])
                    ++lh;
                else
                    --rh;
                if(height[lh]>height[lt])
                    lt = lh;
                if(height[rh]>height[rt])
                    rt = rh;
            }
            cap = (height[lt]<height[rt]?height[lt]:height[rt])*(rt-lt-1);
            cout << cap << endl;
            cout << lt << " " << rt << endl;
            cout << "==========" << endl;
            for(i = lt+1;i < rt;++i)
            {
                cap -= height[i];
            }
            sz+=cap;
            interTrap(height,be,lt,sz);
            interTrap(height,rt,en,sz);
        }
};
int main(int argc, char *argv[])
{
    vector<int> height = {0,2,0};
    Solution so;
    cout << so.trap(height) << endl;
    return 0;
}
