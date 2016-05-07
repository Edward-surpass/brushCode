/*********************************************************************************
*     File Name           :     4MedianofTwoSortedArrays.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-01 13:42]
*     Last Modified       :     [2015-07-03 13:42]
*     Description         :      
topic:There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
**********************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int k = nums1.size() + nums2.size();
            if(k%2 == 1)
            {
                k=k/2;
                return getkth(nums1,0,nums1.size(),nums2,0,nums2.size(),k+1);
            }
            else{
                k=k/2;
                return (getkth(nums1,0,nums1.size(),nums2,0,nums2.size(),k)+getkth(nums1,0,nums1.size(),nums2,0,nums2.size(),k+1))/2;
            }
        }
        double getkth(vector<int> &nums1,int s1be,int s1en,vector<int> &nums2,int s2be,int s2en,int k)
        {
            //cout << "s1be:" << s1be << endl;
            //cout << "s1en:" << s1en << endl;
            //cout << "s2be:" << s2be << endl;
            //cout << "s2en:" << s2en << endl;
            //cout << "k:" << k << endl;
            if(s1en-s1be > s2en-s2be)
                return getkth(nums2,s2be,s2en,nums1,s1be,s1en,k);
            if(s1en-s1be==0)
                return nums2[k+s2be-1];
            if(k==1)
            {
                return nums1[s1be]<nums2[s2be]?nums1[s1be]:nums2[s2be];
            }
            int s1mid = k/2<(s1en-s1be)?k/2:(s1en-s1be);
            int s2mid = k-s1mid;
            //cout << "s1mid:" << s1mid << endl;
            //cout << "s2mid:" << s2mid << endl;
            if(nums1[s1mid+s1be-1]<nums2[s2mid+s2be-1])
            {
                return getkth(nums1,s1be+s1mid,s1en,nums2,s2be,s2en,k-s1mid);
            }
            else if(nums1[s1mid+s1be-1]>nums2[s2mid+s2be-1])
            {
                return getkth(nums1,s1be,s1en,nums2,s2be+s2mid,s2en,k-s2mid);
            }
            else
                return nums1[s1mid+s1be-1];
            
        }
};

int main(int argc, char *argv[])
{
    vector<int> a = {};
    vector<int> b = {1,2};
    Solution so;
    cout << so.findMedianSortedArrays(a,b) << endl;
    return 0;
}
