/*********************************************************************************
*     File Name           :     60PermutationSequence.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-29 09:43]
*     Last Modified       :     [2015-07-30 11:25]
*     Description         :     iPermutation Sequence Total Accepted: 34126 Total Submissions: 149399 My Submissions Question Solution 
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
**********************************************************************************/
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            int i=0,curk,j=1,np = 0;
            string res;
            for (i = 1; i <= n; ++i) {
                res.push_back(i+'0');
            }
            len = res.size();
            return interPer(res,k);
            //len = res.size();
            //curk=1;
            //while(curk*(j+1)<k)
            //{
            //    ++j;
            //    curk*=j;
            //}
            //np= len -j;
            //while(curk+curk < k)
            //{
            //    curk +=curk;
            //    ++np;
            //}
            //swap(res[len-j-1],res[np]);
            //sort(res.begin()+len-j,res.end());
            //++curk;
            //cout << "curk:" << curk << " " << res << endl;
            //while(curk < k)
            //{
            //    getnextPer(res);
            //    ++curk;
            //    cout << "curk:" << curk << " " << res << endl;
            //}
            //return res;
        }
        string interPer(string &res,int k)
        {
            if(k == 1)
                return res;
            //if(k==2)
            //{
            //    getnextPer(res);
            //    return res;
            //}
            int curk,j=1,np = 0,curtol;
            curk=1;
            while(curk*(j+1)<k)
            {
                ++j;
                curk*=j;
            }
            np= len -j;
            curtol = curk;
            while(curtol+curk < k)
            {
                curtol +=curk;
                ++np;
            }
            swap(res[len-j-1],res[np]);
            sort(res.begin()+len-j,res.end());
            return interPer(res,k-curtol);
        }
        void getnextPer(string &s)
        {
            int i,j;
            for (i = s.size()-2; i >= 0; --i) {
                if(s[i]<s[i+1])
                    break;
            }
            for(j=len-1;j>=0;--j)
                if(s[j]>s[i])
                    break;
            swap(s[i],s[j]);
            reverse(s.begin()+i+1,s.end());
        }
    private:
        int len;

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.getPermutation(4,19) << endl;
    return 0;
}
