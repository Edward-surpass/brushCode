/*********************************************************************************
*     File Name           :     1twosum.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-01 10:15]
*     Last Modified       :     [2015-07-01 11:59]
*     Description         :      
topic:Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
**********************************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        multimap<int,int> mint;
        for (size_t i = 0; i < nums.size(); ++i) {
            mint.insert(pair<int,int>(nums[i],i));
        }
        map<int,int>::iterator beg = mint.begin(),end = mint.end();
        --end;
        while(beg != end)
        {
            temp = beg->first + end->first;
            if(temp == target)
            {
                return beg->second < end->second?vector<int>{beg->second+1,end->second+1}:vector<int>{end->second+1,beg->second+1};
            }
            else if(temp > target)
            {
                --end;
            }
            else{
                ++beg;
            }
            
        }
        return vector<int> {0,0};
    }
};
int main(int argc, char *argv[])
{
    vector<int> numbers;
    int target;
    Solution so;
    while(cin >> target)
    {
        numbers.push_back(target);
    }
    numbers.erase(numbers.end()-1);
    vector<int> index = so.twoSum(numbers,target);
    for(size_t i = 0;i<index.size();++i)
    {
        cout << index[i]  << " ";
    }
    cout << endl;
    return 0;
}
