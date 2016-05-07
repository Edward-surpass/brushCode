/*********************************************************************************
*     File Name           :     163Sum.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-06 17:56]
*     Last Modified       :     [2015-07-07 19:42]
*     Description         :      
topic:Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

        A solution set is:
            (-1, 0, 1)
                (-1, -1, 2)
**********************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            if(nums.size()<3)
                return vector<vector<int>>();
            sort(nums.begin(),nums.end());
            vector<vector<int>> resul;
            vector<int>::iterator b = nums.begin(),e = nums.end(),p=b;
            int sum;
            while(p < nums.end()-2)
            {
                b=p+1;
                e=nums.end();
                if(p!=nums.begin() && *p == *(p-1))
                {
                    ++p;
                    continue;
                }
                while(b < e-1)
                {
                    sum = *p + *b + *(e-1);
                    if(sum > 0)
                    {
                        --e;
                    }
                    else if(sum < 0)
                    {
                        ++b;
                    }
                    else if(p != b-1 && *p == *(p-1))
                    {
                        ++b;
                    }
                    else if(e!=nums.end() && *(e-1) == *e)
                    {
                        --e;
                    }
                    else
                    {
                        resul.push_back({*p,*b,*(e-1)});
                        ++b;
                        --e;
                    }
                }
                ++p;
            }
            return resul;
        }
};
int main(int argc, char *argv[])
{
    //vector<int> S = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    //vector<int> S = -1,0,1,2,-1,-4};
    vector<int> S = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> vvi;
    Solution so;
    vvi = so.threeSum(S);
    size_t i,j;
    for (i = 0; i < vvi.size(); ++i) {
        for (j = 0;  j < vvi[i].size(); ++j) {
            cout << vvi[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
